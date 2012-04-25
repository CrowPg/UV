#if !defined(CINEMA)
#define CINEMA


#include <string>
#include <iostream>
#include "time.h"

using namespace TIME;

class Film;
class Programmation;
class Planning;
class Salle;
class Cinema;
class Cinematheque;
class CinemaException;


std::ostream& operator<<(std::ostream&, const Film&);
std::ostream& operator<<(std::ostream&, const Programmation&);
std::ostream& operator<<(std::ostream&, const Planning&);
std::ostream& operator<<(std::ostream&, const Salle&);
std::ostream& operator<<(std::ostream&, const Cinema&);

const int NB_MAX_PROG=100;

class CinemaException {
public:
	CinemaException(const std::string& m):info(m){}
	const std::string& GetInfo() const { return info; }
private:
	std::string info;
};




class Film{
public:
	Film(const std::string& t, int d):titre(t),duree(d) {}
	void Afficher(std::ostream& f=std::cout) const;
	const std::string& GetTitre() const { return titre; }
	Duree GetDuree() const { return duree; }
private:
	std::string titre;
	Duree duree;
};

class Cinematheque {
public:
	static Cinematheque& GetInstance();
	static void LibereInstance();
	void AjouterFilm(const std::string& t, int d);
	const Film& GetFilm(const std::string& t) const;
private:
	Cinematheque(unsigned int n):nb_films(0),nb_max(n),tab(new Film*[n]){} // à mettre dans la partie privée pour en interdire l'utilisation
	~Cinematheque(); // à mettre dans la partie privée pour en interdire l'utilisation
	Cinematheque(const Cinematheque&); // non défini mais à mettre dans la partie privée pour en interdire l'utilisation
	void operator=(const Cinematheque&); // non défini mais à mettre dans la partie privée pour en interdire l'utilisation
	// attributs
	Film** tab;
	unsigned int nb_films;
	unsigned int nb_max;
	static Cinematheque* instance; // pointeur sur la seule instance de la classe
};

class Programmation {
private:
	const Film* film;
	Intervalle inter;
public:
	Programmation():film(0),inter(Date(),Date()){}
	Programmation(const Film& f, const Date& debut, const Date& fin):film(&f),inter(debut,fin){}
	void Afficher(std::ostream& f=std::cout) const;
	Intervalle GetReservation() const { return inter; }  
};

class Planning {
	Programmation* progs;
	int nbProgs;
	int taille;
public :
	explicit Planning(int t):progs(new Programmation[t]),taille(t),nbProgs(0){}
	~Planning() { delete[] progs; }
	Planning(const Planning& p);
	Planning& operator=(const Planning& p);
	bool operator<<(const Programmation& p);
	void Afficher(std::ostream& f=std::cout) const;
	int GetNbProgrammations() const  { return nbProgs;  }
	int GetTaille() const  { return taille;  }
	
	class iterateur {
	public:
		const Programmation& operator*() const { return *prog; }
		bool operator!=(const iterateur& it) { return prog!=it.prog; }
		void operator++() { ++prog; }
		iterateur(const Programmation* p=0):prog(p){} 
	private:
		const Programmation* prog;
	};
	iterateur begin() const { return iterateur(progs); }
	iterateur end() const { return iterateur(progs+nbProgs); }
};

class Salle{
private:
	int num;
	Planning planning;
public:
	explicit Salle(int n):num(n),planning(NB_MAX_PROG){}
	int GetNumero() const { return num; }
	Planning& GetPlanning() { return planning; }
	const Planning& GetPlanning() const { return planning; }
	void Afficher(std::ostream& f=std::cout) const { f<<"SALLE Numero "<<num<<"\n"; planning.Afficher(f); }	
};

class Cinema {
private:
	std::string nom;
	Salle** salles;
	unsigned int nbSalles;
	Cinema(const Cinema& c):salles(0),nbSalles(0){}
	void operator=(const Cinema& c){}
public:
	Cinema(const std::string n, int nb);
	~Cinema();
	Salle& operator[](unsigned int i) { if (i<1||i>nbSalles) throw CinemaException("erreur : cette salle n'existe pas"); return *salles[i-1]; }
	const Salle& operator[](unsigned int i) const { if (i<1||i>nbSalles) throw CinemaException("erreur : cette salle n'existe pas"); return *salles[i]; }
	void Afficher(std::ostream& f=std::cout) const { f<<"Cinema "<<nom<<"\n"; for(unsigned int i=0; i<nbSalles; i++) salles[i]->Afficher(f); }	
};



#endif