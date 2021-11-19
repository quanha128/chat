type expr =
| Add of expr * expr
| Mul of expr * expr
| StrVal of string
| IntVal of int
| Var of string

type typ = IntType | StrType

let env = [("a", IntType); ("b", StrType)]

let rec type_infer expr =
  match expr with
  | Add(e1,e2) ->
    begin
    match type_infer e1, type_infer e2 with
    | IntType, IntType -> IntType
    | StrType, StrType -> StrType
    | _ -> failwith "type error"
    end
  | Mul(e1,e2) ->
    begin
    match type_infer e1, type_infer e2 with
    | IntType, IntType -> IntType
    | StrType, IntType | IntType, StrType -> StrType
    | _ -> failwith "type error"
    end
  | StrVal(str) -> StrType
  | IntVal(i) -> IntType
  | Var(name) -> List.assoc name env