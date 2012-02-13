;; pour une première utilisation, évaluer toutes les lignes ci-dessus
;; pour recommencer une recherche, évaluer les trois dernières lignes
;; (remise à 0 des faits et règles appliquées)


(defvar *bf* NIL)

(defvar *br* NIL)

(defvar *règles-appliquées* NIL)

(defvar *propriétés-a-ne-pas-demander* NIL)

(defvar *planètes* NIL)

(setq *planètes* '(Venus Mercure Terre Mars Jupiter Saturne Uranus Neptune))

(setq *propriétés-a-ne-pas-demander* '(tellurique gazeuse TMaUN JU TMa UN VT MeMa TMaJ
                                                    JS VMa JUN JN SU))

(defun prémisses (règle)
  (cadr règle)
  )

(defun conclusion (règle)
  (caddr règle)
  )

(defun presque (donnee valeur)
		(and
			(< donnee (* 1.30 valeur))
			(> donnee (* 0.70 valeur))
		)
  )




(setq *br* 
      '( 
        
        (R1

      ((<= distance-soleil<km> 448794000))

      ((tellurique T))

) 

(R2

      ((> distance-soleil<km> 448794000))

      ((gazeuse T))

) 

(R3

      ((>= densite 3.5) (<= densite 5.5))

      ((tellurique T))

) 

(R4

      ((<= densite 1.2) (>= densite 0.8))

      ((gazeuse T))

) 

(R5

      ((presque période-de-rotation<jours> 0.85))

      ((TMaUN T))

) 

(R6

      ((eq TMaUN T) (eq tellurique T))

      ((TMa T))

) 

(R7

      ((eq TMaUN T) (eq gazeuse T))

      ((UN T))

) 

(R8

      ((presque période-de-rotation<jours> 0.55))

      ((gazeuse T))

) 

(R9

      ((presque période-de-rotation<jours> 200))

      ((Venus T))

) 

(R10

      ((presque période-de-rotation<jours> 60))

      ((Mercure T))

) 

(R11

      ((presque rayon<km> 6000))

      ((VT T))

) 

(R12

      ((eq VT T) (eq TMaUN T))

      ((Terre T))

) 

(R13

      ((eq VT T) (eq TMa T))

      ((Terre T))

) 

(R14

      ((presque rayon<km> 2750))

      ((MeMa T))

) 

(R15

      ((eq MeMa T) (eq TMaUN T))

      ((Mars T))

) 

(R16

      ((eq MeMa T) (eq TMa T))

      ((Mars T))

) 

(R17

      ((presque rayon<km> 25000))

      ((UN T))

) 
 
(R19

      ((presque rayon<km> 70000))

      ((JS T))

) 
 
(R22

      ((> K<%> 30) (<= K<%> 80))

      ((Mercure T))

) 

(R23

      ((> Na<%> 30) (<= Na<%> 80)) 
 
      ((Mercure T))

) 

(R24

      ((> O<%> 2) (<= O<%> 10))
      ((Mercure T))

) 

(R25

      ((> Ar<%> 0.01) (<= Ar<%> 2)) 
      ((TMa T))

) 

(R26

      ((> Ar<%> 0) (<= Ar<%> 0.01)) 
      ((Venus T))

) 

(R27

      ((> Ar<%> 2) (<= Ar<%> 10)) 

      ((Mercure T))

) 

(R28

      ((> H2O<%> 2) (<= H2O<%> 10))

      ((Mercure T))

) 

(R29

      ((> H20<%> 0.01) (<= H20<%> 2))

      ((TMaJ T))

) 

(R30

      ((eq TMaJ T)(eq gazeuse T))

      ((Jupiter T))

) 

(R31

      ((eq TMaJ T)(eq TMaUN T))

      ((TMa T))

) 

(R32

      ((eq TMaJ T)(eq JS T))

      ((Jupiter T))

) 

(R33

      ((eq TMaJ T)(eq tellurique T))

      ((TMa T))

) 

(R34

      ((> H2<%> 2) (<= H2<%> 10)) 

      ((Mercure T))

) 

(R35

      ((eq H2<%> 0))

      ((Venus T))

) 

(R36

      ((> H2<%> 0) (<= H2<%> 0.01))
      ((TMa T))

) 

(R37

      ((> H2<%> 80)) 

      ((gazeuse T))

) 

(R38

      ((> O2<%> 10) (<= O2<%> 30))

      ((Terre T))

) 

(R39

      ((> O2<%> 2) (<= O2<%> 10)) 

      ((Mercure T))

) 

(R40

      ((> O2<%> 0.01) (<= O2<%> 2))

      ((Mars T))

) 

(R41

      ((> N<%> 2) (<= N<%> 10))
      ((Mercure T))

) 

(R42

      ((> CO2<%> 2) (<= CO2<%> 10)) 

      ((Mercure T))

) 

(R43

      ((> CO2<%> 80)) 

      ((VMa T))

) 

(R44

      ((eq VMa T)(eq TMaUN T))

      ((Mars T))

) 

(R45

      ((eq VMa T)(eq TMa T))

      ((Mars T))

) 

(R46

      ((eq VMa T)(eq VT T))

      ((Venus T))

) 

(R47

      ((eq VMa T)(eq MeMa T))

      ((Mars T))

) 

(R48

      ((eq VMa T)(eq TMaJ))

      ((Mars T))

) 

(R49

      ((> CO2<%> 0) (<= CO2<%> 0.01))
      ((Terre T))

) 

(R50

      ((> N2<%> 2) (<= N2<%> 10))
      ((VMa T))

) 

(R51

      ((> He<%> 0) (<= He<%> 0.01))
      ((VT T))

) 

(R52

      ((> He<%> 2) (<= He<%> 10))
      ((Saturne T))

) 

(R53

      ((> He<%> 10) (<= He<%> 30))
      ((JUN T))

) 

(R54

      ((eq JUN T)(eq TMaJ))

      ((Jupiter T))

) 

(R55

      ((eq JUN T)(eq JS T))

      ((Jupiter T))

) 

(R56

      ((> CH4<%> 0) (<= CH4<%> 0.01))
      ((TMa T))

) 

(R57

      ((> CH4<%> 0.01) (<= CH4<%> 2)) 
      ((JS T))

) 

(R58

      ((> CH4<%> 2) (<= CH4<%> 10)) 
      ((UN T))

) 

(R59

      ((eq ring-comp 2))

      ((SU T))

) 

(R60

      ((eq ring-comp 1))

 ((JN T)) 
 )

(R61

      ((eq SU T)(eq UN T))

      ((Uranus T))

) 

(R62

      ((eq SU T)(eq JUN T))

      ((Uranus T))

) 

(R63

      ((eq SU T)(eq JS T))

      ((Saturne T))

) 

(R64

      ((eq JN T)(eq UN T))

      ((Neptune T))

) 

(R65

      ((eq JN T)(eq TMaJ))

      ((Jupiter T))

) 

(R66

      ((eq JN T)(eq JS T))

      ((Jupiter T))

)


))



(defun règles-applicables (BF)
  (let ((liste NIL))
    (dolist (R *br*)
      (let ((prém (prémisses R))
            (OK T))
        (setq OK T)
        (dolist (pré prém)
          (let ((valeur (cadr (assoc (cadr pré) *BF*))))
            (unless (and
                     (not (null valeur))
                     (not (eq 'ne-sait-pas valeur))
                     (funcall (car pré) valeur (caddr pré))
                     )
               
               (setq OK NIL)
              )
            )) ;; fin dolist
        (if (and OK
                 (not (member (car R) *règles-appliquées*))
            )
            (setq liste (append liste (list R)))
              
          )
        ))
    liste
    ))



    
         
  
(defun choix-règle (liste-règles)
  
  (pop liste-règles)
  )

(defun but-atteint (BF)
  (dolist (planète *planètes*)
    (if (eq (cadr (assoc planète *bf*))
             T)
        (return planète)
      )
    )
  )


(defun appartient-BF (fait)
  (assoc fait *bf*)
  )


(defun recherche (BF)
  
  (format T "On cherche une planète à partir de ses caractéristiques :~%")
  
  (loop
    (cond
     ( (but-atteint BF) 
      (format T "Fin de la recherche ! La planète cherchée est ~a." (but-atteint BF))
      (return-from NIL)
      )
     
          
     
     ( (null (règles-applicables BF))
      (format T "Pas de règles à appliquer ~%")
      (if (null (ask-user *bf*))
          (progn
            (format T "Fin de la recherche, pas de résultat possible.~%")
            (return-from NIL)
            )
        )
      )
     
     (T
      (let ((règles-candidates NIL) (règle-choisie NIL))
         (setq règles-candidates (règles-applicables BF))
         (setq règle-choisie (choix-règle règles-candidates))
        (format T "On applique la règle ~a ~%" (car règle-choisie))
        
        (setq *bf* (appliquer-règle règle-choisie))
        (format T "Conclusion : ~s ~%" (conclusion règle-choisie))
        (setq *règles-appliquées* (append *règles-appliquées* (list (car règle-choisie))))
        (mettre-a-jour-br)
         
         )
      )
     )
    )
  (format T "Pour faire une nouvelle recherche, réévaluer les trois dernières lignes du code.")
  )


(defun mettre-a-jour-br ()
  (cond
	((equal (assoc 'tellurique *bf*) '(tellurique T))
		
	(dolist (x '(R1 R2 R3 R4 R7 R8 R16 R19 R30 R32 R37 R52 R53 R54 R55 R57 R58 R59 R60 R61 R62 R63 R64 R65 R66))

		(pushnew x *règles-appliquées*))
	))
	((equal (assoc 'gazeuse *bf*) '(gazeuse T))
		
	(dolist (x '(R1 R2 R3 R4 R6 R8 R9 R10 R11 R12 R13 R14 R15 R16 R22 R23 R24 R25 R26 R27 R28 R31 R33 R34 
			R35 R36 R37 R38 R39 R40 R41 R42 R43 R44 R45 R46 R47 R48 R49 R50 R51 R56))
			
		(pushnew x *règles-appliquées*))
	
	))
	((equal (assoc 'TmaUN *bf*) '(TMaUN T))
		
	(dolist (x '(R9 R10 R19 R22 R23 R24 R26 R27 R28 R30 R34 R35 R39 R41 R42 R46 R52 R57 R63 R65 R66))
			
		(pushnew x *règles-appliquées*))
		
	))
        ((equal (assoc 'Tma *bf*) '(TMa T))
		
	(dolist (x '(R1 R2 R3 R4 R5 R6 R7 R8 R9 R10 R17 R19 R22 R23 R24 R25 R26 R27 R28 R29 R30 
			R31 R32 R33 R34 R35 R36 R37 R39 R41 R42 R46 R52 R53 R54 R55 R56 R57 R58 
			R59 R60 R61 R62 R63 R64 R65 R66))
	
		(pushnew x *règles-appliquées*))
		
	))
	((equal (assoc 'UN *bf*) '(UN T))
		
	(dolist (x '(R1 R2 R3 R4 R5 R6 R7 R8 R9 R10 R11 R12 R13 R14 R15 R16 R17 R19 R22 R23 R24 R25 
			R26 R27 R28 R29 R30 R31 R32 R33 R34 R35 R36 R37 R38 R39 R40 R41 R42 R43 R44 
			R45 R46 R47 R48 R49 R50 R51 R52 R53 R54 R55 R56 R57 R58 R63 R65 R66))
	
		(pushnew x *règles-appliquées*))
		
	))


	((equal (assoc 'VT *bf*) '(VT T))
		(dolist (x '(R1 R2 R3 R4 R7 R8 R10 R11 R14 R15 R16 R17 R19 R22 R23 R24 R27 R28 R30 R32 R34 R37
			 R39 R40 R41 R42 R44 R45 R47 R48 R51 R52 R53 R54 R55 R57 R58 R59 R60 R61 R62 
			R63 R64 R65 R66))
			
		(pushnew x *règles-appliquées*))
		
	))
        ((equal (assoc 'JS *bf*) '(JS T))
		
	(dolist (x '(R1 R2 R3 R4 R5 R6 R7 R8 R9 R10 R11 R12 R13 R14 R15 R16 R17 R19 R22 R23 R24 R25 R26 
			R27 R28 R31 R33 R34 R35 R36 R37 R38 R39 R40 R41 R42 R43 R44 R45 R46 R47 R48 R49 
			R50 R51 R56 R57 R58 R61 R62 R64))
			
		(pushnew x *règles-appliquées*))
		
	))

	
	((equal (assoc 'TMaJ *bf*) '(TMaJ T))
		
	(dolist (x '(R7 R9 R10 R17 R22 R23 R24 R26 R27 R28 R29 R34 R35 R39 R41 R42 R46 R52 R58 R59 R61 R62 R63 R64))
			
		(pushnew x *règles-appliquées*))
		
	)
)
	

	((equal (assoc 'VMa *bf*) '(VMa T))
		(dolist (x '(R1 R2 R3 R4 R7 R8 R10 R11 R12 R13 R17 R19 R22 R23 R24 R27 R28 R30 R32 R34 R37 R38 R39 R40 R41 R42
			 R43 R49 R50 R52 R53 R54 R55 R57 R58 R59 R60 R61 R62 R63 R64 R65 R66))
		
		(pushnew x *règles-appliquées*)
		
	)
)
	

	((equal (assoc 'JUN *bf*) '(JUN T))
		
	(dolist (x '(R1 R2 R3 R4 R6 R8 R9 R10 R11 R12 R13 R14 R15 R16 R22 R23 R24 R25 R26 R27 R28 R31 R33 R34 R35 R36 
			R37 R38 R39 R40 R41 R42 R43 R44 R45 R46 R47 R48 R49 R50 R51 R52 R56 R63))
			
		(pushnew x *règles-appliquées*)
		
	))
	

	((equal (assoc 'SU *bf*) '(SU T))
	
	(dolist (x '(R1 R2 R3 R4 R5 R6 R8 R9 R10 R11 R12 R13 R14 R15 R16 R22 R23 R24 R25 R26 R27 R28 R29 R30 R31 R32 
			R33 R34 R35 R36 R37 R38 R39 R40 R41 R42 R43 R44 R45 R46 R47 R48 R49 R50 R51 R52 R53 R54 R55 R56 
			R57 R58 R63 R65 R66))
			
			(pushnew x *règles-appliquées*)
		
	)
)
	

	((equal (assoc 'JN *bf*) '(JN T))
		
	(dolist (x '(R1 R2 R3 R4 R5 R6 R8 R9 R10 R11 R12 R13 R14 R15 R16 R22 R23 R24 R25 R26 R27 R28 R31 R33 R34 R35 R36 R37 
			R38 R39 R40 R41 R42 R43 R44 R45 R46 R47 R48 R49 R50 R51 R52 R53 R56 R59 R60 R61 R62 R63))
	
			(pushnew x *règles-appliquées*)
	
	)
)
))


(defun ask-user (BF)
  
  (dolist (R *br*)
    ;; on parcourt la base de règles
    
    (let ((prémisses (prémisses R))
          (fin NIL))
      (if (not (or (appartient-BF (car (car (conclusion R))))
                    (member (car R) *règles-appliquées*)))
          ;; si le fait sur lequel cette règle conclut n'est pas déjà dans la base de fait
          ;; ou si la règle n'est pas déjà appliquée
        ;; alors ça vaut le coup de chercher, sinon, pas la peine
          (progn 
            
      ;; on utilise une variable fin pour savoir ce que le dolist a renvoyé
      ;; dès qu'elle vaut T, on s'arrête
       
            (setq fin (dolist (pré prémisses)
                        ;; on parcourt toutes les prémisses de la règle
                  (let ((fait (assoc (cadr pré) BF))
                        (valeur NIL))
                    ;; variables locales fait et valeur
                    (if (and (null fait)
                             (null (member (cadr pré) *propriétés-a-ne-pas-demander*) )
                          )
                        
                        ;; si le fait n'appartient pas à la base de faits
                        ;; et n'appartient pas aux propriétés à ne pas demander
                        ;; (ex tellurique, TMa, JUN ...)
              (progn
                (format T "Entrez une valeur pour ~a (ou ne-sait-pas)" (cadr pré))
                (setq valeur (read))
                (setq *bf* (ajout (list (cadr pré) valeur) *bf*))
                ;; on met le fait dans la base de faits
                (return T)
                ;; on arrête la boucle, fin vaut T
                )
            )
          )
                  )
          ))) ;; fin setq
      (if fin ;; si fin vaut T, on sort du premier dolist aussi
          (return T)) ;; fin if
      ))
  )
      
            
(defun ajout (fait BF)
  (push fait BF)
  )

(defun appliquer-règle (règle)
  (dolist (fait (conclusion règle))
    (if (null (appartient-BF fait))
        (push fait *bf*)
      )
    )
  *bf*
    )
  

      

(setq *bf* NIL)
(setq *règles-appliquées* NIL)
(recherche *bf*)
