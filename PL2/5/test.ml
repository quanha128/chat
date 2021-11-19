let rec join list =
    match list with
    hd::tl ->
    begin
        match tl with
        | _::_ -> hd^" "^join tl
        | [] -> hd^join tl
    end
    | [] -> ""
;;

(* module MyInt = struct
    type t = int
    let add x y = x + y
    end

module MyString = struct
    let t = string
    let add x y = x ^ y
    end *)

let swap (a: 'a ref) (b: 'a ref) =
    let mid = !a in
    a := !b;
    b := mid
;;

type memo = {mutable content: string}

let s = {content = ""};;

s.content <- read_line();;
print_endline(s.content)

(* let inp = read_line();;
if inp = "" then true else false;; *)