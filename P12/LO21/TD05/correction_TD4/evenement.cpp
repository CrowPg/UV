#include "evenement.h"

std::ostream& operator<<(std::ostream& f, const TIME::ev_1j& e){
	e.Afficher(f); return f;
}

std::ostream& operator<<(std::ostream& f, const TIME::Agenda& e){
	e.Afficher(f); return f;
}

void TIME::ev_1j::Afficher(std::ostream& f) const{
	f<<"***** evt ********"<<"\n";
	f<<"Date="<<_date<<" objet="<<_objet<<"\n";
}

TIME::ev_1j::~ev_1j() {}

TIME::Horaire TIME::ev_1j_dur::GetHoraireFin() const{
	int fin_minutes=_debut.GetHeure()*60
					+_debut.GetMinute()+_duree.GetDureeEnMinutes();
	int h=fin_minutes/60;
	int m=fin_minutes%60;
	if (h>24) h-=24;
	return Horaire(h,m);
}

void TIME::ev_1j_dur::Afficher(std::ostream& f) const{
	ev_1j::Afficher(f);
	f<<"debut="<<_debut<<" duree="<<_duree<<" fin="<<GetHoraireFin()<<"\n";
}

void TIME::rdv::Afficher(std::ostream& f) const{
	ev_1j_dur::Afficher(f);
	f<<"personne="<<personne<<" lieu="<<lieu<<"\n";
}

TIME::ev_1j* TIME::ev_1j::clone() const { return new ev_1j(*this); }
TIME::ev_1j_dur* TIME::ev_1j_dur::clone() const { return new ev_1j_dur(*this); }
TIME::rdv* TIME::rdv::clone() const { return new rdv(*this); }

void TIME::Agenda::operator<<(const TIME::ev_1j& e){
	//std::cout<<"ajout d'un evt"<<"\n";
	//std::cout<<e<<"\n";
	if (nb_evts==nb_max_evts){
		ev_1j** newtab=new ev_1j* [nb_max_evts+=10];
		for(unsigned int i=0; i<nb_evts; i++) newtab[i]=tab[i];
		delete[] tab;
		newtab=tab;
	}
	tab[nb_evts++]=e.clone();
}

void TIME::Agenda::Afficher(std::ostream& f) const{
	f<<"#####    AGENDA  #####"<<"\n";
	for(unsigned int i=0; i<nb_evts; i++) { std::cout<<"type="<<typeid(*tab[i]).name()<<"\n"; tab[i]->Afficher(f); }
	f<<"##### FIN AGENDA #####"<<"\n";
}

TIME::Agenda::~Agenda(){
	for(unsigned int i=0; i<nb_evts; i++) delete tab[i];
	delete[] tab;
}

