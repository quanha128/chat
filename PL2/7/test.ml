type counter = {
  incr: unit -> unit;
  get: unit -> int;
  reset: unit -> unit;
}

let create_counter() = 
  let ctr = ref 0 in
  let incr () = ctr := !ctr + 1
  and reset () = ctr := 0
  and get () = !ctr
  in {incr=incr; reset=reset; get=get}
;;

let rec myjoin xs str =
  match xs with
  | hd::tl ->
    begin
      match tl with
      | _::_ -> hd^str^(myjoin tl str)
      | [] -> hd^(myjoin tl str)
    end
  | [] -> ""
;;

let myjoin2 xs str =
  List.fold_left (^) "" (List.map (fun x -> x^str) xs)
;;
myjoin ["aiueo"; "kakikukeko"; "sasisuseso"; "tatituteto"; "naninuneno"] "+";;
myjoin2 ["aiueo"; "kakikukeko"; "sasisuseso"; "tatituteto"; "naninuneno"] "+";;