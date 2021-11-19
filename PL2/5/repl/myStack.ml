type 'a t = {mutable s: 'a list}

let create () =
    {s = []}

let push elm stack =
    stack.s <- [elm] @ stack.s

let pop stack =
    match stack.s with
    | hd::tl -> 
        stack.s <- tl;
        hd
    | [] -> raise Not_found