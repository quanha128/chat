(* Lazy evaluation *)

type 'a delayed_stat

type 'a delayed

val delay : (unit -> 'a) -> 'a delayed
val force : 'a delayed -> 'a
