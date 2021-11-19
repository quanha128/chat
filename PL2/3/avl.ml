type 'a tree =
    Node of 'a * 'a tree * 'a tree
    | Leaf;;

exception BadBalanceFactor
exception Impossible

let rec height t =
    match t with
    | Node(_,t1,t2) -> 1 + max (height t1) (height t2)
    | Leaf -> 0

let rec check_balance t =
    match t with
    | Node(_,t1,t2) ->
        let diff = abs ((height t1) - (height t2)) in
        (diff < 2) && (check_balance t1) && (check_balance t2)
    | Leaf -> true
;;

let check_balance_factor t =
    match t with
    | Node(_,t1,t2) -> 
        let diff = (height t2) - (height t1) in
        print_int(diff);
        print_newline();
        diff
    | Leaf -> 0
;;

let left_rotation t =
    match t with
    | Node(v1,l,r) ->
    begin
        match r with
        | Node(v2,rl,rr) -> Node(v2,Node(v1,l,rl),rr)
        | Leaf -> r
    end
    | Leaf -> Leaf
;;

let right_rotation t =
    match t with
    | Node(v1,l,r) ->
    begin
        match l with
        | Node(v2,ll,lr) -> Node(v2,ll,Node(v1,lr,r))
        | Leaf -> l
    end
    | Leaf -> Leaf
;;

let lf_rt_rotation t = 
    match t with
    | Node(v1,l,r) ->
        let rot1 = left_rotation l in
        right_rotation (Node(v1,rot1,r))
    | Leaf -> Leaf
;;

let rt_lf_rotation t = 
    match t with
    | Node(v1,l,r) ->
        let rot1 = right_rotation r in
        left_rotation (Node(v1,l,rot1))
    | Leaf -> Leaf
;;

let rec retrace t =
    match t with
    | Node(v,t1,t2) ->
    begin
        match check_balance_factor t with
            | 2 ->
                if check_balance_factor t2 = 1 then left_rotation t
                else rt_lf_rotation t
            | -2 ->
                if check_balance_factor t1 = -1 then right_rotation t
                else lf_rt_rotation t
            | 0 -> t
            | 1 -> Node(v,t1,retrace t2)
            | -1 -> Node(v,retrace t1,t2)
            | _ -> raise BadBalanceFactor
    end
    | Leaf -> t
;;

let rec append_bst node t =
    match t with
        | Node(v,t1,t2) when node<v -> Node(v,append_bst node t1,t2)
        | Node(v,t1,t2) when node>v -> Node(v,t1,append_bst node t2)
        | Node(v,t1,t2) when node=v -> t
        | Leaf -> Node(node,Leaf,Leaf)
        | _ -> raise Impossible
;;

let rec append_avl node t =
    retrace (append_bst node t)
;;