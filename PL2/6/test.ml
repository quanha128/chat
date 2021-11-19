type expr =
    | X
    | One
    | Add of expr * expr

type statement =
    | Print of expr
    | Var of expr

type program = statement list


let rec eval expr i =
    match expr with
    | Add(e1,e2) -> (eval e1 i) + (eval e2 i)
    | One -> 1
    | X -> i;;

let x = ref 0

let eval_statement stmt =
    match stmt with
    | Print(expr) -> print_int(eval (expr) !x); print_newline()
    | Var(expr) -> x := eval expr !x

let rec eval_prog stmt_lst =
    match stmt_lst with
    | hd::tl ->
        eval_statement(hd);
        eval_prog(tl)
    | [] -> print_endline("done")

let prog = [Var(Add(One,One)); Print(Add(X,One))];;
eval_prog(prog);;

module Iniad:
    sig
        val is : unit -> unit
    end =
    struct
    let is () =
        print_endline("Information Networking for Innovation and Design")
    end