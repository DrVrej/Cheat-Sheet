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
  
(* Functions [4 styles / types] *)
let average = fun x y -> (x +. y) /. 2.;; (* Type 1, allows polomorphism. *)
  average 2. 3.;;   -->   -: float = 2.5
let average2 x y = (x +. y) /. 2.;; (* Type 2, allows polomorphism. *)
  average2 2. 3.;;   -->   -: float = 2.5
let average3: float -> float -> float = fun x y -> (x +. y) /. 2.;; (* Type 3, useful for setting the type of the paramters specifically! *)
  average3 2. 3.;;   -->   -: float = 2.5
let average4 (x:float) (y:float) : float = (x +. y) /. 2.;; (* Type 4, more readable then Type 3. *)
  average4 2. 3.;;   -->   -: float = 2.5

(* Local names using   let - in   system. *)
let triangle_area a b c =
  let s = (a +. b +. c) /. 2.0 in (* Local name. *)
    sqrt(s *. (s -. a) *. (s -. b) *. ( s -. c));;
  triangle_area 3. 4. 5.;;   -->   -: float = 6.

(* Function Recursion using   rec   This tells OCaml that it will be a recusive function. *)
let rec fact x =
  if x = 0 then 1
  else x * fact(x - 1);;
  fact 0;;   -->   -: int = 1
  fact 1;;   -->   -: int = 1
  fact 2;;   -->   -: int = 2
  fact 3;;   -->   -: int = 6
  fact 4;;   -->   -: int = 24

(* Using match-with statement.    | = New case or seperator.    _ = Default.    *)
let rec fact x =
  match x with
    | 0 -> 1
    | _ -> x * fact(x - 1);;
  fact 0;;   -->   -: int = 1
  fact 1;;   -->   -: int = 1
  fact 2;;   -->   -: int = 2
  fact 3;;   -->   -: int = 6
  fact 4;;   -->   -: int = 24

(* This will throw an error because it doesn't have a default ( _ ). *)
let foo x =
  match x with
    | 0 -> "zero"
    | 1 -> "one";;

(* Recursive helper functions, *)
let fib n =
  let rec fib_helper f1 f2 i =
    if i = n then f1
    else fib_helper f2 (f1 + f2) (i + 1) in
      fib_helper 0 1 0;;
  fib 0;;   -->   -: int = 0
  fib 1;;   -->   -: int = 1
  fib 2;;   -->   -: int = 1
  fib 3;;   -->   -: int = 2






