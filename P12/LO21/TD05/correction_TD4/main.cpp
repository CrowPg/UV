#include "evenement.h"
#include <iostream>

int main(){
	using namespace std;
	using namespace TIME;

	ev_1j e1(4,10,1957,"Spoutnik");
	ev_1j_dur e2(4,4,2012,"courses",19,0,0,45);
	rdv e3(11,4,2012,"reunion lo21",17,30,1,0,"Intervenants UV","bureau");
	ev_1j e4(20,7,1969,"Premier Homme sur la Lune");
	ev_1j e5(14,7,1789,"Prise de la Bastille");
	rdv e6(9,4,2012,"réunion TX",10,45,1,30,"étudiant","passerelle");

	Agenda mon_agenda;
	mon_agenda<<e1;
	mon_agenda<<e2;
	mon_agenda<<e3;
	mon_agenda<<e4;
	mon_agenda<<e5;
	mon_agenda<<e6;

	cout<<mon_agenda;

	cout<<"essai iterateur\n";
	for(Agenda::iterator it=mon_agenda.begin(); it!=mon_agenda.end(); ++it) std::cout<<*it<<"\n";

	system("pause");
	return 0;
}
