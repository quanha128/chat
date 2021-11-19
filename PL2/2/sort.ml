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
    left @ [piv] @ right
;;

qsort [3;1;4;2;7;9;8;5;6];;