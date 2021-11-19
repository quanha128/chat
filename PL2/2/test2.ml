let multiply [[a;b];[c;d]] [[x;y];[z;t]] =
    [[a*x + b*z; a*y + b*t]; [c*x + d*z; c*y + d*t]]
;;

let id = [[1;1];[1;0]];;

let rec pow [[a;b];[c;d]] n =
    if n = 0 then id
    else let p = pow [[a;b];[c;d]] (n/2) in
        let p2 = multiply p p in
        if n mod 2 = 0 then p2
        else multiply [[a;b];[c;d]] p2
;;