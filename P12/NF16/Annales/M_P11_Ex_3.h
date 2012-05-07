#ifndef TP3_H
#define TP3_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Note{
	char* matiere;
	float note;
	struct Notes* suivant;
} Notes;

typedef Notes* ListeNotes;

typedef struct Etudiant{
	int id;
	ListeNotes L;
	int nbEpreuves;
	struct Etudiant suivant;
} Etudiant;

typedef Etudiant* ListeEtud;

ListeEtud nouvListeNotes();
ListeEtud nouvListeEtud();
Note nouvNote(char[50] mat, float note);
Etudiant nouvEtudiant(int id);


#endif