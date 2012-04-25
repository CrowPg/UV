typedef struct noeud{
	int val;
	struct noeud* gauche;
	struct noeud* droite;
}noeud;

typedef noeud* arbre;

int max_abr(arbre A){
	if (A->droite!=NULL)
		return max_abr(A->droie);
	else
		return A->val;
}

int min_abr(arbre A){
	while (A->gauche!=NULL){
		A=A->gauche;
	}
	return A->val;
}