#if !defined(_EVENEMENT_H)
#define _EVENEMENT_H


#include<iostream>
#include<limits>
#include<string>
#include<sstream>
#include<iomanip>
#include<typeinfo>
#include "time.h"

using namespace std;

namespace TIME{
	
    class Evt
    {
    protected:
        Date date;
        string objet;
        
    public:
        Evt(int j, int m, int a, const string& obj) : date(Date(j, m, a)), objet(obj){}
        
        virtual ~Evt(){}
        const string& getDescription() const {return objet;}
        const Date& getDate() const {return date;}
        void setDescription(const string& desc){objet=desc;}
        void setDate(const Date& d){date=d;}
        
        virtual void afficher(ostream& os) const{os<<to_string();} // =0 => méthode explicitement non déinife, alors classe abstraite et on ne peut pas l'implémenter.
        virtual Evt* clone()const = 0;
        virtual string to_string() const =0;
    };
    
	class ev_1j : public Evt { 
	public:
		ev_1j(int j, int m, int a, const std::string& obj):Evt(j, m, a, obj){}
		
		~ev_1j();
		Evt* clone() const;
        string to_string()const
        {
            stringstream ss;
            ss<<"***** evt ********"<<endl;
            ss<<"Date="<<date<<" objet="<<objet<<endl;
            return ss.str();
        }
	};

    class ev_pj : public Evt
    {
        int intervalle;
        
    public:
        ev_pj(int j, int m, int a, const string& obj, int _intervalle) : Evt(j, m, a, obj), intervalle(_intervalle) {}
        int getIntervalle()const{return intervalle;}
        void setIntervalle(int i){intervalle=i;}
        
        Evt* clone() const {return new ev_pj(*this);}
        string to_string()const
        {
            stringstream ss;
            ss<<"***** evt ********"<<endl;
            ss<<"Date="<<date<<" intervalle : " << intervalle << " objet="<<objet<<"\n";
            return ss.str();
        }
    };
	
	class ev_1j_dur : public ev_1j {
	protected:
		Horaire _debut;
		Duree   _duree;
	public:
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
        string to_string()const
        {
            stringstream ss;
            ss<<"***** evt ********"<<endl;
            ss<<"debut="<<_debut<<" duree="<<_duree<<" fin="<<GetHoraireFin()<<"\n";
            return ss.str();
        }
        
        
	};

	class rdv : public ev_1j_dur {
	protected:
		std::string personne;
		std::string lieu;
	public:
		rdv(int j, int m, int a, const std::string& obj,
					int hdebut, int mdebut, int hdur, int mdur,
					const std::string& p,
					const std::string& l):
			ev_1j_dur(j,m,a,obj,hdebut,mdebut,hdur,mdur),
			personne(p),
			lieu(l){}
		rdv* clone() const;
        string to_string()const
        {
            stringstream ss;
            ss<<"***** evt ********"<<endl;
            ss<<"personne="<<personne<<" lieu="<<lieu<<"\n";
            return ss.str();
        }
	};

	class Agenda {
		Evt** tab;
		unsigned int nb_evts;
		unsigned int nb_max_evts;
	public:
		Agenda():
			nb_evts(0),
			nb_max_evts(10),
			tab(new Evt*[10]) {}
		~Agenda();
		void operator<<(const Evt& e);
		void afficher(std::ostream& f=std::cout) const;

		class iterator {
			Evt** cur;
		public:
			iterator(Evt** pt=0):cur(pt){}
			iterator& operator++() { cur++; return *this; }
			const Evt& operator*() const { return **cur; }
			bool operator==(iterator it) const { return cur==it.cur; }
			bool operator!=(iterator it) const { return cur!=it.cur; }
		};
		iterator begin() const { return iterator(tab); }
		iterator end() const { return iterator(tab+nb_evts); }
	};
}

std::ostream& operator<<(std::ostream& f, const TIME::Evt& e);
std::ostream& operator<<(std::ostream& f, const TIME::Agenda& e);

#endif
