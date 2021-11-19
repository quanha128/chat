type t = (string, int) Hashtbl.t

let create () = Hashtbl.create 100

let amount t key =
    try
        Hashtbl.find t key
    with
        Not_found -> 0

let deposit t key am =
    let a = amount t key in
    Hashtbl.replace t key (a+am)

let withdraw t key am =
    let a = amount t key in
    Hashtbl.replace t key (a-am)

let transfer t key1 key2 am =
    let u1 = amount t key1 and
    u2 = amount t key2 in
    Hashtbl.replace t key1 (u1-am);
    Hashtbl.replace t key2 (u2+am)

let inipay = create ();;
deposit inipay "alice" 10000;
deposit inipay "bob" 5000;
withdraw inipay "alice" 300;
transfer inipay "alice" "bob" 100;
Printf.printf "Finally, alice has %d and bob has %d yen\n"
  (amount inipay "alice") (amount inipay "bob")