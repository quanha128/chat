
module MenhirBasics = struct
  
  exception Error
  
  type token = 
    | WHILE
    | STRING of (
# 7 "parser.mly"
       (string)
# 12 "parser.ml"
  )
    | RPAREN
    | PRINT
    | PLUS
    | NOTEQUAL
    | NEWLINE
    | MUL
    | MINUS
    | LPAREN
    | INT of (
# 8 "parser.mly"
       (int)
# 25 "parser.ml"
  )
    | INDENT
    | IF
    | IDENT of (
# 6 "parser.mly"
       (string)
# 32 "parser.ml"
  )
    | EQUAL
    | EOF
    | ELSE
    | DIV
    | DEDENT
    | COLON
    | ASSIGN
  
end

include MenhirBasics

let _eRR =
  MenhirBasics.Error

type _menhir_env = {
  _menhir_lexer: Lexing.lexbuf -> token;
  _menhir_lexbuf: Lexing.lexbuf;
  _menhir_token: token;
  mutable _menhir_error: bool
}

and _menhir_state = 
  | MenhirState53
  | MenhirState47
  | MenhirState46
  | MenhirState39
  | MenhirState38
  | MenhirState36
  | MenhirState33
  | MenhirState32
  | MenhirState31
  | MenhirState27
  | MenhirState26
  | MenhirState25
  | MenhirState23
  | MenhirState20
  | MenhirState19
  | MenhirState18
  | MenhirState17
  | MenhirState16
  | MenhirState15
  | MenhirState14
  | MenhirState12
  | MenhirState10
  | MenhirState9
  | MenhirState8
  | MenhirState6
  | MenhirState3
  | MenhirState1
  | MenhirState0

# 1 "parser.mly"
  
open Syntax

# 90 "parser.ml"

let rec _menhir_goto_newline : _menhir_env -> 'ttv_tail -> _menhir_state -> 'tv_newline -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s _v ->
    match _menhir_s with
    | MenhirState27 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ((('freshtv219 * _menhir_state)) * _menhir_state * 'tv_expr) * _menhir_state) = Obj.magic _menhir_stack in
        let (_menhir_s : _menhir_state) = _menhir_s in
        let (_v : 'tv_newline) = _v in
        ((let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ((('freshtv217 * _menhir_state)) * _menhir_state * 'tv_expr) * _menhir_state) = Obj.magic _menhir_stack in
        let (_ : _menhir_state) = _menhir_s in
        let (_ : 'tv_newline) = _v in
        ((let (((_menhir_stack, _menhir_s), _, (_3 : 'tv_expr)), _) = _menhir_stack in
        let _v : 'tv_stmt = 
# 38 "parser.mly"
        ( PrintStmt(_3) )
# 108 "parser.ml"
         in
        _menhir_goto_stmt _menhir_env _menhir_stack _menhir_s _v) : 'freshtv218)) : 'freshtv220)
    | MenhirState39 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (('freshtv223 * _menhir_state * (
# 6 "parser.mly"
       (string)
# 116 "parser.ml"
        ))) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        let (_menhir_s : _menhir_state) = _menhir_s in
        let (_v : 'tv_newline) = _v in
        ((let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (('freshtv221 * _menhir_state * (
# 6 "parser.mly"
       (string)
# 124 "parser.ml"
        ))) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        let (_ : _menhir_state) = _menhir_s in
        let (_ : 'tv_newline) = _v in
        ((let ((_menhir_stack, _menhir_s, (_1 : (
# 6 "parser.mly"
       (string)
# 131 "parser.ml"
        ))), _, (_3 : 'tv_expr)) = _menhir_stack in
        let _v : 'tv_stmt = 
# 32 "parser.mly"
                                ( AssignStmt(_1, _3) )
# 136 "parser.ml"
         in
        _menhir_goto_stmt _menhir_env _menhir_stack _menhir_s _v) : 'freshtv222)) : 'freshtv224)
    | _ ->
        _menhir_fail ()

and _menhir_goto_list_stmt_ : _menhir_env -> 'ttv_tail -> _menhir_state -> 'tv_list_stmt_ -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s _v ->
    let _menhir_stack = (_menhir_stack, _menhir_s, _v) in
    match _menhir_s with
    | MenhirState47 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ('freshtv201 * _menhir_state * 'tv_stmt) * _menhir_state * 'tv_list_stmt_) = Obj.magic _menhir_stack in
        ((let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ('freshtv199 * _menhir_state * 'tv_stmt) * _menhir_state * 'tv_list_stmt_) = Obj.magic _menhir_stack in
        ((let ((_menhir_stack, _menhir_s, (x : 'tv_stmt)), _, (xs : 'tv_list_stmt_)) = _menhir_stack in
        let _v : 'tv_list_stmt_ = 
# 213 "<standard.mly>"
    ( x :: xs )
# 155 "parser.ml"
         in
        _menhir_goto_list_stmt_ _menhir_env _menhir_stack _menhir_s _v) : 'freshtv200)) : 'freshtv202)
    | MenhirState46 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (((('freshtv215)))) * _menhir_state * 'tv_list_stmt_) = Obj.magic _menhir_stack in
        ((assert (not _menhir_env._menhir_error);
        let _tok = _menhir_env._menhir_token in
        match _tok with
        | DEDENT ->
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : (((('freshtv211)))) * _menhir_state * 'tv_list_stmt_) = Obj.magic _menhir_stack in
            ((let _menhir_env = _menhir_discard _menhir_env in
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : (((('freshtv209)))) * _menhir_state * 'tv_list_stmt_) = Obj.magic _menhir_stack in
            ((let (_menhir_stack, _, (_5 : 'tv_list_stmt_)) = _menhir_stack in
            let _v : 'tv_else_term = 
# 40 "parser.mly"
                                                       ( _5 )
# 174 "parser.ml"
             in
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : 'freshtv207) = _menhir_stack in
            let (_v : 'tv_else_term) = _v in
            ((let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : 'freshtv205) = Obj.magic _menhir_stack in
            let (_v : 'tv_else_term) = _v in
            ((let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : 'freshtv203) = Obj.magic _menhir_stack in
            let ((x : 'tv_else_term) : 'tv_else_term) = _v in
            ((let _v : 'tv_loption_else_term_ = 
# 144 "<standard.mly>"
    ( x )
# 188 "parser.ml"
             in
            _menhir_goto_loption_else_term_ _menhir_env _menhir_stack _v) : 'freshtv204)) : 'freshtv206)) : 'freshtv208)) : 'freshtv210)) : 'freshtv212)
        | _ ->
            assert (not _menhir_env._menhir_error);
            _menhir_env._menhir_error <- true;
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : (((('freshtv213)))) * _menhir_state * 'tv_list_stmt_) = Obj.magic _menhir_stack in
            ((let (_menhir_stack, _menhir_s, _) = _menhir_stack in
            _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv214)) : 'freshtv216)
    | _ ->
        _menhir_fail ()

and _menhir_run28 : _menhir_env -> 'ttv_tail -> _menhir_state -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s ->
    let _menhir_env = _menhir_discard _menhir_env in
    let (_menhir_env : _menhir_env) = _menhir_env in
    let (_menhir_stack : 'freshtv197) = Obj.magic _menhir_stack in
    let (_menhir_s : _menhir_state) = _menhir_s in
    ((let _v : 'tv_newline = 
# 63 "parser.mly"
                       ()
# 210 "parser.ml"
     in
    _menhir_goto_newline _menhir_env _menhir_stack _menhir_s _v) : 'freshtv198)

and _menhir_run29 : _menhir_env -> 'ttv_tail -> _menhir_state -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s ->
    let _menhir_env = _menhir_discard _menhir_env in
    let (_menhir_env : _menhir_env) = _menhir_env in
    let (_menhir_stack : 'freshtv195) = Obj.magic _menhir_stack in
    let (_menhir_s : _menhir_state) = _menhir_s in
    ((let _v : 'tv_newline = 
# 63 "parser.mly"
                       ()
# 223 "parser.ml"
     in
    _menhir_goto_newline _menhir_env _menhir_stack _menhir_s _v) : 'freshtv196)

and _menhir_run8 : _menhir_env -> 'ttv_tail * _menhir_state * 'tv_expr -> _menhir_state -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s ->
    let _menhir_stack = (_menhir_stack, _menhir_s) in
    let _menhir_env = _menhir_discard _menhir_env in
    let _tok = _menhir_env._menhir_token in
    match _tok with
    | IDENT _v ->
        _menhir_run5 _menhir_env (Obj.magic _menhir_stack) MenhirState8 _v
    | INT _v ->
        _menhir_run4 _menhir_env (Obj.magic _menhir_stack) MenhirState8 _v
    | LPAREN ->
        _menhir_run3 _menhir_env (Obj.magic _menhir_stack) MenhirState8
    | STRING _v ->
        _menhir_run2 _menhir_env (Obj.magic _menhir_stack) MenhirState8 _v
    | _ ->
        assert (not _menhir_env._menhir_error);
        _menhir_env._menhir_error <- true;
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState8

and _menhir_run14 : _menhir_env -> 'ttv_tail * _menhir_state * 'tv_expr -> _menhir_state -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s ->
    let _menhir_stack = (_menhir_stack, _menhir_s) in
    let _menhir_env = _menhir_discard _menhir_env in
    let _tok = _menhir_env._menhir_token in
    match _tok with
    | IDENT _v ->
        _menhir_run5 _menhir_env (Obj.magic _menhir_stack) MenhirState14 _v
    | INT _v ->
        _menhir_run4 _menhir_env (Obj.magic _menhir_stack) MenhirState14 _v
    | LPAREN ->
        _menhir_run3 _menhir_env (Obj.magic _menhir_stack) MenhirState14
    | STRING _v ->
        _menhir_run2 _menhir_env (Obj.magic _menhir_stack) MenhirState14 _v
    | _ ->
        assert (not _menhir_env._menhir_error);
        _menhir_env._menhir_error <- true;
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState14

and _menhir_run10 : _menhir_env -> 'ttv_tail * _menhir_state * 'tv_expr -> _menhir_state -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s ->
    let _menhir_stack = (_menhir_stack, _menhir_s) in
    let _menhir_env = _menhir_discard _menhir_env in
    let _tok = _menhir_env._menhir_token in
    match _tok with
    | IDENT _v ->
        _menhir_run5 _menhir_env (Obj.magic _menhir_stack) MenhirState10 _v
    | INT _v ->
        _menhir_run4 _menhir_env (Obj.magic _menhir_stack) MenhirState10 _v
    | LPAREN ->
        _menhir_run3 _menhir_env (Obj.magic _menhir_stack) MenhirState10
    | STRING _v ->
        _menhir_run2 _menhir_env (Obj.magic _menhir_stack) MenhirState10 _v
    | _ ->
        assert (not _menhir_env._menhir_error);
        _menhir_env._menhir_error <- true;
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState10

and _menhir_run16 : _menhir_env -> 'ttv_tail * _menhir_state * 'tv_expr -> _menhir_state -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s ->
    let _menhir_stack = (_menhir_stack, _menhir_s) in
    let _menhir_env = _menhir_discard _menhir_env in
    let _tok = _menhir_env._menhir_token in
    match _tok with
    | IDENT _v ->
        _menhir_run5 _menhir_env (Obj.magic _menhir_stack) MenhirState16 _v
    | INT _v ->
        _menhir_run4 _menhir_env (Obj.magic _menhir_stack) MenhirState16 _v
    | LPAREN ->
        _menhir_run3 _menhir_env (Obj.magic _menhir_stack) MenhirState16
    | STRING _v ->
        _menhir_run2 _menhir_env (Obj.magic _menhir_stack) MenhirState16 _v
    | _ ->
        assert (not _menhir_env._menhir_error);
        _menhir_env._menhir_error <- true;
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState16

and _menhir_run18 : _menhir_env -> 'ttv_tail * _menhir_state * 'tv_expr -> _menhir_state -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s ->
    let _menhir_stack = (_menhir_stack, _menhir_s) in
    let _menhir_env = _menhir_discard _menhir_env in
    let _tok = _menhir_env._menhir_token in
    match _tok with
    | IDENT _v ->
        _menhir_run5 _menhir_env (Obj.magic _menhir_stack) MenhirState18 _v
    | INT _v ->
        _menhir_run4 _menhir_env (Obj.magic _menhir_stack) MenhirState18 _v
    | LPAREN ->
        _menhir_run3 _menhir_env (Obj.magic _menhir_stack) MenhirState18
    | STRING _v ->
        _menhir_run2 _menhir_env (Obj.magic _menhir_stack) MenhirState18 _v
    | _ ->
        assert (not _menhir_env._menhir_error);
        _menhir_env._menhir_error <- true;
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState18

and _menhir_run12 : _menhir_env -> 'ttv_tail * _menhir_state * 'tv_expr -> _menhir_state -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s ->
    let _menhir_stack = (_menhir_stack, _menhir_s) in
    let _menhir_env = _menhir_discard _menhir_env in
    let _tok = _menhir_env._menhir_token in
    match _tok with
    | IDENT _v ->
        _menhir_run5 _menhir_env (Obj.magic _menhir_stack) MenhirState12 _v
    | INT _v ->
        _menhir_run4 _menhir_env (Obj.magic _menhir_stack) MenhirState12 _v
    | LPAREN ->
        _menhir_run3 _menhir_env (Obj.magic _menhir_stack) MenhirState12
    | STRING _v ->
        _menhir_run2 _menhir_env (Obj.magic _menhir_stack) MenhirState12 _v
    | _ ->
        assert (not _menhir_env._menhir_error);
        _menhir_env._menhir_error <- true;
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState12

and _menhir_fail : unit -> 'a =
  fun () ->
    Printf.fprintf stderr "Internal failure -- please contact the parser generator's developers.\n%!";
    assert false

and _menhir_goto_stmt : _menhir_env -> 'ttv_tail -> _menhir_state -> 'tv_stmt -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s _v ->
    let _menhir_stack = (_menhir_stack, _menhir_s, _v) in
    match _menhir_s with
    | MenhirState47 | MenhirState46 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : 'freshtv191 * _menhir_state * 'tv_stmt) = Obj.magic _menhir_stack in
        ((assert (not _menhir_env._menhir_error);
        let _tok = _menhir_env._menhir_token in
        match _tok with
        | IDENT _v ->
            _menhir_run37 _menhir_env (Obj.magic _menhir_stack) MenhirState47 _v
        | IF ->
            _menhir_run32 _menhir_env (Obj.magic _menhir_stack) MenhirState47
        | PRINT ->
            _menhir_run24 _menhir_env (Obj.magic _menhir_stack) MenhirState47
        | WHILE ->
            _menhir_run1 _menhir_env (Obj.magic _menhir_stack) MenhirState47
        | DEDENT ->
            _menhir_reduce12 _menhir_env (Obj.magic _menhir_stack) MenhirState47
        | _ ->
            assert (not _menhir_env._menhir_error);
            _menhir_env._menhir_error <- true;
            _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState47) : 'freshtv192)
    | MenhirState0 | MenhirState23 | MenhirState31 | MenhirState53 | MenhirState36 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : 'freshtv193 * _menhir_state * 'tv_stmt) = Obj.magic _menhir_stack in
        ((assert (not _menhir_env._menhir_error);
        let _tok = _menhir_env._menhir_token in
        match _tok with
        | IDENT _v ->
            _menhir_run37 _menhir_env (Obj.magic _menhir_stack) MenhirState53 _v
        | IF ->
            _menhir_run32 _menhir_env (Obj.magic _menhir_stack) MenhirState53
        | NEWLINE ->
            _menhir_run31 _menhir_env (Obj.magic _menhir_stack) MenhirState53
        | PRINT ->
            _menhir_run24 _menhir_env (Obj.magic _menhir_stack) MenhirState53
        | WHILE ->
            _menhir_run1 _menhir_env (Obj.magic _menhir_stack) MenhirState53
        | DEDENT | EOF ->
            _menhir_reduce25 _menhir_env (Obj.magic _menhir_stack) MenhirState53
        | _ ->
            assert (not _menhir_env._menhir_error);
            _menhir_env._menhir_error <- true;
            _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState53) : 'freshtv194)
    | _ ->
        _menhir_fail ()

and _menhir_goto_loption_else_term_ : _menhir_env -> 'ttv_tail -> 'tv_loption_else_term_ -> 'ttv_return =
  fun _menhir_env _menhir_stack _v ->
    let (_menhir_env : _menhir_env) = _menhir_env in
    let (_menhir_stack : (((((('freshtv189 * _menhir_state) * _menhir_state * 'tv_expr) * _menhir_state))) * _menhir_state * 'tv_stmt_list)) = Obj.magic _menhir_stack in
    let (_v : 'tv_loption_else_term_) = _v in
    ((let (_menhir_env : _menhir_env) = _menhir_env in
    let (_menhir_stack : (((((('freshtv187 * _menhir_state) * _menhir_state * 'tv_expr) * _menhir_state))) * _menhir_state * 'tv_stmt_list)) = Obj.magic _menhir_stack in
    let ((_8 : 'tv_loption_else_term_) : 'tv_loption_else_term_) = _v in
    ((let ((((_menhir_stack, _menhir_s), _, (_2 : 'tv_expr)), _), _, (_6 : 'tv_stmt_list)) = _menhir_stack in
    let _v : 'tv_stmt = 
# 34 "parser.mly"
        ( IfStmt(_2, _6, _8) )
# 407 "parser.ml"
     in
    _menhir_goto_stmt _menhir_env _menhir_stack _menhir_s _v) : 'freshtv188)) : 'freshtv190)

and _menhir_reduce12 : _menhir_env -> 'ttv_tail -> _menhir_state -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s ->
    let _v : 'tv_list_stmt_ = 
# 211 "<standard.mly>"
    ( [] )
# 416 "parser.ml"
     in
    _menhir_goto_list_stmt_ _menhir_env _menhir_stack _menhir_s _v

and _menhir_goto_expr : _menhir_env -> 'ttv_tail -> _menhir_state -> 'tv_expr -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s _v ->
    let _menhir_stack = (_menhir_stack, _menhir_s, _v) in
    match _menhir_s with
    | MenhirState3 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ('freshtv131 * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((assert (not _menhir_env._menhir_error);
        let _tok = _menhir_env._menhir_token in
        match _tok with
        | DIV ->
            _menhir_run12 _menhir_env (Obj.magic _menhir_stack) MenhirState6
        | EQUAL ->
            _menhir_run18 _menhir_env (Obj.magic _menhir_stack) MenhirState6
        | MINUS ->
            _menhir_run16 _menhir_env (Obj.magic _menhir_stack) MenhirState6
        | MUL ->
            _menhir_run10 _menhir_env (Obj.magic _menhir_stack) MenhirState6
        | NOTEQUAL ->
            _menhir_run14 _menhir_env (Obj.magic _menhir_stack) MenhirState6
        | PLUS ->
            _menhir_run8 _menhir_env (Obj.magic _menhir_stack) MenhirState6
        | RPAREN ->
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : ('freshtv129 * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
            let (_menhir_s : _menhir_state) = MenhirState6 in
            ((let _menhir_env = _menhir_discard _menhir_env in
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : ('freshtv127 * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
            let (_ : _menhir_state) = _menhir_s in
            ((let ((_menhir_stack, _menhir_s), _, (_2 : 'tv_expr)) = _menhir_stack in
            let _v : 'tv_expr = 
# 55 "parser.mly"
        ( _2 )
# 454 "parser.ml"
             in
            _menhir_goto_expr _menhir_env _menhir_stack _menhir_s _v) : 'freshtv128)) : 'freshtv130)
        | _ ->
            assert (not _menhir_env._menhir_error);
            _menhir_env._menhir_error <- true;
            _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState6) : 'freshtv132)
    | MenhirState8 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (('freshtv135 * _menhir_state * 'tv_expr) * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((assert (not _menhir_env._menhir_error);
        let _tok = _menhir_env._menhir_token in
        match _tok with
        | DIV ->
            _menhir_run12 _menhir_env (Obj.magic _menhir_stack) MenhirState9
        | MUL ->
            _menhir_run10 _menhir_env (Obj.magic _menhir_stack) MenhirState9
        | COLON | EOF | EQUAL | MINUS | NEWLINE | NOTEQUAL | PLUS | RPAREN ->
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : (('freshtv133 * _menhir_state * 'tv_expr) * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
            ((let (((_menhir_stack, _menhir_s, (_1 : 'tv_expr)), _), _, (_3 : 'tv_expr)) = _menhir_stack in
            let _v : 'tv_expr = 
# 43 "parser.mly"
        ( BinopExpr(AddOp, _1, _3) )
# 478 "parser.ml"
             in
            _menhir_goto_expr _menhir_env _menhir_stack _menhir_s _v) : 'freshtv134)
        | _ ->
            assert (not _menhir_env._menhir_error);
            _menhir_env._menhir_error <- true;
            _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState9) : 'freshtv136)
    | MenhirState10 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (('freshtv139 * _menhir_state * 'tv_expr) * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (('freshtv137 * _menhir_state * 'tv_expr) * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((let (((_menhir_stack, _menhir_s, (_1 : 'tv_expr)), _), _, (_3 : 'tv_expr)) = _menhir_stack in
        let _v : 'tv_expr = 
# 47 "parser.mly"
        ( BinopExpr(MulOp, _1, _3) )
# 494 "parser.ml"
         in
        _menhir_goto_expr _menhir_env _menhir_stack _menhir_s _v) : 'freshtv138)) : 'freshtv140)
    | MenhirState12 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (('freshtv143 * _menhir_state * 'tv_expr) * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (('freshtv141 * _menhir_state * 'tv_expr) * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((let (((_menhir_stack, _menhir_s, (_1 : 'tv_expr)), _), _, (_3 : 'tv_expr)) = _menhir_stack in
        let _v : 'tv_expr = 
# 49 "parser.mly"
        ( BinopExpr(DivOp, _1, _3) )
# 506 "parser.ml"
         in
        _menhir_goto_expr _menhir_env _menhir_stack _menhir_s _v) : 'freshtv142)) : 'freshtv144)
    | MenhirState14 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (('freshtv147 * _menhir_state * 'tv_expr) * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((assert (not _menhir_env._menhir_error);
        let _tok = _menhir_env._menhir_token in
        match _tok with
        | DIV ->
            _menhir_run12 _menhir_env (Obj.magic _menhir_stack) MenhirState15
        | MINUS ->
            _menhir_run16 _menhir_env (Obj.magic _menhir_stack) MenhirState15
        | MUL ->
            _menhir_run10 _menhir_env (Obj.magic _menhir_stack) MenhirState15
        | PLUS ->
            _menhir_run8 _menhir_env (Obj.magic _menhir_stack) MenhirState15
        | COLON | EOF | NEWLINE | RPAREN ->
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : (('freshtv145 * _menhir_state * 'tv_expr) * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
            ((let (((_menhir_stack, _menhir_s, (_1 : 'tv_expr)), _), _, (_3 : 'tv_expr)) = _menhir_stack in
            let _v : 'tv_expr = 
# 53 "parser.mly"
        ( BinopExpr(NeqOp, _1, _3) )
# 530 "parser.ml"
             in
            _menhir_goto_expr _menhir_env _menhir_stack _menhir_s _v) : 'freshtv146)
        | _ ->
            assert (not _menhir_env._menhir_error);
            _menhir_env._menhir_error <- true;
            _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState15) : 'freshtv148)
    | MenhirState16 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (('freshtv151 * _menhir_state * 'tv_expr) * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((assert (not _menhir_env._menhir_error);
        let _tok = _menhir_env._menhir_token in
        match _tok with
        | DIV ->
            _menhir_run12 _menhir_env (Obj.magic _menhir_stack) MenhirState17
        | MUL ->
            _menhir_run10 _menhir_env (Obj.magic _menhir_stack) MenhirState17
        | COLON | EOF | EQUAL | MINUS | NEWLINE | NOTEQUAL | PLUS | RPAREN ->
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : (('freshtv149 * _menhir_state * 'tv_expr) * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
            ((let (((_menhir_stack, _menhir_s, (_1 : 'tv_expr)), _), _, (_3 : 'tv_expr)) = _menhir_stack in
            let _v : 'tv_expr = 
# 45 "parser.mly"
        ( BinopExpr(SubOp, _1, _3) )
# 554 "parser.ml"
             in
            _menhir_goto_expr _menhir_env _menhir_stack _menhir_s _v) : 'freshtv150)
        | _ ->
            assert (not _menhir_env._menhir_error);
            _menhir_env._menhir_error <- true;
            _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState17) : 'freshtv152)
    | MenhirState18 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (('freshtv155 * _menhir_state * 'tv_expr) * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((assert (not _menhir_env._menhir_error);
        let _tok = _menhir_env._menhir_token in
        match _tok with
        | DIV ->
            _menhir_run12 _menhir_env (Obj.magic _menhir_stack) MenhirState19
        | MINUS ->
            _menhir_run16 _menhir_env (Obj.magic _menhir_stack) MenhirState19
        | MUL ->
            _menhir_run10 _menhir_env (Obj.magic _menhir_stack) MenhirState19
        | PLUS ->
            _menhir_run8 _menhir_env (Obj.magic _menhir_stack) MenhirState19
        | COLON | EOF | NEWLINE | RPAREN ->
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : (('freshtv153 * _menhir_state * 'tv_expr) * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
            ((let (((_menhir_stack, _menhir_s, (_1 : 'tv_expr)), _), _, (_3 : 'tv_expr)) = _menhir_stack in
            let _v : 'tv_expr = 
# 51 "parser.mly"
        ( BinopExpr(EqOp, _1, _3) )
# 582 "parser.ml"
             in
            _menhir_goto_expr _menhir_env _menhir_stack _menhir_s _v) : 'freshtv154)
        | _ ->
            assert (not _menhir_env._menhir_error);
            _menhir_env._menhir_error <- true;
            _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState19) : 'freshtv156)
    | MenhirState1 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ('freshtv167 * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((assert (not _menhir_env._menhir_error);
        let _tok = _menhir_env._menhir_token in
        match _tok with
        | COLON ->
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : ('freshtv165 * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
            let (_menhir_s : _menhir_state) = MenhirState20 in
            ((let _menhir_stack = (_menhir_stack, _menhir_s) in
            let _menhir_env = _menhir_discard _menhir_env in
            let _tok = _menhir_env._menhir_token in
            match _tok with
            | NEWLINE ->
                let (_menhir_env : _menhir_env) = _menhir_env in
                let (_menhir_stack : (('freshtv161 * _menhir_state) * _menhir_state * 'tv_expr) * _menhir_state) = Obj.magic _menhir_stack in
                ((let _menhir_env = _menhir_discard _menhir_env in
                let _tok = _menhir_env._menhir_token in
                match _tok with
                | INDENT ->
                    let (_menhir_env : _menhir_env) = _menhir_env in
                    let (_menhir_stack : ((('freshtv157 * _menhir_state) * _menhir_state * 'tv_expr) * _menhir_state)) = Obj.magic _menhir_stack in
                    ((let _menhir_env = _menhir_discard _menhir_env in
                    let _tok = _menhir_env._menhir_token in
                    match _tok with
                    | IDENT _v ->
                        _menhir_run37 _menhir_env (Obj.magic _menhir_stack) MenhirState23 _v
                    | IF ->
                        _menhir_run32 _menhir_env (Obj.magic _menhir_stack) MenhirState23
                    | NEWLINE ->
                        _menhir_run31 _menhir_env (Obj.magic _menhir_stack) MenhirState23
                    | PRINT ->
                        _menhir_run24 _menhir_env (Obj.magic _menhir_stack) MenhirState23
                    | WHILE ->
                        _menhir_run1 _menhir_env (Obj.magic _menhir_stack) MenhirState23
                    | DEDENT ->
                        _menhir_reduce25 _menhir_env (Obj.magic _menhir_stack) MenhirState23
                    | _ ->
                        assert (not _menhir_env._menhir_error);
                        _menhir_env._menhir_error <- true;
                        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState23) : 'freshtv158)
                | _ ->
                    assert (not _menhir_env._menhir_error);
                    _menhir_env._menhir_error <- true;
                    let (_menhir_env : _menhir_env) = _menhir_env in
                    let (_menhir_stack : ((('freshtv159 * _menhir_state) * _menhir_state * 'tv_expr) * _menhir_state)) = Obj.magic _menhir_stack in
                    ((let (_menhir_stack, _menhir_s) = _menhir_stack in
                    _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv160)) : 'freshtv162)
            | _ ->
                assert (not _menhir_env._menhir_error);
                _menhir_env._menhir_error <- true;
                let (_menhir_env : _menhir_env) = _menhir_env in
                let (_menhir_stack : (('freshtv163 * _menhir_state) * _menhir_state * 'tv_expr) * _menhir_state) = Obj.magic _menhir_stack in
                ((let (_menhir_stack, _menhir_s) = _menhir_stack in
                _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv164)) : 'freshtv166)
        | DIV ->
            _menhir_run12 _menhir_env (Obj.magic _menhir_stack) MenhirState20
        | EQUAL ->
            _menhir_run18 _menhir_env (Obj.magic _menhir_stack) MenhirState20
        | MINUS ->
            _menhir_run16 _menhir_env (Obj.magic _menhir_stack) MenhirState20
        | MUL ->
            _menhir_run10 _menhir_env (Obj.magic _menhir_stack) MenhirState20
        | NOTEQUAL ->
            _menhir_run14 _menhir_env (Obj.magic _menhir_stack) MenhirState20
        | PLUS ->
            _menhir_run8 _menhir_env (Obj.magic _menhir_stack) MenhirState20
        | _ ->
            assert (not _menhir_env._menhir_error);
            _menhir_env._menhir_error <- true;
            _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState20) : 'freshtv168)
    | MenhirState25 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (('freshtv171 * _menhir_state)) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((assert (not _menhir_env._menhir_error);
        let _tok = _menhir_env._menhir_token in
        match _tok with
        | DIV ->
            _menhir_run12 _menhir_env (Obj.magic _menhir_stack) MenhirState26
        | EQUAL ->
            _menhir_run18 _menhir_env (Obj.magic _menhir_stack) MenhirState26
        | MINUS ->
            _menhir_run16 _menhir_env (Obj.magic _menhir_stack) MenhirState26
        | MUL ->
            _menhir_run10 _menhir_env (Obj.magic _menhir_stack) MenhirState26
        | NOTEQUAL ->
            _menhir_run14 _menhir_env (Obj.magic _menhir_stack) MenhirState26
        | PLUS ->
            _menhir_run8 _menhir_env (Obj.magic _menhir_stack) MenhirState26
        | RPAREN ->
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : (('freshtv169 * _menhir_state)) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
            let (_menhir_s : _menhir_state) = MenhirState26 in
            ((let _menhir_stack = (_menhir_stack, _menhir_s) in
            let _menhir_env = _menhir_discard _menhir_env in
            let _tok = _menhir_env._menhir_token in
            match _tok with
            | EOF ->
                _menhir_run29 _menhir_env (Obj.magic _menhir_stack) MenhirState27
            | NEWLINE ->
                _menhir_run28 _menhir_env (Obj.magic _menhir_stack) MenhirState27
            | _ ->
                assert (not _menhir_env._menhir_error);
                _menhir_env._menhir_error <- true;
                _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState27) : 'freshtv170)
        | _ ->
            assert (not _menhir_env._menhir_error);
            _menhir_env._menhir_error <- true;
            _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState26) : 'freshtv172)
    | MenhirState32 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ('freshtv183 * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((assert (not _menhir_env._menhir_error);
        let _tok = _menhir_env._menhir_token in
        match _tok with
        | COLON ->
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : ('freshtv181 * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
            let (_menhir_s : _menhir_state) = MenhirState33 in
            ((let _menhir_stack = (_menhir_stack, _menhir_s) in
            let _menhir_env = _menhir_discard _menhir_env in
            let _tok = _menhir_env._menhir_token in
            match _tok with
            | NEWLINE ->
                let (_menhir_env : _menhir_env) = _menhir_env in
                let (_menhir_stack : (('freshtv177 * _menhir_state) * _menhir_state * 'tv_expr) * _menhir_state) = Obj.magic _menhir_stack in
                ((let _menhir_env = _menhir_discard _menhir_env in
                let _tok = _menhir_env._menhir_token in
                match _tok with
                | INDENT ->
                    let (_menhir_env : _menhir_env) = _menhir_env in
                    let (_menhir_stack : ((('freshtv173 * _menhir_state) * _menhir_state * 'tv_expr) * _menhir_state)) = Obj.magic _menhir_stack in
                    ((let _menhir_env = _menhir_discard _menhir_env in
                    let _tok = _menhir_env._menhir_token in
                    match _tok with
                    | IDENT _v ->
                        _menhir_run37 _menhir_env (Obj.magic _menhir_stack) MenhirState36 _v
                    | IF ->
                        _menhir_run32 _menhir_env (Obj.magic _menhir_stack) MenhirState36
                    | NEWLINE ->
                        _menhir_run31 _menhir_env (Obj.magic _menhir_stack) MenhirState36
                    | PRINT ->
                        _menhir_run24 _menhir_env (Obj.magic _menhir_stack) MenhirState36
                    | WHILE ->
                        _menhir_run1 _menhir_env (Obj.magic _menhir_stack) MenhirState36
                    | DEDENT ->
                        _menhir_reduce25 _menhir_env (Obj.magic _menhir_stack) MenhirState36
                    | _ ->
                        assert (not _menhir_env._menhir_error);
                        _menhir_env._menhir_error <- true;
                        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState36) : 'freshtv174)
                | _ ->
                    assert (not _menhir_env._menhir_error);
                    _menhir_env._menhir_error <- true;
                    let (_menhir_env : _menhir_env) = _menhir_env in
                    let (_menhir_stack : ((('freshtv175 * _menhir_state) * _menhir_state * 'tv_expr) * _menhir_state)) = Obj.magic _menhir_stack in
                    ((let (_menhir_stack, _menhir_s) = _menhir_stack in
                    _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv176)) : 'freshtv178)
            | _ ->
                assert (not _menhir_env._menhir_error);
                _menhir_env._menhir_error <- true;
                let (_menhir_env : _menhir_env) = _menhir_env in
                let (_menhir_stack : (('freshtv179 * _menhir_state) * _menhir_state * 'tv_expr) * _menhir_state) = Obj.magic _menhir_stack in
                ((let (_menhir_stack, _menhir_s) = _menhir_stack in
                _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv180)) : 'freshtv182)
        | DIV ->
            _menhir_run12 _menhir_env (Obj.magic _menhir_stack) MenhirState33
        | EQUAL ->
            _menhir_run18 _menhir_env (Obj.magic _menhir_stack) MenhirState33
        | MINUS ->
            _menhir_run16 _menhir_env (Obj.magic _menhir_stack) MenhirState33
        | MUL ->
            _menhir_run10 _menhir_env (Obj.magic _menhir_stack) MenhirState33
        | NOTEQUAL ->
            _menhir_run14 _menhir_env (Obj.magic _menhir_stack) MenhirState33
        | PLUS ->
            _menhir_run8 _menhir_env (Obj.magic _menhir_stack) MenhirState33
        | _ ->
            assert (not _menhir_env._menhir_error);
            _menhir_env._menhir_error <- true;
            _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState33) : 'freshtv184)
    | MenhirState38 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (('freshtv185 * _menhir_state * (
# 6 "parser.mly"
       (string)
# 776 "parser.ml"
        ))) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((assert (not _menhir_env._menhir_error);
        let _tok = _menhir_env._menhir_token in
        match _tok with
        | DIV ->
            _menhir_run12 _menhir_env (Obj.magic _menhir_stack) MenhirState39
        | EOF ->
            _menhir_run29 _menhir_env (Obj.magic _menhir_stack) MenhirState39
        | EQUAL ->
            _menhir_run18 _menhir_env (Obj.magic _menhir_stack) MenhirState39
        | MINUS ->
            _menhir_run16 _menhir_env (Obj.magic _menhir_stack) MenhirState39
        | MUL ->
            _menhir_run10 _menhir_env (Obj.magic _menhir_stack) MenhirState39
        | NEWLINE ->
            _menhir_run28 _menhir_env (Obj.magic _menhir_stack) MenhirState39
        | NOTEQUAL ->
            _menhir_run14 _menhir_env (Obj.magic _menhir_stack) MenhirState39
        | PLUS ->
            _menhir_run8 _menhir_env (Obj.magic _menhir_stack) MenhirState39
        | _ ->
            assert (not _menhir_env._menhir_error);
            _menhir_env._menhir_error <- true;
            _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState39) : 'freshtv186)
    | _ ->
        _menhir_fail ()

and _menhir_goto_stmt_list : _menhir_env -> 'ttv_tail -> _menhir_state -> 'tv_stmt_list -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s _v ->
    let _menhir_stack = (_menhir_stack, _menhir_s, _v) in
    match _menhir_s with
    | MenhirState36 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ((((('freshtv95 * _menhir_state) * _menhir_state * 'tv_expr) * _menhir_state))) * _menhir_state * 'tv_stmt_list) = Obj.magic _menhir_stack in
        ((assert (not _menhir_env._menhir_error);
        let _tok = _menhir_env._menhir_token in
        match _tok with
        | DEDENT ->
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : ((((('freshtv91 * _menhir_state) * _menhir_state * 'tv_expr) * _menhir_state))) * _menhir_state * 'tv_stmt_list) = Obj.magic _menhir_stack in
            ((let _menhir_env = _menhir_discard _menhir_env in
            let _tok = _menhir_env._menhir_token in
            match _tok with
            | ELSE ->
                let (_menhir_env : _menhir_env) = _menhir_env in
                let (_menhir_stack : 'freshtv85) = Obj.magic _menhir_stack in
                ((let _menhir_env = _menhir_discard _menhir_env in
                let _tok = _menhir_env._menhir_token in
                match _tok with
                | COLON ->
                    let (_menhir_env : _menhir_env) = _menhir_env in
                    let (_menhir_stack : 'freshtv81) = Obj.magic _menhir_stack in
                    ((let _menhir_env = _menhir_discard _menhir_env in
                    let _tok = _menhir_env._menhir_token in
                    match _tok with
                    | NEWLINE ->
                        let (_menhir_env : _menhir_env) = _menhir_env in
                        let (_menhir_stack : ('freshtv77)) = Obj.magic _menhir_stack in
                        ((let _menhir_env = _menhir_discard _menhir_env in
                        let _tok = _menhir_env._menhir_token in
                        match _tok with
                        | INDENT ->
                            let (_menhir_env : _menhir_env) = _menhir_env in
                            let (_menhir_stack : (('freshtv73))) = Obj.magic _menhir_stack in
                            ((let _menhir_env = _menhir_discard _menhir_env in
                            let _tok = _menhir_env._menhir_token in
                            match _tok with
                            | IDENT _v ->
                                _menhir_run37 _menhir_env (Obj.magic _menhir_stack) MenhirState46 _v
                            | IF ->
                                _menhir_run32 _menhir_env (Obj.magic _menhir_stack) MenhirState46
                            | PRINT ->
                                _menhir_run24 _menhir_env (Obj.magic _menhir_stack) MenhirState46
                            | WHILE ->
                                _menhir_run1 _menhir_env (Obj.magic _menhir_stack) MenhirState46
                            | DEDENT ->
                                _menhir_reduce12 _menhir_env (Obj.magic _menhir_stack) MenhirState46
                            | _ ->
                                assert (not _menhir_env._menhir_error);
                                _menhir_env._menhir_error <- true;
                                _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState46) : 'freshtv74)
                        | _ ->
                            assert (not _menhir_env._menhir_error);
                            _menhir_env._menhir_error <- true;
                            let (_menhir_env : _menhir_env) = _menhir_env in
                            let (_menhir_stack : (('freshtv75))) = Obj.magic _menhir_stack in
                            (raise _eRR : 'freshtv76)) : 'freshtv78)
                    | _ ->
                        assert (not _menhir_env._menhir_error);
                        _menhir_env._menhir_error <- true;
                        let (_menhir_env : _menhir_env) = _menhir_env in
                        let (_menhir_stack : ('freshtv79)) = Obj.magic _menhir_stack in
                        (raise _eRR : 'freshtv80)) : 'freshtv82)
                | _ ->
                    assert (not _menhir_env._menhir_error);
                    _menhir_env._menhir_error <- true;
                    let (_menhir_env : _menhir_env) = _menhir_env in
                    let (_menhir_stack : 'freshtv83) = Obj.magic _menhir_stack in
                    (raise _eRR : 'freshtv84)) : 'freshtv86)
            | DEDENT | EOF | IDENT _ | IF | NEWLINE | PRINT | WHILE ->
                let (_menhir_env : _menhir_env) = _menhir_env in
                let (_menhir_stack : 'freshtv87) = Obj.magic _menhir_stack in
                ((let _v : 'tv_loption_else_term_ = 
# 142 "<standard.mly>"
    ( [] )
# 882 "parser.ml"
                 in
                _menhir_goto_loption_else_term_ _menhir_env _menhir_stack _v) : 'freshtv88)
            | _ ->
                assert (not _menhir_env._menhir_error);
                _menhir_env._menhir_error <- true;
                let (_menhir_env : _menhir_env) = _menhir_env in
                let (_menhir_stack : (((((('freshtv89 * _menhir_state) * _menhir_state * 'tv_expr) * _menhir_state))) * _menhir_state * 'tv_stmt_list)) = Obj.magic _menhir_stack in
                ((let (_menhir_stack, _menhir_s, _) = _menhir_stack in
                _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv90)) : 'freshtv92)
        | _ ->
            assert (not _menhir_env._menhir_error);
            _menhir_env._menhir_error <- true;
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : ((((('freshtv93 * _menhir_state) * _menhir_state * 'tv_expr) * _menhir_state))) * _menhir_state * 'tv_stmt_list) = Obj.magic _menhir_stack in
            ((let (_menhir_stack, _menhir_s, _) = _menhir_stack in
            _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv94)) : 'freshtv96)
    | MenhirState53 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ('freshtv99 * _menhir_state * 'tv_stmt) * _menhir_state * 'tv_stmt_list) = Obj.magic _menhir_stack in
        ((let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ('freshtv97 * _menhir_state * 'tv_stmt) * _menhir_state * 'tv_stmt_list) = Obj.magic _menhir_stack in
        ((let ((_menhir_stack, _menhir_s, (_1 : 'tv_stmt)), _, (_2 : 'tv_stmt_list)) = _menhir_stack in
        let _v : 'tv_stmt_list = 
# 29 "parser.mly"
                        ( _1::_2 )
# 908 "parser.ml"
         in
        _menhir_goto_stmt_list _menhir_env _menhir_stack _menhir_s _v) : 'freshtv98)) : 'freshtv100)
    | MenhirState31 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ('freshtv103 * _menhir_state) * _menhir_state * 'tv_stmt_list) = Obj.magic _menhir_stack in
        ((let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ('freshtv101 * _menhir_state) * _menhir_state * 'tv_stmt_list) = Obj.magic _menhir_stack in
        ((let ((_menhir_stack, _menhir_s), _, (_2 : 'tv_stmt_list)) = _menhir_stack in
        let _v : 'tv_stmt_list = 
# 28 "parser.mly"
                        ( _2 )
# 920 "parser.ml"
         in
        _menhir_goto_stmt_list _menhir_env _menhir_stack _menhir_s _v) : 'freshtv102)) : 'freshtv104)
    | MenhirState23 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ((((('freshtv111 * _menhir_state) * _menhir_state * 'tv_expr) * _menhir_state))) * _menhir_state * 'tv_stmt_list) = Obj.magic _menhir_stack in
        ((assert (not _menhir_env._menhir_error);
        let _tok = _menhir_env._menhir_token in
        match _tok with
        | DEDENT ->
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : ((((('freshtv107 * _menhir_state) * _menhir_state * 'tv_expr) * _menhir_state))) * _menhir_state * 'tv_stmt_list) = Obj.magic _menhir_stack in
            ((let _menhir_env = _menhir_discard _menhir_env in
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : ((((('freshtv105 * _menhir_state) * _menhir_state * 'tv_expr) * _menhir_state))) * _menhir_state * 'tv_stmt_list) = Obj.magic _menhir_stack in
            ((let ((((_menhir_stack, _menhir_s), _, (_2 : 'tv_expr)), _), _, (_6 : 'tv_stmt_list)) = _menhir_stack in
            let _v : 'tv_stmt = 
# 36 "parser.mly"
        ( WhileStmt(_2, _6) )
# 939 "parser.ml"
             in
            _menhir_goto_stmt _menhir_env _menhir_stack _menhir_s _v) : 'freshtv106)) : 'freshtv108)
        | _ ->
            assert (not _menhir_env._menhir_error);
            _menhir_env._menhir_error <- true;
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : ((((('freshtv109 * _menhir_state) * _menhir_state * 'tv_expr) * _menhir_state))) * _menhir_state * 'tv_stmt_list) = Obj.magic _menhir_stack in
            ((let (_menhir_stack, _menhir_s, _) = _menhir_stack in
            _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv110)) : 'freshtv112)
    | MenhirState0 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : 'freshtv125 * _menhir_state * 'tv_stmt_list) = Obj.magic _menhir_stack in
        ((assert (not _menhir_env._menhir_error);
        let _tok = _menhir_env._menhir_token in
        match _tok with
        | EOF ->
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : 'freshtv121 * _menhir_state * 'tv_stmt_list) = Obj.magic _menhir_stack in
            ((let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : 'freshtv119 * _menhir_state * 'tv_stmt_list) = Obj.magic _menhir_stack in
            ((let (_menhir_stack, _menhir_s, (_1 : 'tv_stmt_list)) = _menhir_stack in
            let _v : (
# 21 "parser.mly"
       (Syntax.pyprog)
# 964 "parser.ml"
            ) = 
# 25 "parser.mly"
                    ( _1 )
# 968 "parser.ml"
             in
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : 'freshtv117) = _menhir_stack in
            let (_menhir_s : _menhir_state) = _menhir_s in
            let (_v : (
# 21 "parser.mly"
       (Syntax.pyprog)
# 976 "parser.ml"
            )) = _v in
            ((let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : 'freshtv115) = Obj.magic _menhir_stack in
            let (_menhir_s : _menhir_state) = _menhir_s in
            let (_v : (
# 21 "parser.mly"
       (Syntax.pyprog)
# 984 "parser.ml"
            )) = _v in
            ((let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : 'freshtv113) = Obj.magic _menhir_stack in
            let (_menhir_s : _menhir_state) = _menhir_s in
            let ((_1 : (
# 21 "parser.mly"
       (Syntax.pyprog)
# 992 "parser.ml"
            )) : (
# 21 "parser.mly"
       (Syntax.pyprog)
# 996 "parser.ml"
            )) = _v in
            (Obj.magic _1 : 'freshtv114)) : 'freshtv116)) : 'freshtv118)) : 'freshtv120)) : 'freshtv122)
        | _ ->
            assert (not _menhir_env._menhir_error);
            _menhir_env._menhir_error <- true;
            let (_menhir_env : _menhir_env) = _menhir_env in
            let (_menhir_stack : 'freshtv123 * _menhir_state * 'tv_stmt_list) = Obj.magic _menhir_stack in
            ((let (_menhir_stack, _menhir_s, _) = _menhir_stack in
            _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv124)) : 'freshtv126)
    | _ ->
        _menhir_fail ()

and _menhir_run2 : _menhir_env -> 'ttv_tail -> _menhir_state -> (
# 7 "parser.mly"
       (string)
# 1012 "parser.ml"
) -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s _v ->
    let _menhir_env = _menhir_discard _menhir_env in
    let (_menhir_env : _menhir_env) = _menhir_env in
    let (_menhir_stack : 'freshtv71) = Obj.magic _menhir_stack in
    let (_menhir_s : _menhir_state) = _menhir_s in
    let ((_1 : (
# 7 "parser.mly"
       (string)
# 1022 "parser.ml"
    )) : (
# 7 "parser.mly"
       (string)
# 1026 "parser.ml"
    )) = _v in
    ((let _v : 'tv_expr = 
# 61 "parser.mly"
        ( ConstExpr(StrValue(_1)) )
# 1031 "parser.ml"
     in
    _menhir_goto_expr _menhir_env _menhir_stack _menhir_s _v) : 'freshtv72)

and _menhir_run3 : _menhir_env -> 'ttv_tail -> _menhir_state -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s ->
    let _menhir_stack = (_menhir_stack, _menhir_s) in
    let _menhir_env = _menhir_discard _menhir_env in
    let _tok = _menhir_env._menhir_token in
    match _tok with
    | IDENT _v ->
        _menhir_run5 _menhir_env (Obj.magic _menhir_stack) MenhirState3 _v
    | INT _v ->
        _menhir_run4 _menhir_env (Obj.magic _menhir_stack) MenhirState3 _v
    | LPAREN ->
        _menhir_run3 _menhir_env (Obj.magic _menhir_stack) MenhirState3
    | STRING _v ->
        _menhir_run2 _menhir_env (Obj.magic _menhir_stack) MenhirState3 _v
    | _ ->
        assert (not _menhir_env._menhir_error);
        _menhir_env._menhir_error <- true;
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState3

and _menhir_run4 : _menhir_env -> 'ttv_tail -> _menhir_state -> (
# 8 "parser.mly"
       (int)
# 1057 "parser.ml"
) -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s _v ->
    let _menhir_env = _menhir_discard _menhir_env in
    let (_menhir_env : _menhir_env) = _menhir_env in
    let (_menhir_stack : 'freshtv69) = Obj.magic _menhir_stack in
    let (_menhir_s : _menhir_state) = _menhir_s in
    let ((_1 : (
# 8 "parser.mly"
       (int)
# 1067 "parser.ml"
    )) : (
# 8 "parser.mly"
       (int)
# 1071 "parser.ml"
    )) = _v in
    ((let _v : 'tv_expr = 
# 59 "parser.mly"
        ( ConstExpr(IntValue(_1)) )
# 1076 "parser.ml"
     in
    _menhir_goto_expr _menhir_env _menhir_stack _menhir_s _v) : 'freshtv70)

and _menhir_run5 : _menhir_env -> 'ttv_tail -> _menhir_state -> (
# 6 "parser.mly"
       (string)
# 1083 "parser.ml"
) -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s _v ->
    let _menhir_env = _menhir_discard _menhir_env in
    let (_menhir_env : _menhir_env) = _menhir_env in
    let (_menhir_stack : 'freshtv67) = Obj.magic _menhir_stack in
    let (_menhir_s : _menhir_state) = _menhir_s in
    let ((_1 : (
# 6 "parser.mly"
       (string)
# 1093 "parser.ml"
    )) : (
# 6 "parser.mly"
       (string)
# 1097 "parser.ml"
    )) = _v in
    ((let _v : 'tv_expr = 
# 57 "parser.mly"
        ( IdentExpr(_1) )
# 1102 "parser.ml"
     in
    _menhir_goto_expr _menhir_env _menhir_stack _menhir_s _v) : 'freshtv68)

and _menhir_errorcase : _menhir_env -> 'ttv_tail -> _menhir_state -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s ->
    match _menhir_s with
    | MenhirState53 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : 'freshtv11 * _menhir_state * 'tv_stmt) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s, _) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv12)
    | MenhirState47 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : 'freshtv13 * _menhir_state * 'tv_stmt) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s, _) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv14)
    | MenhirState46 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ((('freshtv15)))) = Obj.magic _menhir_stack in
        (raise _eRR : 'freshtv16)
    | MenhirState39 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (('freshtv17 * _menhir_state * (
# 6 "parser.mly"
       (string)
# 1128 "parser.ml"
        ))) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s, _) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv18)
    | MenhirState38 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ('freshtv19 * _menhir_state * (
# 6 "parser.mly"
       (string)
# 1137 "parser.ml"
        ))) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s, _) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv20)
    | MenhirState36 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (((('freshtv21 * _menhir_state) * _menhir_state * 'tv_expr) * _menhir_state))) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv22)
    | MenhirState33 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ('freshtv23 * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s, _) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv24)
    | MenhirState32 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : 'freshtv25 * _menhir_state) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv26)
    | MenhirState31 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : 'freshtv27 * _menhir_state) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv28)
    | MenhirState27 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ((('freshtv29 * _menhir_state)) * _menhir_state * 'tv_expr) * _menhir_state) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv30)
    | MenhirState26 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (('freshtv31 * _menhir_state)) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s, _) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv32)
    | MenhirState25 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ('freshtv33 * _menhir_state)) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv34)
    | MenhirState23 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (((('freshtv35 * _menhir_state) * _menhir_state * 'tv_expr) * _menhir_state))) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv36)
    | MenhirState20 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ('freshtv37 * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s, _) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv38)
    | MenhirState19 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (('freshtv39 * _menhir_state * 'tv_expr) * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s, _) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv40)
    | MenhirState18 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ('freshtv41 * _menhir_state * 'tv_expr) * _menhir_state) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv42)
    | MenhirState17 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (('freshtv43 * _menhir_state * 'tv_expr) * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s, _) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv44)
    | MenhirState16 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ('freshtv45 * _menhir_state * 'tv_expr) * _menhir_state) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv46)
    | MenhirState15 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (('freshtv47 * _menhir_state * 'tv_expr) * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s, _) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv48)
    | MenhirState14 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ('freshtv49 * _menhir_state * 'tv_expr) * _menhir_state) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv50)
    | MenhirState12 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ('freshtv51 * _menhir_state * 'tv_expr) * _menhir_state) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv52)
    | MenhirState10 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ('freshtv53 * _menhir_state * 'tv_expr) * _menhir_state) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv54)
    | MenhirState9 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : (('freshtv55 * _menhir_state * 'tv_expr) * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s, _) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv56)
    | MenhirState8 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ('freshtv57 * _menhir_state * 'tv_expr) * _menhir_state) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv58)
    | MenhirState6 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : ('freshtv59 * _menhir_state) * _menhir_state * 'tv_expr) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s, _) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv60)
    | MenhirState3 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : 'freshtv61 * _menhir_state) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv62)
    | MenhirState1 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : 'freshtv63 * _menhir_state) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv64)
    | MenhirState0 ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : 'freshtv65) = Obj.magic _menhir_stack in
        (raise _eRR : 'freshtv66)

and _menhir_reduce25 : _menhir_env -> 'ttv_tail -> _menhir_state -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s ->
    let _v : 'tv_stmt_list = 
# 30 "parser.mly"
                        ( [] )
# 1261 "parser.ml"
     in
    _menhir_goto_stmt_list _menhir_env _menhir_stack _menhir_s _v

and _menhir_run1 : _menhir_env -> 'ttv_tail -> _menhir_state -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s ->
    let _menhir_stack = (_menhir_stack, _menhir_s) in
    let _menhir_env = _menhir_discard _menhir_env in
    let _tok = _menhir_env._menhir_token in
    match _tok with
    | IDENT _v ->
        _menhir_run5 _menhir_env (Obj.magic _menhir_stack) MenhirState1 _v
    | INT _v ->
        _menhir_run4 _menhir_env (Obj.magic _menhir_stack) MenhirState1 _v
    | LPAREN ->
        _menhir_run3 _menhir_env (Obj.magic _menhir_stack) MenhirState1
    | STRING _v ->
        _menhir_run2 _menhir_env (Obj.magic _menhir_stack) MenhirState1 _v
    | _ ->
        assert (not _menhir_env._menhir_error);
        _menhir_env._menhir_error <- true;
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState1

and _menhir_run24 : _menhir_env -> 'ttv_tail -> _menhir_state -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s ->
    let _menhir_stack = (_menhir_stack, _menhir_s) in
    let _menhir_env = _menhir_discard _menhir_env in
    let _tok = _menhir_env._menhir_token in
    match _tok with
    | LPAREN ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : 'freshtv7 * _menhir_state) = Obj.magic _menhir_stack in
        ((let _menhir_env = _menhir_discard _menhir_env in
        let _tok = _menhir_env._menhir_token in
        match _tok with
        | IDENT _v ->
            _menhir_run5 _menhir_env (Obj.magic _menhir_stack) MenhirState25 _v
        | INT _v ->
            _menhir_run4 _menhir_env (Obj.magic _menhir_stack) MenhirState25 _v
        | LPAREN ->
            _menhir_run3 _menhir_env (Obj.magic _menhir_stack) MenhirState25
        | STRING _v ->
            _menhir_run2 _menhir_env (Obj.magic _menhir_stack) MenhirState25 _v
        | _ ->
            assert (not _menhir_env._menhir_error);
            _menhir_env._menhir_error <- true;
            _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState25) : 'freshtv8)
    | _ ->
        assert (not _menhir_env._menhir_error);
        _menhir_env._menhir_error <- true;
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : 'freshtv9 * _menhir_state) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv10)

and _menhir_run31 : _menhir_env -> 'ttv_tail -> _menhir_state -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s ->
    let _menhir_stack = (_menhir_stack, _menhir_s) in
    let _menhir_env = _menhir_discard _menhir_env in
    let _tok = _menhir_env._menhir_token in
    match _tok with
    | IDENT _v ->
        _menhir_run37 _menhir_env (Obj.magic _menhir_stack) MenhirState31 _v
    | IF ->
        _menhir_run32 _menhir_env (Obj.magic _menhir_stack) MenhirState31
    | NEWLINE ->
        _menhir_run31 _menhir_env (Obj.magic _menhir_stack) MenhirState31
    | PRINT ->
        _menhir_run24 _menhir_env (Obj.magic _menhir_stack) MenhirState31
    | WHILE ->
        _menhir_run1 _menhir_env (Obj.magic _menhir_stack) MenhirState31
    | DEDENT | EOF ->
        _menhir_reduce25 _menhir_env (Obj.magic _menhir_stack) MenhirState31
    | _ ->
        assert (not _menhir_env._menhir_error);
        _menhir_env._menhir_error <- true;
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState31

and _menhir_run32 : _menhir_env -> 'ttv_tail -> _menhir_state -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s ->
    let _menhir_stack = (_menhir_stack, _menhir_s) in
    let _menhir_env = _menhir_discard _menhir_env in
    let _tok = _menhir_env._menhir_token in
    match _tok with
    | IDENT _v ->
        _menhir_run5 _menhir_env (Obj.magic _menhir_stack) MenhirState32 _v
    | INT _v ->
        _menhir_run4 _menhir_env (Obj.magic _menhir_stack) MenhirState32 _v
    | LPAREN ->
        _menhir_run3 _menhir_env (Obj.magic _menhir_stack) MenhirState32
    | STRING _v ->
        _menhir_run2 _menhir_env (Obj.magic _menhir_stack) MenhirState32 _v
    | _ ->
        assert (not _menhir_env._menhir_error);
        _menhir_env._menhir_error <- true;
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState32

and _menhir_run37 : _menhir_env -> 'ttv_tail -> _menhir_state -> (
# 6 "parser.mly"
       (string)
# 1361 "parser.ml"
) -> 'ttv_return =
  fun _menhir_env _menhir_stack _menhir_s _v ->
    let _menhir_stack = (_menhir_stack, _menhir_s, _v) in
    let _menhir_env = _menhir_discard _menhir_env in
    let _tok = _menhir_env._menhir_token in
    match _tok with
    | ASSIGN ->
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : 'freshtv3 * _menhir_state * (
# 6 "parser.mly"
       (string)
# 1373 "parser.ml"
        )) = Obj.magic _menhir_stack in
        ((let _menhir_env = _menhir_discard _menhir_env in
        let _tok = _menhir_env._menhir_token in
        match _tok with
        | IDENT _v ->
            _menhir_run5 _menhir_env (Obj.magic _menhir_stack) MenhirState38 _v
        | INT _v ->
            _menhir_run4 _menhir_env (Obj.magic _menhir_stack) MenhirState38 _v
        | LPAREN ->
            _menhir_run3 _menhir_env (Obj.magic _menhir_stack) MenhirState38
        | STRING _v ->
            _menhir_run2 _menhir_env (Obj.magic _menhir_stack) MenhirState38 _v
        | _ ->
            assert (not _menhir_env._menhir_error);
            _menhir_env._menhir_error <- true;
            _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState38) : 'freshtv4)
    | _ ->
        assert (not _menhir_env._menhir_error);
        _menhir_env._menhir_error <- true;
        let (_menhir_env : _menhir_env) = _menhir_env in
        let (_menhir_stack : 'freshtv5 * _menhir_state * (
# 6 "parser.mly"
       (string)
# 1397 "parser.ml"
        )) = Obj.magic _menhir_stack in
        ((let (_menhir_stack, _menhir_s, _) = _menhir_stack in
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) _menhir_s) : 'freshtv6)

and _menhir_discard : _menhir_env -> _menhir_env =
  fun _menhir_env ->
    let lexer = _menhir_env._menhir_lexer in
    let lexbuf = _menhir_env._menhir_lexbuf in
    let _tok = lexer lexbuf in
    {
      _menhir_lexer = lexer;
      _menhir_lexbuf = lexbuf;
      _menhir_token = _tok;
      _menhir_error = false;
    }

and prog : (Lexing.lexbuf -> token) -> Lexing.lexbuf -> (
# 21 "parser.mly"
       (Syntax.pyprog)
# 1417 "parser.ml"
) =
  fun lexer lexbuf ->
    let _menhir_env = {
      _menhir_lexer = lexer;
      _menhir_lexbuf = lexbuf;
      _menhir_token = Obj.magic ();
      _menhir_error = false;
    } in
    Obj.magic (let (_menhir_env : _menhir_env) = _menhir_env in
    let (_menhir_stack : 'freshtv1) = ((), _menhir_env._menhir_lexbuf.Lexing.lex_curr_p) in
    ((let _menhir_env = _menhir_discard _menhir_env in
    let _tok = _menhir_env._menhir_token in
    match _tok with
    | IDENT _v ->
        _menhir_run37 _menhir_env (Obj.magic _menhir_stack) MenhirState0 _v
    | IF ->
        _menhir_run32 _menhir_env (Obj.magic _menhir_stack) MenhirState0
    | NEWLINE ->
        _menhir_run31 _menhir_env (Obj.magic _menhir_stack) MenhirState0
    | PRINT ->
        _menhir_run24 _menhir_env (Obj.magic _menhir_stack) MenhirState0
    | WHILE ->
        _menhir_run1 _menhir_env (Obj.magic _menhir_stack) MenhirState0
    | EOF ->
        _menhir_reduce25 _menhir_env (Obj.magic _menhir_stack) MenhirState0
    | _ ->
        assert (not _menhir_env._menhir_error);
        _menhir_env._menhir_error <- true;
        _menhir_errorcase _menhir_env (Obj.magic _menhir_stack) MenhirState0) : 'freshtv2))

# 269 "<standard.mly>"
  

# 1451 "parser.ml"
