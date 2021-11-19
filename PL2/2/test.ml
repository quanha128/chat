let pow a n =
    let rec iter res n =
        if n <= 1 then res
        else let res' = res * a
    in iter res' (n-1)
    in iter a n;;

let sigma n =
    let rec sigma_iter result n=
        if n <= 0 then result
        else let result' = n+result in
    sigma_iter result' (n-1)
    in sigma_iter 0 n;;

let digit n =
    let rec iter res d =
        if res = 0 then d
        else let res' = res/10
        in iter res' d+1
    in iter n 0
;;

let len xs =
    let rec iter cnt tl =
        match tl with
        hd::tl -> iter (cnt+1) tl
        | [] -> cnt
    in iter 0 xs
;;

let rec digit n =
    if n != 0 then 1 + digit(n/10)
    else 0
;;

let len xs =
    List.fold_left (fun x _ -> x+1) 0 xs
;;

let rec filter f xs =
    match xs with
        hd::tl when f hd = true -> hd::filter f tl
        | hd::tl -> filter f tl
        | [] -> []
;;

let rec fib1 n =
    if n=0 then 0
    else if n=1 then 1
    else fib1(n-1) + fib1(n-2)
;;

let fib2 n =
    let rec iter res res' i=
        if i>=n then res
        else let res'' = res + res' in
            iter res' res'' (i+1)
    in iter 0 1 0
;;

let multiply [[a;b];[c;d]] [[x;y];[z;t]] =
    [[a*x + b*z; a*y + b*t]; [c*x + d*z; c*y + d*t]]
;;

let mul2x1 [[a;b];[c;d]] [x;y] =
    c*x + d*y;;

let id = [[1;0];[0;1]];;

let rec pow [[a;b];[c;d]] n =
    if n = 0 then id
    else let p = pow [[a;b];[c;d]] (n/2) in
        let p2 = multiply p p in
        if n mod 2 = 0 then p2
        else multiply [[a;b];[c;d]] p2
;;

let fib3 n =
    let a = [[1;1];[1;0]] in
    mul2x1 (pow a n) [1;0];;

let pivot xs =
    if List.length xs = 1 then List.hd xs else
    let rec iter piv tl =
        match tl with
            hd::tl -> 
            begin
            let nxt_hd = List.hd tl in
            match hd with
                hd when hd > nxt_hd -> iter hd []
                | _ -> iter nxt_hd []
            end
            | [] -> piv
    in iter (List.hd xs) xs;;

let rec qsort xs =
    if xs = [] then [] else
    let piv = pivot xs in
    let left = qsort (List.filter (fun x -> (x < piv)) xs) in
    let right = qsort (List.filter (fun x -> (x > piv)) xs) in
    left @ [pivot] @ right

let rec combination xs n =
    if n <= 0 then [[]]
    else match xs with
        | [] -> []
        | hd::tl -> 
            let with_hd = List.map (fun l -> hd :: l) (combination tl (n - 1)) in
            let without_hd = combination tl n in
            with_hd @ without_hd
;;