#if !defined(CTIME)
#define CTIME

#include<iostream>
#include<iomanip>

namespace TIME {
	/*! \class TimeException
     \brief Classe permettant de g�rer les exceptions des classes du namespace TIME 		
     */
	class TimeException{
	public:
		//! Constructeur � partir d'une string
		TimeException(const std::string& m):info(m){}
		const std::string& GetInfo() const { return info; } //<! Retourne l'information stock�e dans la classe
	private:
		std::string info;
	};
    
	/*! \class Date
     \brief Classe permettant de manipuler des dates standards 		
     L'utilisation de cette classe n�cessite des dates valides au sens commun du terme. 
     D�clenchement d'exception dans le cas contraire
     */	
	class Date {
	public:
		//! Constructeur � partir d'un jour, mois, ann�e
		/*! \param j jour avec 1<=j<=31
         \param m mois avec 1<=m<=12
         \param a ann�e avec a>=0
         */
		Date(short j=1, short m=1, unsigned int a=0):jour(1),mois(1),annee(0){ SetDate(j,m,a); }
		// m�thodes
		unsigned short int  GetJour() const { return jour; } //<! Retourne le jour de la date
		unsigned short int  GetMois() const { return mois; } //<! Retourne le mois de la date
		unsigned int GetAnnee() const { return annee; } //<! Retourne l'ann�e de la date
		void SetDate(unsigned short int j, unsigned short int m, unsigned int a); //!< initialisation de la date
		void SetDateAujourdhui(); //!< initialisation de la date avec la date d'aujourd'hui
		void Afficher(std::ostream& f=std::cout) const; //!< affiche le date sous le format JJ/MM/AAAA
		bool operator==(const Date& d) const; //<! d1==d2 retourne vrai si les deux dates sont �gales
		bool operator<(const Date& d) const; //<! Compare deux dates dans le temps : d1<d2 retourne true si d1 est avant d2
		int operator-(const Date& d) const; //<! Retourne le nombre de jours s�parant les deux dates
		Date Demain() const; //<! Retourne la date du lendemain
		Date operator+(unsigned int nb) const; //<!Retourne la date de dans nb jours
	private:
		// attributs
		unsigned short int jour; // jour entre 1 et 31
		unsigned short int mois; // mois entre 1 et 12
		unsigned int annee; 
	};
    
	/*! \class Duree
     \brief Classe permettant de manipuler des durees	
     L'utilisation de cette classe n�cessite des dates valides au sens commun du terme. 
     D�clenchement d'exception dans le cas contraire
     */	
	class Duree{
	public:
		//! Constructeur � partir de heure et minute
		/*! \param h heure avec h>=0
         \param m minute avec 0<=m<=59
         */
		Duree(unsigned int h, unsigned int m):nb_minutes(h*60+m) {if (m>59) throw TimeException("erreur: initialisation duree invalide");}
		//! Constructeur � partir de minute
		/*! \param m minute avec m>=0
         */
		Duree(unsigned int m):nb_minutes(m) {}
		void SetDuree(unsigned int heures, unsigned int minutes) { if (minutes>59) throw TimeException("erreur: initialisation duree invalide"); nb_minutes=heures*60+minutes; }
		unsigned int GetDureeEnMinutes() const { return nb_minutes; } //<!Retourne la duree en minutes
		double GetDureeEnHeures() const { return double(nb_minutes)/60; } //<!Retourne la duree en heures
		void Afficher(std::ostream& f=std::cout) const { f<<nb_minutes/60<<"H"<<std::setw(2)<<nb_minutes%60; } //<!Affiche la duree sous le format hhHmm
	private:
		unsigned int nb_minutes;
	};
    
	/*! \class Horaire
     \brief Classe permettant de manipuler des horaires	
     L'utilisation de cette classe n�cessite des dates valides au sens commun du terme. 
     D�clenchement d'exception dans le cas contraire
     */	
	class Horaire{
	public:
		//! Constructeur � partir de heure et minute
		/*! \param h heure avec 0<=h<=23
         \param m minute avec 0<=m<=59
         */
		Horaire(unsigned short int  h, unsigned short int  m):heure(h),minute(m) {if (h>23||m>59) throw TimeException("erreur: initialisation horaire invalide");}
		void SetHoraire(unsigned short int h, unsigned short int m) { if (h>23||m>59) throw TimeException("erreur: initialisation horaire invalide"); heure=h; minute=m; }
		void Afficher(std::ostream& f=std::cout) const { f<<heure<<"H"<<minute; } //<!Affiche l'horaire sous le format hhHmm
		unsigned short int GetHeure() const { return heure; } //<!Retourne l'heure de l'horaire
		unsigned short int GetMinute() const { return minute; } //<!Retourne les minutes de l'horaire
		bool operator<(const Horaire& h) const; //<! h1<h2 retourne true si h1 est avant h2 dans le temps
	private:
		unsigned short int  heure;
		unsigned short int  minute;
	};
    
	/*! \class Periode
     \brief Classe permettant de manipuler des periodes exprim�es en jours/mois/ann�es	
     L'utilisation de cette classe n�cessite des dates valides au sens commun du terme. 
     D�clenchement d'exception dans le cas contraire
     */	
	class Periode{
        public :
		//! Constructeur � partir de jour/mois/ann�e
		/*! \param j nombre de jours avec 0<=j<=364
         \param m nombre de mois avec 0<=m<=11
         \param a nombre d'ann�es 
         */
		Periode(unsigned int j, unsigned int m, unsigned int a);
		void Afficher(std::ostream& f=std::cout) const { f<<"{"<<nb_jours<<" jours, "<<nb_mois<<" mois, "<<nb_annees<<" ans}"; }
	private:
		unsigned int nb_jours;
		unsigned int nb_mois;
		unsigned int nb_annees;
	};
    
	/*! \class Intervalle
     \brief Classe permettant de manipuler des intervalles de dates
     L'utilisation de cette classe n�cessite des dates valides au sens commun du terme. 
     D�clenchement d'exception dans le cas contraire
     */	
	class Intervalle{
	public:
		//! Constructeur � partir de deux dates
		/*! \param d date de d�but de l'intervalle
         \param f date de fin de l'intervalle. On doit avoir d<=f
         */
		Intervalle(const Date & d, const Date & f);
		void Afficher(std::ostream& f=std::cout) const; //<! Affiche l'intervalle de dates
		Date GetDebut() const { return debut; } //<! Retourne la date de d�but de l'intervalle
		Date GetFin() const { return fin; } //<! Retourne la date de fin de l'intervalle
		int GetDuree() const { return fin-debut; } //<! Retourne le nombre de jours s'�coulant entre le d�but et la fin de l'intervalle
		bool operator&&(const Intervalle & v) const; //<! I1&&I2 Retourne vrai si il y a intersection entre I1 et I2
		Intervalle operator + (const Intervalle & i) const; //<! I1+I2 Retourne un intervalle union des 2 intervalles I1 et I2 qui se touchent, ie I2.debut est le jour du lendemain de I1.fin
	private:
		Date debut;
		Date fin;
	};
    
}

std::ostream& operator<<(std::ostream&, const TIME::Date&);
std::ostream& operator<<(std::ostream& f, const TIME::Duree & d);
std::ostream& operator<<(std::ostream& f, const TIME::Horaire & h);
std::ostream& operator<<(std::ostream& f, const TIME::Periode & p);
std::ostream& operator<<(std::ostream& f, const TIME::Intervalle & p);

#endif
