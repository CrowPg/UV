//#include "cinema.h"
#include "cinema.h"

int main(){
	try {
		Cinematheque& collection=Cinematheque::GetInstance();
		collection.AjouterFilm("Kill Bill 1", 123);
		collection.AjouterFilm("Kill Bill 2", 156);
		collection.AjouterFilm("2001, Space Odyssey", 152);
		collection.AjouterFilm("School of Rock", 118);
		collection.AjouterFilm("Freaky Friday", 112);
	
		Cinema cine("Majestic",2);
		cine[1].GetPlanning()<<Programmation(collection.GetFilm("Kill Bill 1"),Date(5,5,2010),Date(11,5,2010));
		cine[2].GetPlanning()<<Programmation(collection.GetFilm("Kill Bill 2"),Date(5,5,2010),Date(11,5,2010));
		cine[1].GetPlanning()<<Programmation(collection.GetFilm("2001, Space Odyssey"),Date(12,5,2010),Date(18,5,2010));
		cine[1].GetPlanning()<<Programmation(collection.GetFilm("School of Rock"),Date(19,5,2010),Date(25,5,2010));
		cine[2].GetPlanning()<<Programmation(collection.GetFilm("Freaky Friday"),Date(12,5,2010),Date(25,5,2010));
		cine.Afficher();
	
		std::cout<<"\nEssai Iterateur\n";
		for(Planning::iterateur it=cine[1].GetPlanning().begin(); it!=cine[1].GetPlanning().end();++it)
			std::cout<<*it<<"\n";
		for(Planning::iterateur it=cine[0].GetPlanning().begin(); it!=cine[0].GetPlanning().end();++it)
			std::cout<<*it<<"\n";
		Cinematheque::LibereInstance();
	}
	catch(CinemaException e){
		std::cout<<e.GetInfo()<<"\n";
	}
	catch(TimeException e){
		std::cout<<e.GetInfo()<<"\n";
	}
	std::cout<<"Fin projet cinema\n";
	system("pause");
}