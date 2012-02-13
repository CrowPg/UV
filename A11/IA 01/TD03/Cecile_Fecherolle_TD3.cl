;;; 1. Boucles

(setq ll '(A 1 BB CCC 3 DDD 4))

(defun aff1 (liste) (dolist (e liste) (print e)))

(defun aff2 (liste) (format t "~{~a~^, ~}" liste))

(defun aff3 (liste)
  (cond ((atom liste))
        (t (print (car liste))
           (aff3 (cdr liste)))))

(defun aff4 (liste) (mapcar #'print liste))

(defun aff5 (liste) (dotimes (e (length liste)) (print (nth e liste))))


;;; 2.1 Représentation HTML

(setq l '(html
          (header
           (title "ma page" )
           )
          (body
           (h1 "un titre")
           (p "soror et aemula romae")
          )
         )
      )

;;; 2.2 Manipulation de la représentation

 (defun make-html (l) 
                (if (listp l)
                       (progn (print (concatenate 'string "<" (string (car l)) ">"))
                                            (dolist (e (cdr l))
                                                 (make-html e)
                                            )
                         
                         (print (concatenate 'string "</" (string (car l)) ">"))
                        )        
                        (print (string l))
                )
                )

;;; 2.3 Utilisation des fichiers

