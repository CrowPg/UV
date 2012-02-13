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

(setq etat-initial '(0 0 0 1 0 1))

(setq oldstates '( (0 0 0 1 0 1) ))

(setq compteur '(0 1 2 3 4))

(setq etat-final '(1 1 1 1 1 1))

(defun newstate (etat pos)
              (let ((copie ()))

                (setf copie (copy-list etat))


                (if (= 0 (nth pos copie))
                    (setf (nth pos copie) 1)
                    (setf (nth pos copie) 0)
                  )
                (if (= 0 (nth (+ 1 pos) copie))
                    (setf (nth (+ 1 pos) copie) 1)
                    (setf (nth (+ 1 pos) copie) 0)
                  )

                copie
                )
 )
(defun successors (state)
              (let ((liste '(O)))
                (setf liste (copy-list '(0)))
                (dolist (i compteur)
                  (nconc liste (list (newstate state i)))
                  )
                (rest liste))
  )

(defun appartient (sous-liste liste)
               (dolist (i liste)
                 (if (equal i sous-liste)
                     (return T)
                   )
                 )
 )
(defun getnewstate (state)
               (dolist (i (successors state))
                 (if (not (appartient i oldstates))
                     (return i)
                   )
                 )
 )


(defun explore-prof (state)
                
                (cond
                  ( (null state)
                    (print "échec")
                   )
                 
                 ( (equal '(1 1 1 1 1 1) state)
                   (print state)
                   (print "succès ! :) ")
                  )
                 
                 ( (eq NIL (getnewstate state)) 
                   (nconc oldstates (list state))
                   (explore-prof (backtrack state))
                  )
                 
                 ( T 
                  (nconc oldstates (list state))
                  (print state)
                  (explore-prof (getnewstate state))
                  )
                 )
  )
(defun backtrack (state)
                (let ((candidats '(0)))
                  (setf candidats (reverse oldstates))




                  (dolist (i candidats)
                   
                    (if (not (eq NIL (getnewstate i))) 
                       
                        (return i)
                      ) 
                    )
                  )
                )

(defun explore-breadth (state)
  
   (let ((f '())(gagne nil))
     (push state oldstates)
     
     
     (setq f (append f (list state))) 
        (loop 
          (if (or gagne (null f)) 
              (return nil)
              (progn 
                (let ((x (pop f)))
                 
                  
                  (dolist (succ (successors x)) 
                    
                    (if (equal succ '(1 1 1 1 1 1)) 
                        (progn 
                          (print succ)
                          (setq gagne T)
                          )
                      
                      (if (not (appartient succ oldstates)) 
                          
                          (progn 
                            (print succ) 
                            (push succ oldstates)
                            (setq f (append f (list succ)))
                            )
                        )
                      )
                    )
                  )
                )
            )
          )
     )
  )

(defun proximite (state final)
             (let ((count 0) (pos 0))
               (dolist (i state)
                 (if (= i (nth pos final))
                     (setq count (+ 1 count))
                   )

                 (setq pos (+ 1 pos))
                 )


               count
               )
             )
(defun explore-prof-bis (state)

               (cond
                 ( (null state)
                   (print "échec")
                  )

                ( (equal etat-final state)
                  (print state)
                  (print "succès ! :) ")
                 )

                ( (eq NIL (getnewstate-bis state))
                 
                  (nconc oldstates (list state))
                  (explore-prof-bis (backtrack-bis state))
                 )

                ( T 
                 (nconc oldstates (list state))
                 (print state)
                 (explore-prof-bis (getnewstate-bis state))
                 )
                )
 )
                 
                 defun backtrack-bis (state)
               (let ((candidats '(0)))
                 (setf candidats (reverse oldstates))

                 (dolist (i candidats)
                   
                   (if (not (eq NIL (getnewstate-bis i)))
                       
                       (return i)
                     ) 
                   )
                 )
               )
(defun getnewstate-bis (state)
              (let ((plus-proche '(0 0 0 0 0 0)))
               (dolist (i (successors state))
                 (if (and (not (appartient i oldstates)) (>
(proximite i etat-final) (proximite plus-proche etat-final)))
                     (setq plus-proche i)
                   )
                 )
                plus-proche)
 )
