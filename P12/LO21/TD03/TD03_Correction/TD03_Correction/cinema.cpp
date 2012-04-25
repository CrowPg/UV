#include "cinema.h"


std::ostream& operator<<(std::ostream& f, const Film& x){ x.Afficher(f); return f;}
std::ostream& operator<<(std::ostream& f, const Programmation& x){ x.Afficher(f); return f;}
std::ostream& operator<<(std::ostream& f, const Planning& x){ x.Afficher(f); return f;}
std::ostream& operator<<(std::ostream& f, const Salle& x){ x.Afficher(f); return f;}
std::ostream& operator<<(std::ostream& f, const Cinema& x){ x.Afficher(f); return f;}




void Film::Afficher(std::ostream& f) const {
	f<<titre<<" ("<<duree<<")";
}

void Programmation::Afficher(std::ostream& f) const{
	f<<inter<<" : "<<*film;
}

Planning::Planning(const Planning& p):
	progs(new Programmation[p.taille]),taille(p.taille),nbProgs(p.nbProgs){
	for(int i=0; i<nbProgs; i++) progs[i]=p.progs[i];
}
Planning& Planning::operator=(const Planning& p){
	if (this!=&p){
		delete[] progs;
		taille=p.taille;
		progs=new Programmation [taille];
		for(int i=0; i<nbProgs; i++) progs[i]=p.progs[i];
	}
	return *this;
}

bool Planning::operator<<(const Programmation& p){
	if (nbProgs<taille){
		int i=0;
		while(i<nbProgs){
			if (progs[i].GetReservation()&&p.GetReservation()) return false;
			if (progs[i].GetReservation().GetDebut()<p.GetReservation().GetDebut()) i++; else break;
		}
		int j=nbProgs;
		while (j>i) {
			progs[j]=progs[j-1];
			j--;
		}
		progs[i]=p;
		nbProgs++;
		return true;
	}
	return false;
}

void Planning::Afficher(std::ostream& f) const{
	for(int i=0; i<nbProgs; i++) f<<"- "<<progs[i]<<"\n";
}

Cinema::Cinema(const std::string n, int nb):
			nom(n),nbSalles(nb),salles(new Salle*[nb]){ 
	for(unsigned int i=0; i<nbSalles; i++) { salles[i]= new Salle(i+1); }
}

Cinema::~Cinema() { 
	for(unsigned int i=0; i<nbSalles; i++) delete salles[i];
	delete[] salles; 
}

Cinematheque::~Cinematheque(){
	for(unsigned int i=0; i<nb_films; i++) delete tab[i];
	delete[] tab;
}

Cinematheque* Cinematheque::instance=0; // un membre statique doit être initialisé pour être défini

Cinematheque& Cinematheque::GetInstance(){
	if (!instance) instance= new Cinematheque(10);
	return *instance;
}
void Cinematheque::LibereInstance(){
	if (!instance) delete instance;
}

void Cinematheque::AjouterFilm(const std::string& t, int d){
	if (nb_films==nb_max){
		Film** newtab = new Film* [nb_max+10];
		for(unsigned int i=0; i<nb_films; i++) newtab[i]=tab[i];
		nb_max+=10;
		delete[] tab;
		tab=newtab;
	}
	tab[nb_films]=new Film(t,d);
	nb_films++;
}

const Film& Cinematheque::GetFilm(const std::string& t) const{
	for(unsigned int i=0; i<nb_films; i++)
		if (tab[i]->GetTitre()==t) return *tab[i];
	// si on arrive là, le titre n'est pas bon
	throw CinemaException("Demande d'un film inexistant dans la cinematheque");
}