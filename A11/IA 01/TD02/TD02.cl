International Allegro CL Free Express Edition
8.2 [Mac OS X (Intel)] (Oct 2, 2011 23:00)
Copyright (C) 1985-2010, Franz Inc., Oakland, CA, USA.  All Rights Reserved.

This development copy of Allegro CL is licensed to:
   Allegro CL 8.2 Express user

CG version 1.134 / IDE version 1.125
;; Optimization settings: safety 1, space 1, speed 1, debug 2.
;; For a complete description of all compiler switches given the current optimization settings evaluate
;; (EXPLAIN-COMPILER-SETTINGS).

[changing package from "COMMON-LISP-USER" to "COMMON-GRAPHICS-USER"]
CG-USER(1): 
;; Connecting to http://www.franz.com/ftp/pub/patches/.
;; Reading CRC cache...done.
;; Checking for new update.fasl.
;; Retrieving list of available patches.
;; Checking which patches need to be downloaded.
CG-USER(1): 
;; Connecting to http://www.franz.com/ftp/pub/patches/.
;; Checking for new update.fasl.
;; Retrieving list of available patches.
;; Checking which patches need to be downloaded.
CG-USER(1): (defun deriv_term (F X)
              (if (eq F X) 1 0))
DERIV_TERM
CG-USER(2): (defun deriv_sum (F X)
              (list
                '+
                (deriv (cadr F) X)
                (deriv (caddr F) X)))
DERIV_SUM
CG-USER(3): 
CG-USER(3): (defun deriv_mult (F X)
(list
'+
(list '* (deriv (cadr F) X) (caddr F))
(list '* (cadr F) (deriv (caddr F) X))
)
)
DERIV_MULT
CG-USER(4): (defun deriv (F X)
(if (atom F)
(deriv_term F X)
(case (car F)
('+ (deriv_sum F X))
('* (deriv_mult F X))
)
)
)
DERIV
CG-USER(5
CG-USER(5): (deriv '(+(* 2 x) 3) 'x)
(+ (+ (* 0 X) (* 2 1)) 0)
CG-USER(6): (defun simplify1 (F)
(cond
 ((and (numberp (cadr F)) (numberp (caddr F))) (eval F))
 ((eq (car F) '+)
   (cond
    ((eq (cadr F) 0) (caddr F))
    ((eq (caddr F) 0) (cadr F))
   )
 )
 ((eq (car F) '*)
   (cond
    ((eq (cadr F) 0) 0)
    ((eq (caddr F) 0) 0)
    ((eq (cadr F) 1) (caddr F))
    ((eq (caddr F) 1) (cadr F))
   )
 )
)
)
SIMPLIFY1
CG-USER(7): (simplify1 '(+ 2 3))
NIL
CG-USER(8): (setq H '(+ 2 3))
(+ 2 3)
CG-USER(9): H
(+ 2 3)
CG-USER(10): (eval H)
5
CG-USER(11): (simlify1 H)
Error: attempt to call `SIMLIFY1' which is an undefined function.
[condition type: UNDEFINED-FUNCTION]
CG-USER(12): (simplify1 H)
NIL
CG-USER(13): (defun simplify1 (F)
(cond
 ((and (numberp (cadr F)) (numberp (caddr F))) (eval F))
 ((eq (car F) '+)
   (cond
    ((eq (cadr F) 0) (caddr F))
    ((eq (caddr F) 0) (cadr F))
   )
 )
 ((eq (car F) '*)
   (cond
    ((eq (cadr F) 0) 0)
    ((eq (caddr F) 0) 0)
    ((eq (cadr F) 1) (caddr F))
    ((eq (caddr F) 1) (cadr F))
   )
 )
)
)
SIMPLIFY1
CG-USER(14): (simplify1 H)
5
CG-USER(15): (simplify1 (+ 2 5))
Error: Attempt to take the cdr of 7 which is not listp.
[condition type: TYPE-ERROR]
CG-USER(16): (simplify1 '(+ 2 5))
7
CG-USER(17): (simplify1 '(+ 3 x))
NIL
CG-USER(18): (defun simplify1 (F)
(cond
 ((and (numberp (cadr F)) (numberp (caddr F))) (eval F))
 ((eq (car F) '+)
   (cond
    ((eq (cadr F) 0) (caddr F))
    ((eq (caddr F) 0) (cadr F))
   )
 )
 ((eq (car F) '*)
   (cond
    ((eq (cadr F) 0) 0)
    ((eq (caddr F) 0) 0)
    ((eq (cadr F) 1) (caddr F))
    ((eq (caddr F) 1) (cadr F))
   )
 )
)
)
SIMPLIFY1
CG-USER(19): (defun simplify1 (F)
(cond
 ((and (numberp (cadr F)) (numberp (caddr F))) (eval F))
 ((eq (car F) '+)
   (cond
    ((eq (cadr F) 0) (caddr F))
    ((eq (caddr F) 0) (cadr F))
    (T F)
   )
 )
 ((eq (car F) '*)
   (cond
    ((eq (cadr F) 0) 0)
    ((eq (caddr F) 0) 0)
    ((eq (cadr F) 1) (caddr F))
    ((eq (caddr F) 1) (cadr F))
    (T F)
   )
 )
)
)
SIMPLIFY1
CG-USER(20): (simplify1 '(+ X 3))
(+ X 3)
CG-USER(21): (simplify1 '(* x 4))
(* X 4)
CG-USER(22): (simplify1 '(+ 0 x))
X
CG-USER(23): (simplify1 '(* 0 k))
0
CG-USER(24): (simplify1 '(* 1
                           k))
K
CG-USER(25): (defun simplify (F)
 (if (atom F)
   F
   (simplify1 (list (car F)
                    (simplify (cadr F))
                    (simplify (caddr F))
              )
    )
 )
)




SIMPLIFY
CG-USER(26): 
CG-USER(26): (simplify '(* (+ 3 x) (+ 4 x)))
Error: attempt to call `CADRF' which is an undefined function.
[condition type: UNDEFINED-FUNCTION]
CG-USER(27): (defun simplify (F)
 (if (atom F)
   F
   (simplify1 (list (car F)
                    (simplify (cadr F))
                    (simplify (caddr F))
              )
    )
 )
)
SIMPLIFY
CG-USER(28): (simplify '(* (+ 3 x) (+ 4 x)))
(* (+ 3 X) (+ 4 X))
CG-USER(29(simplify '(* (+ 3 x) (+ 4 x)))
(* (+ 3 X) (+ 4 X))
CG-USER(30): (simplify '(* (+ 3 x) (+ 0 x)))
(* (+ 3 X) X)
CG-USER(31): (simplify '(* (+ 1 x) (+ 0 x)))
(* (+ 1 X) X)
CG-USER(32): (simplify '(* (+ 1 x) (+ 1 x)))
(* (+ 1 X) (+ 1 X))
CG-USER(33): 