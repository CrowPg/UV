#include "M_P11_Ex_3.h"

void nouvListeNotes(){
	ListeNotes sent = malloc(sizeof(Note));
	sent->suivant=sent;
}

void nouvListeEtud(){
	ListeEtud sent = malloc(sizeof(Etudiant));
	sent->suivant=sent;
}

void nouvNote(char[50] mat, float note){
	Note n=malloc(sizeof(Note));
	n->matiere=mat;
	n->note=note;
}

void nouvEtudiant(int id){
	Etudiant e=malloc(sizeof(Etudiant));
	e->id=id;
	e->L=nouvListeNotes();
	e->nbEpreuves=0;
}

ListeNotes ajoutNote(ListeNotes ln, char[50] mat, float note){
	Note n=nouvNote(mat, note);
	ListeNotes temp=ln;
	temp=temp->suivant;
	ln->suivant=n;
	n->suivant=temp;
	return ln;
}

Etudiant ajoutEtud(ListeEtud let, int id){
	Etudiant e=nouvEtudiant(id);
	ListeEtud temp=let;
	temp=temp->suivant;
	let->suivant=e;
	e->suivant=temp;
	return e;
}
	
ListeEtud ajout(listeEtud let, int id, char[50] mat, float note){
	ListeEtud temp=let;
	while (temp->suivant != let){
		temp=temp->suivant;
		if (temp->id == id){
			ajoutNote(temp->L, mat, note);
			temp->nbEpreuves++;
			return let;
		}
	}
	Etudiant e = ajoutEtud(let, int id);
	ajoutNote(e->L, mat, note);
	e->nbEpreuves++;
	return let;
}

void subGroup(ListeEtud let, ListeEtud let1, ListeEtud let2, ListeEtud let3, char[50] mat){
	let1 = nouvListeEtud();
	let2 = nouvListeEtud();
	let3 = nouvListeEtud();
	ListeEtud temp=let;
	while (temp->suivant != let){
		temp=temp->suivant;
		ListeNotes ntemp = temp->L;
		float moy=0;
		int absent=1;
		int nbEpMat=0
		while (ntemp->suivant != temp->L){
			ntemp=ntemp->suivant;
			if (ntemp->mat == mat){
				moy+=ntemp->note;
				nbEpMat++;
			}
		}
		if (nbEpMat==0){
			ajoutEtud(let3, temp->id);
		}
		else{
			moy/=nbEpMat;
			if (moy<10){
				ajoutEtud(let2, temp->id);
			}
			else{
				ajoutEtud(let1, temp->id);
			}
		}
	}
}

float calcMoy(Etudiant* e){
	ListeNote temp=e->L;
	float moy=0;
	while(temp->suivant != e->L){
		temp=temp->suivant;
		moy+=temp->note;
	}
	moy/=e->nbEpreuves;
	return moy;
}
		
	
void classement(listeEtud let){
	ListeEtud temp=let;
	while (temp->suivant != let){
		
		
		