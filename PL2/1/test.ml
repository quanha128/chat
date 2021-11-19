let rec gcd a b =
    if a = 0 then b
    else gcd (b mod a) a;;

let even_vs_odd a b c d e =
    let r = abs(a mod 2) + abs(b mod 2) + abs(c mod 2) + abs(d mod 2) + abs(e mod 2)
    in if r > 2 then false
    else true
;;

let rec pow a n =
    if n = 0 then 1
    else a * (pow a (n-1));;

let rec pow_2 a n =
    if n = 0 then 1
    else if n mod 2 = 0 then pow (a*a) (n/2)
    else a * (pow (a*a) (n/2));;

let isprime a = 
    let rec iter i =
        if i*i > a then true
        else if a mod i = 0 then false
        else iter (i + 1)
    in iter 2
;;

let deriv f =
    let dx = 0.0001
    in let df x =
        (f(x+.dx) -. f(x)) /. dx
    in df
;;

let f x = x ** 2.0;;
let f' = deriv f;;
f' 10.0;;