let pyramid num =
  let rec iter n_space n_star =
    let rec make_space space n =
      if n > 0 then make_space (space ^ " ") (n-1)
      else space
    and make_star star n =
      if n > 0 then make_star (star ^ "*") (n-1)
      else star in
    if n_space >= 0 then
    let space = make_space "" n_space and star = make_star "" n_star in
      print_string (space);
      print_endline (star);
      iter (n_space-1) (n_star+2)
    else
      print_endline ""
  in iter (num-1) 1
;;

pyramid 100;;

let sq xs = 
  List.map (fun x -> x**2.0) xs;;

sq [1.0; 2.0; 3.0]

type figure =
Circle of float (*radius*)
| Rectangle of float * float (* width and height *)

let area fig =
  match fig with
  | Circle(r) -> 3.14 *. r
  | Rectangle(w, h) -> w*.h

let a = ref ""
let grass () =
  a := !a ^ "w";
  !a

type expr = 
    Add of expr * expr  (* addition *)
  | Mul of expr * expr  (* multiplication *)
  | Val of float        (* constant *)
  | Var of string       (* variable *)

let rec fold_const exp =
  match exp with
  | Add(e1,e2) ->
    begin
      match fold_const(e1), fold_const(e2) with
      | Val(v1), Val(v2) -> Val(v1 +. v2)
      | c1, c2 -> Add(fold_const(c1), fold_const(c2))
    end
  | Mul(e1,e2) ->
    begin
      match fold_const(e1), fold_const(e2) with
      | Val(v1), Val(v2) -> Val(v1 *. v2)
      | c1, c2 -> Mul(fold_const (c1), fold_const(c2))
    end
  | Val(v) -> Val(v)
  | Var(x) -> Var(x)

let rec range m n =
  let rec iter i =
    if i < n then i :: iter (i+1)
    else []
  in iter m
;;

range 5 10;;