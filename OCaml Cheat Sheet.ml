; (* Seperator in the interperter. *)
;; (* Mostly used when interpreting OCaml, tells it that iahs stopped. *)

(* Gets definitions from the given package. *)
open List;; (* opens the List package which allows you to use List definitions. *)


(* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= *)
char   -->   Example: 'a'

float   -->   Example: 2.14
	3.0 +. 0.2;; (* Operators for floating numbers must have a dot after the operator. *)

int   -->   Example: 3

(* Items are separated by ; and the types must be the same! *)
list   -->   Example: [1;2;3]
  ['a';'b';'c'] (* List of characters. *)
  let l2 = [1;2;3];; (* Sets the name l2 to the given list. *)
  4::5::6::[];;   -->   -: int list [4;5;6]
  4::5::[6];;   -->   -: int list [4;5;6]
  
  let l1 = ['a';'b';'c'];;
  
  (* Head of the list, returns the first element of a list. *)
  hd l1;;   -->   char = 'a'
  
  (* Tail of the list, returns the list without the first element. *)
  tl l1;;   -->   char list = ['b';'c']
  
  (* Appends 2 lists together. Version 1. *)
  let rec append2 l1 l2 =
    if l1 = [] then l2 (* If l1 is an empty list then return l2. *)
    else hd l1 :: append2 (tl l1) l2;; (* Take the first element of l1 and combine it with  *)
    
  (* Appends 2 lists together. Version 2. *)
  let rec append2 l1 l2 =
    match l1 with
    | [] -> 12 (* If l1 is an empty list then return l2. *)
    | _ -> hd l1 :: append2 (t1 l1) l2;;
    append2 [1;2] [3;4]   -->   -: int list = [1;2;3;4]
    
  (* Check if an item is in a list. *)
  let rec member x l =
    if l = [] then false
    else if x = hd l then true
    else member x (tl l);;
    member 1 [1;2;3];;   -->   -: bool = true
    member 4 [1;2;3];;   -->   -: bool = false

(* Arrays, can allow you to directly access the elements and index. *)
let five_primes = [| 2; 3; 5; 7; 11 |];; (* An array example of 5 ints. *)
  five_primes.(2);;   -->   -: int = 5 (* Returns the number at index 2. *)
  five_primes.(2) <- 4   -->   -: unit = () (* Changes the value of index 2 to 4. *)
  five_primes;;   -->   -: int array = [|2; 3; 4; 7; 11|]
  
(* Tuples, consists of values (0 or more), enclosed in parentheses and separated by commas. Can have different types for each element. *)
	(1, 2);;   -->   -: int * int (1, 2)
	(1, "Hello");;   -->   -: int * string = (1, "Hello")
	(1, "Hello", 1.234);;   --> -: int * string * float = (1, "Hello", 1.234) (*Example of a 3-dimensional tuple. *)
	(10234, "Sa");;   -->   -: int * string = (10234, "Sa")

	type 'a tree = Empty | Node of 'a * 'a tree * 'a tree;;
		let myt1 = Empty;;
		let myt2 = (1, Empty, Empty);;
		let myt2 = (2, myt1, Empty);;
		let myt3 = (3, myt2, Empty);;
		let myt4 = (4, myt2, myt3);;
	
	("Hg", 80);;   -->   -: string * int = ("Hg", 80)
	let mercury = ("Hg", 80);; (* Set this tuple to a name *)

	(* Gets the first value of the tuple. *)
	fst mercury;;   -->   -: string = "Hg"

	(* Gets the second value of the tuple. *)
	snd mercury;;   -->   -: int = 80

(* Records, fields in a record has a name unlike tuples. The order doesn't matter unlike tuples. *)
	type element = {name: string; atomic_number: int; atomic_weight float};;
		let mercury = { atomic_number = 80; name = "Hg"; atomic_weight = 200.592};; (* Makes a record that we defined above. *)
		mercury.name;;   -->   -: string = "Hg"
		mercury.atomic_number;;   -->   -: int = 80
	
	(* mutable - This keyword allows you to make a certain field in a record changeable once set. *)
	type sale_item = {name: string; mutable price: float};; (* Makes a new record with price being mutable, which means it can change! *)
		let my_item = {name = "bike"; price = 699.99};;
		my_item.price;;   -->   -: float = 699.99
		my_item.price <- 599.99;;
		my_item.price;;   -->   -: float = 599.99
		
(* References, kind like a pointer. *)
	let x = ref 3;;   -->   val x : int ref = {contents = 3}
	!x;;   -->   -: int = 3 (* Gets the value of x. *)
	x := !x + 1;; (* Changes the value of x. *)
	!x;;   -->   -: int = 4 (* Gets the value of x. *)
	
type weekday = Sun | Mon | Tue | Wed | Thu | Fri | Sat;;
type yearday = YMD of int * int * int | YD of int * int;;
	let a = YMD(2020, 3, 2);; (*Creates a type yearday defined above. *)


(* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= *)
(* Physical Equivelance *)
==   -->   Example: 2 == 2
	2 == 3   -->   false
	let l1 = [1;2]; l1 == l1   -->   true
  
(* Structural Equivelance *)
=   -->   Example: [1] = [1]
	[1;2;3] = [1;2;3]   -->   true
	let l1 = [1;2]; l1 = [1;2]   -->   true
 
(* List Construction. *)
::
 
(* Concatenation or appends lists together *)
@
[1;2]@[3;4];;   -->   -: int list = [1;2;3;4]


(* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= *)
(* Parameters don't have () or commas in between. *)
max 1 2;;   -->   -: int = 2

let   -->   (* Sets things to names. *)
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