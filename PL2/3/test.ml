type 'a btree = Node of 'a * 'a btree * 'a btree | Leaf;;

let rec height (t: 'a btree) =
    match t with
    | Leaf -> 0
    | Node(_,t1,t2) -> 1 + max (height t1) (height t2);;

let t = 
    Node(1, 
        Node(2,
            Node(4, Leaf,
                Node(5, Leaf, Leaf)),
            Leaf),
        Node(7, Node(6, Leaf, Leaf),
            Node(8, Leaf,
                Node(9, Leaf, Leaf))));;

(* let bfs (t: 'a btree) =
    let rec bfs_iter res nodes =
        if nodes = [] then res else
        
    in bfs_iter 

(* let delete v xs =
    (* if xs = [] then [] else *)
    (* if List.hd xs = v then List.tl xs else *)
    (* let rec iter prv xs' =
        match xs' with
        | hd::tl -> if hd = v then prv::tl else iter hd tl
        | [] -> []
    in iter (List.hd xs) xs;; *)
    List.filter (fun x -> x<>v) xs;;

delete 2 [2;2;3;1;4;1];; *)*)

let rec find value t =
    match t with
    | Node(v,t1,t2) ->
        if v = value then true
        else if v<value then find value t1
        else find value t2
    | Leaf -> false


let rec count_bst t =
    match t with
    | Node(v,t1,t2) -> 1 + (count_bst t1) + (count_bst t2)
    | Leaf -> 0;;

count_bst (Node(8, Node(3, Node(1, Leaf, Leaf), Leaf), Node(10, Leaf, Leaf)));;
count_bst Leaf;;