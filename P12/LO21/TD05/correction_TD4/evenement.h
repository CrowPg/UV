#if !defined(_EVENEMENT_H)
#define _EVENEMENT_H


#include<iostream>
#include<limits>
#include<string>
#include<iomanip>
#include<typeinfo>
#include "time.h"

using namespace std;

namespace TIME{
	

	class ev_1j { 
	protected:
		std::string _objet;
		Date _date;
	public:
		ev_1j(int j, int m, int a, const std::string& obj):_date(j,m,a),_objet(obj){}
		const std::string& get_description() const { return _objet; }
		const Date& get_date() const { return _date; }
		virtual void Afficher(std::ostream& f=std::cout) const;
		virtual ~ev_1j();
		virtual ev_1j* clone() const;
	};

	
	class ev_1j_dur : public ev_1j {
	protected:
		Horaire _debut;
		Duree   _duree;
	public:
		void Afficher(std::ostream& f=std::cout) const;
		ev_1j_dur(int j, int m, int a,
			                        const std::string& obj,
									int hdebut, int mdebut,
									int hdur, int mdur):
				ev_1j(j,m,a,obj),
				_debut(hdebut,mdebut),
				_duree(hdur,mdur){}
		const Horaire& GetHoraire() const { return _debut; }
		const Duree& GetDuree() const { return _duree; }
		Horaire GetHoraireFin() const;
		ev_1j_dur* clone() const;
	};

	class rdv : public ev_1j_dur {
	protected:
		std::string personne;
		std::string lieu;
	public:
		void Afficher(std::ostream& f=std::cout) const;
		rdv(int j, int m, int a, const std::string& obj,
					int hdebut, int mdebut, int hdur, int mdur,
					const std::string& p,
					const std::string& l):
			ev_1j_dur(j,m,a,obj,hdebut,mdebut,hdur,mdur),
			personne(p),
			lieu(l){}
		rdv* clone() const;
	};

	class Agenda {
		ev_1j** tab;
		unsigned int nb_evts;
		unsigned int nb_max_evts;
	public:
		Agenda():
			nb_evts(0),
			nb_max_evts(10),
			tab(new ev_1j*[10]) {}
		~Agenda();
		void operator<<(const ev_1j& e);
		void Afficher(std::ostream& f=std::cout) const;

		class iterator {
			ev_1j** cur;
		public:
			iterator(ev_1j** pt=0):cur(pt){}
			iterator& operator++() { cur++; return *this; }
			const ev_1j& operator*() const { return **cur; }
			bool operator==(iterator it) const { return cur==it.cur; }
			bool operator!=(iterator it) const { return cur!=it.cur; }
		};
		iterator begin() const { return iterator(tab); }
		iterator end() const { return iterator(tab+nb_evts); }
	};
}

std::ostream& operator<<(std::ostream& f, const TIME::ev_1j& e);
std::ostream& operator<<(std::ostream& f, const TIME::Agenda& e);

#endif
