type expr =
| Add of expr * expr
| Mul of expr * expr
| StrVal of string
| IntVal of int
| Var of string

type typ = IntType | StrType

let env = [("a", IntType); ("b", StrType)]

type statement =
Assign of expr
| Return of expr

(* type funbody =
Statement of statement * env *)

let slice xs n =
  let rec iter i xs' = 
    match xs' with
    | h::t ->
      if i > 0 then
        h :: (iter (i-1) t)
      else []
    | [] -> []
  in iter n xs
;;
(* slice [1;2;3;4;5] 4;; *)

let myfunc abs = abs;;

let myfunc2 func x = func (x);

myfunc 1;;
myfunc2 (fun x->x^"lamo");;


let add i f = float_of_int i +. f

let limit xs n =
  let rec iter xs' i =
    if i < n then
      match xs' with
      | h::t -> h :: (iter t (i+1))
      | [] -> []
    else []
  in iter xs 0
;;

limit [1;2;3;4;5] 3;;
limit ["Information"; "Networking"; "for"; "Innovation"; "and"; "Design"] 4;;

let rec remove_zero1 numbers = 
  match numbers with
    0::tl -> remove_zero1 tl
  | hd::tl -> hd::(remove_zero1 tl)
  | [] -> []

let remove_zero numbers = 
  let rec iter num res =
    match num with
      0::tl -> iter tl res
    | hd::tl -> iter tl (res@[hd])
    | [] -> res
  in iter numbers [];;

remove_zero [0;1;2;3;4;0;1;0;2;3];;

type 'a btree = 
    Node of 'a * 'a btree * 'a btree
  | Leaf

let rec contains t e =
  match t with
  | Node(v, t1, t2) ->
    if v = e then true
    else (contains t1 e) || (contains t2 e)
  | Leaf -> false

let tree = Node(1, Node(3, Leaf, Node(6, Leaf, Leaf)), Node(4, Leaf, Node(2, Leaf, Leaf)));;

contains tree 5;;
contains tree 6;;

exception Type_mismatch

type value =
    String of string    (* string value *)
  | Int of int          (* integer value *)

type expr = 
    Add of expr * expr  (* a + b *)
  | Sub of expr * expr  (* a - b *)
  | Const of value      (* constant value *)

let rec eval exp =
  match exp with
  | Add(e1, e2) ->
    begin
      match eval e1, eval e2 with
      | Int(v1), Int(v2) -> Int(v1 + v2)
      | String(s1), String(s2) -> String(s1 ^ s2)
      | _ -> raise Type_mismatch
    end
  | Sub(e1, e2) ->
    begin
      match eval e1, eval e2 with
      | Int(v1), Int(v2) -> Int(v1 - v2)
      | _ -> raise Type_mismatch
    end
  | Const(v) -> v;;

eval (Add(Const(Int(1)), Const(Int(2))));;
eval (Add(Const(String("ini")), Const(String("ad"))));;
eval (Sub(Const(String("ini")), Const(String("ad"))));;