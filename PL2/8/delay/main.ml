open Delayed

let if2 cond tcls fcls =
  if cond
  then force tcls
  else force fcls

let rec fact n =
  if2 (n <= 0)
    (delay (fun () -> 1))
    (delay (fun () -> n * fact (n-1)))

let main () =
  Printf.printf "fact(10) = %d\n" (fact 10)

let _ = main()

  
