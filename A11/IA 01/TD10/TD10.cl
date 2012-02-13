(defclass $dot ($figure)
(($x :accessor abscisse :initarg :abscisse :type real)
 ($y :accessor ordonnee :initarg :ordonnee :type real)
)
)

(defclass $cercle ($figure)
(($centre :accessor centre :initarg :centre :type $dot)
 ($rayon :accessor rayon :initarg :rayon :type real)
)
)

(defclass $triangle ($figure)
(($M1 :accessor M1 :initarg :M1 :type $dot)
 ($M2 :accessor M2 :initarg :M2 :type $dot)
 ($M3 :accessor M3 :initarg :M3 :type $dot)
)
)

(defclass $poly ($figure)
(($listeSommets :accessor listeSommets :initarg :listeSommets :type list)
)
)

(defclass $rectangle  ($figure)
(($sommetG :accessor sommetG :initarg :sommetG :type $dot)
 ($hauteur :accessor hauteur :initarg :hauteur :type real)
 ($largeur :accessor largeur :initarg :largeur :type real)
)
)

(defclass $carre  ($figure)
(($sommetG :accessor sommetG :initarg :sommetG :type $dot)
 ($cote :accessor cote :initarg :cote :type real)
)
)

(defclass $figure ()
(($color :accessor color :initarg :color :type string)))


(defmethod translate ((xx $dot) dx dy)
(setf (abscisse xx) (+ dx (abscisse xx)))
(setf (ordonnee xx) (+ dy (ordonnee xx)))
xx
) 

(defmethod symx ((xx $dot))
(setf (ordonnee xx) (- 0 (ordonnee xx)))
xx
)

(defmethod symy ((xx $dot))
(setf (abscisse xx) (- 0 (abscisse xx)))
xx
)

(defmethod symO ((xx $dot))
(Symx P0)
(Symy P0)
xx
)

(defmethod zoom ((xx $dot) k)
  (setf (abscisse xx) (* k (abscisse xx)))
  (setf (ordonnee xx) (* k (ordonnee xx)))
  xx
  )

(defmethod translate ((tt $triangle) dx dy)
  (translate (M1 tt) dx dy)
  (translate (M2 tt) dx dy)
  (translate (M3 tt) dx dy)
  tt
  )

(defmethod symx ((tt $triangle))
(symx (M1 tt))
(symx (M2 tt))
(symx (M3 tt))
tt
)

(defmethod symy ((tt $triangle))
(symy (M1 tt))
(symy (M2 tt))
(symy (M3 tt))
tt
)

(defmethod symO ((tt $triangle))
(symO tt)
(symO tt)
tt
)

(defmethod zoom ((tt $triangle) k)
  (zoom (M1 tt))
  (zoom (M2 tt))
  (zoom (M3 tt))
  tt
  )

(defmethod translate ((cc $cercle) dx dy)
  (translate (centre cc) dx dy)
  cc
)

(defmethod symy ((cc $cercle))
  (symy (centre cc))
  cc
  )

(defmethod symx ((cc $cercle))
  (symx (centre cc))
  cc
  )

(defmethod symO ((cc $cercle))
  (symx (centre cc))
  (symy (centre cc))
  cc
  )

(defmethod zoom ((cc $cercle) k)
  (zoom (centre cc) k)
  (setf (rayon cc) (* (abs k) (rayon cc)))
  cc
  )

(defmethod translate ((cc $carre) dx dy)
  (translate (sommetG cc) dx dy)
  cc
  )

(defmethod symy ((cc $carre))
  (if (>= (abscisse (sommetG cc)) 0)
      (setf (abscisse (sommetG cc)) (- (cote cc) (abscisse cc)))
      (setf (abscisse (sommetG cc)) (+ (cote cc) (abscisse cc)))
   )
   cc
  )

(defmethod symx ((cc $carre))
  (if (>= (ordonnee (sommetG cc)) 0)
      (setf (ordonnee (sommetG cc)) (- (cote cc) (ordonnee cc)))
      (setf (ordonnee (sommetG cc)) (+ (cote cc) (ordonnee cc)))
   )
   cc
  )

(defmethod symO ((cc $carre))
  (symx cc)
  (symy cc)
  cc
  )

(defmethod zoom ((cc $carre) k)
  (zoom (sommetG cc) k)
  (setf (cote cc) (* (abs k) (cote cc)))
  cc
  )

(defmethod translate ((rr $rectangle) dx dy)
  (translate (sommetG rr) dx dy)
  rr)

(defmethod symy ((rr $rectangle))
  (if (>= (abscisse (sommetG rr)) 0)
      (setf (abscisse (sommetG rr)) (- (largeur rr) (abscisse rr)))
      (setf (abscisse (sommetG rr)) (+ (largeur rr) (abscisse rr)))
   )
   rr
  )

(defmethod symx ((rr $rectangle))
  (if (>= (ordonnee (sommetG rr)) 0)
      (setf (ordonnee (sommetG rr)) (- (hauteur rr) (ordonnee rr)))
      (setf (ordonnee (sommetG rr)) (+ (hauteur rr) (ordonnee rr)))
   )
   cc
  )

(defmethod symO ((rr $rectangle))
  (symx cc)
  (symy cc)
  cc
  )

(defmethod zoom ((rr $rectangle) k)
  (zoom (sommetG rr) k)
  (setf (hauteur rr) (* (abs k) (hauteur cc)))
  (setf (largeur rr) (* (abs k) (largeur cc)))
  rr
  )

(defmethod translate ((pp $poly) dx dy)
  (dolist (i (listeSommets))
    (translate i dx dy)
    )
  pp
)  

(defmethod symx ((pp $poly))
  (dolist (i (listeSommets))
    (symx i)
    )
  pp
)  

(defmethod symy ((pp $poly))
  (dolist (i (listeSommets))
    (symy i)
    )
  pp
)  

(defmethod symO ((pp $poly))
  (dolist (i (listeSommets))
    (symO i)
    )
  pp
)  

(defmethod zoom ((pp $poly) k)
  (dolist (i (listeSommets))
    (zoom i k)
    )
  pp
)  

(setq P0 (make-instance '$dot :abscisse 3 :ordonnee 4 :color "noir"))
(setq P1 (make-instance '$dot :abscisse 3 :ordonnee -4 :color "noir"))
(setq P2 (make-instance '$dot :abscisse -3 :ordonnee -4 :color "noir"))
(setq P3 (make-instance '$dot :abscisse -3 :ordonnee 4 :color "noir"))

(setq C0 (make-instance '$cercle :centre P0 :rayon 2 :color "pink"))
(setq C1 (make-instance '$cercle 
           :centre (make-instance '$dot :abscisse 0 :ordonnee 0 :color "pink" )
           :rayon 2
           )
    )

(setq T0 (make-instance '$triangle :M1 P1 :M2 P2 :M3 P3 :color "yellow"))

(setq Cr0 ((lengmake-instance '$carre :sommetG P0 :cote 4 :color "blue"))

(setq R0 (make-instance '$rectangle :sommetG P0 :hauteur 6 :largeur 2 :color "green"))

(setq Pl0 (make-instance '$poly :listeSommets '(P0 P1 P2 P3) :color "orange"))

(defmethod duplicate ((xx $dot) dx dy)
  (let ((copie 0))
    (setq copie (make-instance '$dot :abscisse (abscisse xx) :ordonnee (ordonnee xx)))
    (translate copie dx dy)
    )
  )

