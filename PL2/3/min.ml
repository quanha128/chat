type 'a btree = Node of 'a * 'a btree * 'a btree | Leaf;;
let t = 
    Node(1, 
        Node(2,
            Node(4, Leaf,
                Node(5, Leaf, Leaf)),
            Leaf),
        Node(7, Node(6, Leaf, Leaf),
            Node(8, Leaf,
                Node(9, Leaf, Leaf))));;


let rec min_bst t =
    match t with
    | Node(_,t1,_) ->
    begin
        match t with
        Node(_,Node(v,_,_), Leaf) -> Some(v)
        | _ -> min_bst t1
    end
    | Leaf -> None
;;

exception Impossible

let rec append_bst node t =
    match t with
    | Node(v,t1,t2) when node<v -> Node(v,append_bst node t1,t2)
    | Node(v,t1,t2) when node>v -> Node(v,t1,append_bst node t2)
    | Node(v,t1,t2) when node=v -> t
    | Leaf -> Node(node,Leaf,Leaf)
    | _ -> raise Impossible
;;