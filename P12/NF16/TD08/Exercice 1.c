/*Rappels sur les ABR

Arbre représenté par le noeud racine
Chaque noeud a deux fils :
	à droite : supérieur
	à gauche : inférieur
	ou NIL
	
Cf. dessin

recherche(arbre, cle)
	si (cle(arbre)=cle ou arbre=NIL)
		retourne arbre
	fin si
	si (cle<cle(arbre))
		retourne recherche(gauche(arbre))
	sinon
		retourne recherche(droit(arbre))
	fin si

recherche_iter(x:noeud, cle:entier)
	tant que (cle(x)!=cle et x!=NIL)
		si (cle<cle(x))
			x<-gauche(x)
		sinon
			x<-droite(x)
		fin si
	fin tant que
	retourne x

minimum(x:Arbre) // on va toujours à gauche
	tant que (gauche(x)!=NIL)
		x<-gauche(x)
	fin tant que
	retourne x
	
maximum(x:Arbre) // on va toujours à droite
	tant que (droite(x)!=NIL)
		x<-droite(x)
	fin tant que
	retourne x
	
successeur(x:Noeud)
	si (droit(x)!=NIL) // s'il y a des trucs à droite, donc
		alors retourne minimum(droit(x))
	sinon
		y<-pere(x)
		tant que (y!=NIL et x=droit(y))
			x<-y
			y<-pere(x)
		fin tant que
	fin si
	retourne y
	
inserer (T:arbre, z:noeud)
	x<-racine(T)
	y<-NIL
	tant que (x!=NIL)
		y<-x
		si cle(z)<cle(x) alors x<-gauche(x)
		sinon x=droite(x) fin si
	fin tant que
	pere(z)<-y
	si(y=NIL) alors racine(T)<-z
	sinon si (cle(z)<cle(y)) alors gauche(y)<-z
	sinon droit(z)<-z

supprimer (x:Noeud)
	si (droite(x)=NIL et gauche(x)=NIL)
		y<-pere(x)
		si x=gauche(y) alors 
			gauche(y)<-NIL
		sinon 
			droite(y)<-NIL
		fin si
	sinon si (droite(x)=NIL ou gauche(x)=NIL)
		si (droite(x)!=NIL) alors 
			z<-droite(x)
		sinon 
			z<-gauche(x)
		fin si
		y<-pere(x)
		pere(z)<-y
		si (x=gauche(y) alors 
			gauche(y)<-z
		sinon 
			droite(y)<-z
		fin si
	sinon
		y<-successeur(x)
		cle(x)<-cle(y)
		x<-y
	fin si
	libérer x
		
*/