; (* Seperator in the interperter. *)
;; (* Mostly used when interpreting OCaml, tells it that iahs stopped. *)

(* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= *)
char   -->   Example: 'a'

float   -->   Example: 2.14
  3.0 +. 0.2;; (* Operators for floating numbers must have a dot after the operator. *)

int   -->   Example: 3

list   -->   Example: [1;2;3]
(* Items ar seperated by ; and the types must be the same! *)

(* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= *)
(* Physical Equivelance *)
==   -->   Example: 2 == 2
  2 == 3   -->   false
  let l1 = [1;2]; l1 == l1   -->   true
  
(* Structural Equivelance *)
=   -->   Example: [1] = [1]
  [1;2;3] = [1;2;3]   -->   true
  let l1 = [1;2]; l1 = [1;2]   -->   true
  
(* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= *)
(* Parameters don't have () or commas in between. *)
max 1 2;;   -->   -: int = 2

let   -->   Sets things to names.
  let hi = 3;; (* Sets the name hi to int 3. *)
  let f3() = 3;; (* Put () if there is no parameters. *)
