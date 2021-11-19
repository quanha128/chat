let sum xs =
    let rec iter res tl=
        match tl with
            hd::tl -> iter (res+hd) tl
            | [] -> res
    in iter 0 xs;;