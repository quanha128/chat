let sum a b =
  let rec iter result a =
    if a = b then result else
    iter (result+a) (a+1)
  in iter 0 a
;;

let rec sum2 n m =
  if n = m-1 then n else
  n + (sum2 (n+1) m)
;;

let sigma lst =
  let rec iter res tl =
   match tl with
   | h::t -> iter (h+res) t
   | [] -> res
  in iter 0 lst
;;

let rec sigma2 lst =
  match lst with
  | hd::tl -> hd + sigma2 tl
  | [] -> 0
;;

let sigma3 lst =
  List.fold_left (+) 0 lst;;

type expression =
  Binop of char * expression * expression
  | Number of int
;;

let rec remove_minus exp =
  match exp with
  | Binop(op,e1,e2) ->
      begin
        if op = '-' then
        match e1, e2 with
        | (_, Number(i)) -> Binop('+',remove_minus e1, Number(-i))
        | (Number(i), _) -> Binop('+',Number(-i), remove_minus e2)
        | (_, Binop(_,_,_)) -> Binop(op, remove_minus e1, remove_minus e2)
        else Binop(op, remove_minus e1, remove_minus e2)
      end
  | Number(i) -> Number(i)
;;

remove_minus (Binop('-', Number(5), Binop('-', Number(4), Number(6))));;

let deriv f =
  let delta = 0.00001 in
  fun x -> (f(x+. delta) -. (f x)) /. delta