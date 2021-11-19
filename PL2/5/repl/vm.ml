type expression =
    | Binop of char * expression * expression
    | Number of int;;

type instructions =
    Add | Sub | Mul | Div
    | Push of int;;

let parse expr =
  let expr = 
    let r = ref "" in
    String.iter (fun c -> if c <> ' ' then r := !r ^ (String.make 1 c) else ()) expr;
    !r
  in let len = String.length expr in
  let rec parse_addsub pos =
    let rec iter (pos, e) =
      if pos >= len then pos, e
      else match expr.[pos] with
          '+' | '-' as op ->
          let pos, e2 = parse_muldiv (pos+1) in iter (pos, Binop(op, e, e2))
        | _ -> (pos, e)
    in iter (parse_muldiv pos)
  and parse_muldiv pos =
    let rec iter (pos, e) =
      if pos >= len then pos, e
      else match expr.[pos] with
          '*' | '/' as op ->
          let pos, e2 = parse_simple (pos+1) in iter (pos, Binop(op, e, e2))
        | _ -> (pos, e)
    in iter (parse_simple pos)
  and parse_simple pos =
    if pos >= len then failwith "Parse error"
    else match expr.[pos] with
        '(' ->
        let pos, head = parse_addsub (pos+1) in
        if pos >= len || expr.[pos] <> ')' then failwith "Parse error"
        else (pos+1), head
      | c when c >= '0' && c <= '9' ->
        let char_of_int c = Char.code c - Char.code '0' in
        let rec iter (pos, v) =
          if pos >= len || expr.[pos] < '0' || expr.[pos] > '9' then (pos, v)
          else iter (pos+1, v * 10 + char_of_int expr.[pos])
        in let (pos, v) = iter (pos+1, char_of_int c)
        in pos, Number(v)
      | _ -> failwith "Parse error"
  in let pos, head = parse_addsub 0 in
  if pos < len then failwith "Parse error"
  else head
;;

let rec compile exp =
    match exp with
    | Binop(op,e1,e2) ->
        if op = '+' then compile e1@compile e2@[Add]
        else if op = '-' then compile e1@compile e2@[Sub]
        else if op = '*' then compile e1@compile e2@[Mul]
        else compile e1@compile e2@[Div]
    | Number(i) -> [Push(i)]
;;

let rec parse_list stack list =
    match list with
    | hd::tl ->
        MyStack.push hd stack;
        parse_list stack tl
    | [] -> stack
;;

let rec parse_stack stack =
    match MyStack.pop stack with
    | Add -> (parse_stack stack) + (parse_stack stack)
    | Sub -> (parse_stack stack) - (parse_stack stack)
    | Mul -> (parse_stack stack) * (parse_stack stack)
    | Div -> (parse_stack stack) / (parse_stack stack)
    | Push(i) -> i

let rec iter () =
    let s = MyStack.create () in
    print_string(">>> ");
    try
        let inp = read_line() in
        if inp = "" then iter () else
        let inst = compile (parse(inp)) in
        let result = parse_stack (parse_list s inst) in
        print_int(result);
        print_newline();
        iter ();
    with
        | Division_by_zero ->
            print_endline("ERROR: division by zero");
            iter ()
        | Failure(s) when s = "Parse error"->
            print_endline("ERROR: syntax error");
            iter ();
;;

let _ = iter ();;