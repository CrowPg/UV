Exercice 5

int calcul(char* exp){
	Pile * p; // exercice précédent pour déf de Pile 
	p=creer_pile(50); // exercice précédent pour déf d
	int nb=0; // pour récupérer les nombres de l'expression et effectuer les calculs
	int i=0;
	for (i=O; exp[i] !='\0'; i++){ // ou for ( ; *exp!='\0' ; exp++)
		if (exp[i] >='0' && exp[i] <= '9'){
			nb=0;
			while(exp[i] >='0' && exp[i] <= '9'){
				nb*=10;
				nb+=exp[i]-'0';
				i++;
			}
			empiler(p, nb);
		}
		else if(exp[i]!=' '){ // Hyp : si ce n'est pas une espace, c'est un opérateur
			{
				int op1, op2;
				op1=depiler(p);
				op2=depiler(p);
				empiler(p,calcul(op1, op2, exp[i])); // calcul fait un switch sur le caractère courant pour déterminer quelle opération il faut efféctuer et l'effectue (retour : résultat !)
			}
		}
	}
	nb=depiler(p);
	free_pile(p);
	return nb;
}	