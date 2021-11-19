type 'a stack = {mutable s: 'a list}

exception EmptyStack

let new_stack () =
    {s = []}

let push s e =
    s.s <- [e] @ s.s

let pop s =
    match s.s with
    | hd::tl -> 
        s.s <- tl;
        hd
    | [] -> raise EmptyStack

let s = new_stack ();;
push s 1;;
push s 2;;
pop s;;
pop s;;
pop s;;