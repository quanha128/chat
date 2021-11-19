let sum_between x y =
  let rec iter sum i =
    if i = y then sum+i
    else iter (sum+i) (i+1)
  in iter 0 x
;;

sum_between 10 20;;