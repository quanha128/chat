(* Lazy evaluation *)

type 'a delayed_stat =
  | Before of (unit -> 'a)
  | After of 'a

type 'a delayed = 'a delayed_stat ref
      
let delay f = ref (Before(f))
      
let force l =
  match !l with
  | Before(a) -> let v = a() in l:=After(v); v
  | After(a) -> a