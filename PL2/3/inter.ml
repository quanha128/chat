type expression =
    | Binop of char * expression * expression
    | Tern of bool * expression * expression
    | Number of int;;

let rec eval exp =
    match exp with
    | Binop(op,e1,e2) -> 
        if op = '+' then (eval e1) + (eval e2)
        else if op = '-' then (eval e1) - (eval e2)
        else if op = '*' then (eval e1) * (eval e2)
        else (eval e1) / (eval e2)
    | Tern(cond,e1,e2) ->
        if cond = true then eval e1 else eval e2
    | Number(i) -> i
;;

eval (Binop('+', Number(1), Tern(1>2, Number(2), Number(3))));;

type instruction =
    | Add | Sub | Mul | Div
    | Push of int;;

type 'a tree =
    Node of 'a * 'a tree * 'a tree
    | Leaf;;

let rec dfs t =
    match t with
    | Leaf -> []
    | Node(v,t1,t2) -> dfs t1 @ dfs t2 @ [v]
;;

let t = 
    Node(1, 
        Node(2,
            Node(4, Leaf,
                Node(5, Leaf, Leaf)),
            Leaf),
        Node(7, Node(6, Leaf, Leaf),
            Node(8, Leaf,
                Node(9, Leaf, Leaf))));;

let tree =
  Node (1,
        Node (2,
              Node (4,
                    Node (7, Leaf, Leaf),
                    Leaf),
              Node (5, Leaf, Leaf)),
        Node (3,
              Node (6,
                    Node (8, Leaf, Leaf),
                    Node (9, Leaf, Leaf)),
              Leaf));;

dfs tree;;
type expression =
    | Binop of char * expression * expression
    | Number of int;;

let rec compile exp =
    match exp with
    | Binop(op,e1,e2) ->
        if op = '+' then compile e1@compile e2@[Add]
        else if op = '-' then compile e1@compile e2@[Sub]
        else if op = '*' then compile e1@compile e2@[Mul]
        else compile e1@compile e2@[Div]
    | Number(i) -> [Push(i)]
;;
compile (Binop('+', Number(1), Binop('*', Number(2), Number(3))));;

(* let rec max_bst t =
    match t with
    | Node(_,_,t2) ->
    begin
        match t with
        Node(_,Leaf, Node(v,_,_)) -> Some(v)
        | _ -> max_bst t2
    end
    | Leaf -> None
;; *)


let rec max_bst t =
    match t with
    | Node(v,_,t2) ->
    begin
        match t2 with
        Leaf -> v
        | _ -> max_bst t2
    end
;;

max_bst (Node(8, Node(3, Node(1, Leaf, Leaf), Leaf), Node(10, Leaf, Leaf)));;

let rec remove_bst node t =
    match t with
    | Node(v,t1,t2) when node<v -> Node(v,remove_bst node t1, t2)
    | Node(v,t1,t2) when node>v -> Node(v,t1,remove_bst node t2)
    | Node(v,t1,t2) when node=v ->
        begin
            match (t1,t2) with
            | (Leaf,Leaf) -> Leaf
            | (Leaf,Node(v',t1',t2')) -> Node(v',t1',t2')
            | (Node(v',t1',t2'),Leaf) -> Node(v',t1',t2')
            | (Node(_,_,_),Node(_,_,_)) ->
                let node' = max_bst t1 in
                Node(node', remove_bst node' t1, t2)
        end
    | Leaf -> t
;;

remove_bst 8 (Node(8, Node(3, Node(1, Leaf, Leaf), Leaf), Node(10, Leaf, Leaf)));;