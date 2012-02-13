;;; This is the IDE's built-in-editor, where you create and edit
;;; lisp source code.  You could use some other editor instead,
;;; though the IDE's menu-bar commands would not be applicable there.
;;; 
;;; This editor has a tab for each file that it's editing.  You can
;;; create a new editor buffer at any time with the File | New command.
;;; Other commands such as Search | Find Definitions will create
;;; editor buffers automatically for existing code.
;;; 
;;; You can use the File | Compile and Load command to compile and
;;; load an entire file, or compile an individual definition by
;;; placing the text cursor inside it and using Tools | Incremental
;;; Compile.  You can similarly evaluate test expressions in the
;;; editor by using Tools | Incremental Evaluation; the returned
;;; values and any printed output will appear in a lisp listener
;;; in the Debug Window.
;;; 
;;; For a brief introduction to other IDE tools, try the
;;; Help | Interactive IDE Intro command.  And be sure to explore
;;; the other facilities on the Help menu.

(setq BaseTest '((dupont pierre lyon 45 150)
			     (dupont marie nice 32 200)
                             (dupont jacques lyon 69 20)
                             (perrot jacques geneve 28 500)
                             (perrot jean nice 55 60)
                             (perrot anna grenoble 19 180)
                )
)

(defun nom (personne)
               (car personne))

(defun prenom (personne)
               (second personne))


(defun ville (personne)
  (third personne))

(defun age (personne)
  (fourth personne))

(defun livres (personne)
  (fifth personne))

(defun F1 (base)               (dolist (i base)                 (print i)))(defun F2 (base)               (dolist (i base)                 (if (eq (first i) 'Perrot)                     (print i)                   )))(defun F3 (base)               (dolist (i base)                 (if (eq (third i) 'Lyon)                     (print i)                   )))(defun F4 (base nom)               (dolist (i base)                 (if (eq (first i) nom)                     (print i))))(defun F5 (base X)(dolist (i base)(if (eq X (age i))(return i))))(defun F6 (base)(dolist (i base)(if (> 100 (livres i))(return i))))(defun F7 (base)(dolist (i base)(if (and (eq 'Lyon (ville i)) (< 50 (age i)))(return i))))(defun F8 (base)               (let ((somme 0))                 (dolist (i base)                   (setf somme (+ somme (fifth i)))                   )                 somme                 )  )(defun F9 (base)               (let ((somme 0))                 (dolist (i base)                   (when (eq 'Lyon (third i))(setf somme (+ somme (fifth i))))                  )                 somme                 )  )(defun F10 (base nom)               (let ((somme 0))                 (dolist (i base)                   (if (eq nom (first i))                       (setf somme (+ somme (fifth i)))                     )                   )                 somme                 )  )(defun F11 (base)               (let ((nombre 0.0)                     (total 0.0))                 (dolist (i base)                   (setf total (+ total (fourth i)))                   (setf nombre (+ nombre 1))                   )                 (/ total nombre)                 )  )(defun F12 (base nom)               (let ((nombre 0.0)                     (total 0.0))                 (dolist (i base)                   (when (eq nom (first i))                     (setf total (+ total (fourth i)))                     (setf nombre (+ nombre 1))                     )                   )                 (if (= 0 nombre)                     NIL                   (/ total nombre))                 )  )(defun F13 (base)                (setf copie13 (list NIL))                (dolist (i base)                  (nconc copie13 (list i)))                  )  (setf copie13 (rest copie13)))(defun F14 (base)                (setf copie14 (list NIL))                (dolist (i base)                  (nconc copie14 (list (remove (fifth i) i)))                  )  (setf copie14 (rest copie14)))(defun F15 (base)                (setf copie15 (list NIL))                (dolist (i base)                  (if (eq 'Lyon (third i))                  (nconc copie15 (list i))                    )                  )  (setf copie15 (rest copie15)))(defun F16 (base)                (setf copie16 (list NIL))                (dolist (i base)                  (if (not (eq 'Nice (third i)))                  (nconc copie16 (list i))                    )                  )  (setf copie16 (rest copie16)))(defun F18 (base nom ville)               (dolist (i base)                 (when (and (eq (first i) nom) (eq (third i) ville)                     (print i)))))
  
