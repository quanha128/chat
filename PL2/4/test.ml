let call = ref 0

let count () =
    call := !call + 1;
    !call
;;

type 'a tree = Node of 'a * 'a tree * 'a tree |Leaf

let rec find t cond =
    match t with
    | Node(v,t1,t2) ->
        if (cond v) = true then true
        else find t1 cond || find t2 cond
    | Leaf -> false

let t = 
    Node(1, 
        Node(2,
            Node(4, Leaf,
                Node(5, Leaf, Leaf)),
            Leaf),
        Node(7, Node(6, Leaf, Leaf),
            Node(8, Leaf,
                Node(9, Leaf, Leaf))));;

let rec print_lines xs =
    match xs with
    | hd::tl ->
        print_endline(hd);
        print_lines(tl)
    | [] -> print_string("")
;;


let generate_counter () =
    let cnt = ref 6
    and arr = [|"mon";"tue";"wed";"thu";"fri";"sat";"sun"|] in
        fun () -> cnt := !cnt +1;
        arr.((!cnt) mod 7)
;;

type turtle = {
    mutable x : float;
    mutable y: float;
    mutable theta: float
}

let new_turtle () =
    {x=0.;y=0.;theta=0.}

let forward ttl dis =
    ttl.x <- ttl.x +. cos ttl.theta *. dis;
    ttl.y <- ttl.x +. sin ttl.theta *. dis

let left ttl deg =
    ttl.theta <- ttl.theta +. deg

type lat_lng = float*float
type lat_lng_op =  Values of lat_lng | Null

let north_of_iniad ll =
    match ll with
    | Values(lt_lg) ->
        begin
            match lt_lg with
            | (lat,_) when lat < 35.780246 -> Some(true)
            | _ -> Some(false)
        end
    | Null -> None

let akabane_station = Values(35.777615, 139.7209868);;
north_of_iniad akabane_station;;
north_of_iniad Null;;