International Allegro CL Free Express Edition
8.2 [Mac OS X (Intel)] (Oct 2, 2011 23:00)
Copyright (C) 1985-2010, Franz Inc., Oakland, CA, USA.  All Rights Reserved.

This development copy of Allegro CL is licensed to:
   Allegro CL 8.2 Express user

CG version 1.134 / IDE version 1.125
Loaded options from /Users/johan/.allegro-prefs-8-2-express.cl.

;; Optimization settings: safety 1, space 1, speed 1, debug 2.
;; For a complete description of all compiler switches given the current optimization settings evaluate
;; (EXPLAIN-COMPILER-SETTINGS).

[changing package from "COMMON-LISP-USER" to "COMMON-GRAPHICS-USER"]


CG-USER(3): (defun f3 (ll)
(dotimes ( i (length ll))
  (print (nth i ll))
)
)
F3


CG-USER(6): (defun f5 (ll)
(loop for i in ll
  do (print i))
)
F5
CG-USER(7): (defun f6 (ll)
(loop
  (unless ll (return from nil "done"))
  (print (pop ll))
)
)
F6
CG-USER(8): (setq ll '( A 1 BB 2 CCC 3 DDDD 4))
(A 1 BB 2 CCC 3 DDDD 4)

CG-USER(13):(defun f1 (ll)
(dolist (x ll)
  (print x)
)
)
F1
CG-USER(14): (f1 ll)

A 
1 
BB 
2 
CCC 
3 
DDDD 
4 
NIL


CG-USER(17):(defun f2 (ll)
(mapcar print ll)
)
F2
CG-USER(18): (f2 ll)
Error: Attempt to take the value of the unbound variable `PRINT'.
[condition type: UNBOUND-VARIABLE]
CG-USER(19): (f3 ll)

A 
1 
BB 
2 
CCC 
3 
DDDD 
4 
NIL
CG-USER(20): (f4 ll)

A 
A
CG-USER(21): (defun f4 (ll)
(cond
  ((null ll) nil)
  (T (print (car ll))
  (f4 (cdr ll))
)
)
)
F4
CG-USER(22): (f4 ll)

A 
1 
BB 
2 
CCC 
3 
DDDD 
4 
NIL
CG-USER(23): (f5 ll)

A 
1 
BB 
2 
CCC 
3 
DDDD 
4 
NIL
CG-USER(24): (f6 ll)

A 
1 
BB 
2 
CCC 
3 
DDDD 
4 
Error: Attempt to take the value of the unbound variable `FROM'.
[condition type: UNBOUND-VARIABLE]
CG-USER(25): 