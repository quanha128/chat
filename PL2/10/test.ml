let checkab s =
  let len = (String.length s) - 1 in 
  if s.[0] = 'a' then
    if s.[len] = 'b' then
      let rec iter str i =
        if i = len then true else
        if str.[i] = 'a' then iter str (i+1)
        else false
      in iter s 1
    else false
  else false
;;

let collect3 xs =
  List.filter (fun x -> String.length x = 3) xs
;;

type ibtree = Node of int * ibtree * ibtree | Leaf

type 'a btree = Node of 'a * 'a btree * 'a btree | Leaf

let rec flatten tree =
  match tree with
  | Node(v, t1, t2) -> v::flatten t1 @ flatten t2
  | Leaf -> []
;;

(* flatten (Node(1, Node(2, Leaf, Node(3, Leaf, Leaf)), Node(4, Leaf, Leaf)));;
flatten (Node(1, Node(3, Node(2, Leaf, Leaf), Leaf), Leaf)) *)

let remove xs i =
  List.filter (fun x-> x != i) xs
;;

let remove xs i =
  let rec iter res xs' n =
    match xs' with
    | h::t ->
      if n = i then iter res t (n+1)
      else iter (res@[h]) t (n+1)
    | [] -> res
  in iter [] xs 0
;;

(* remove [1;2;3;4;5;6] 0;; *)

let apply f n =
  let rec iter f' i =
    if i = n then
      f'
    else
      iter (fun x -> f (f' x)) (i+1)
  in iter f 1
;;

let mysqrt a =
  let f = (fun x -> x*.x -. a) in
  let df = (fun x-> 2.0*.x) in
  let newton = apply (fun x -> x -. (f x)/. (df x)) 20 in
  newton a
;;

mysqrt 3.0;;