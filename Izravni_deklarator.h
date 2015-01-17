#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"
#include "pomocne_funkcije_roko.h"

povratni_tip Izravni_deklarator::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    cerr << "Izravni_deklarator" << endl;

	povratni_tip xy;
	if (produkcija.nodes.size() == 1) {
		xy = produkcija1(produkcija, tablica, ntip);
	}
	else if (produkcija.nodes.size() == 4)
	{
		if (produkcija.nodes[1].znak.substr(0, produkcija.nodes[1].znak.find(" ")) == "L_UGL_ZAGRADA")
		{
			xy = produkcija2(produkcija, tablica, ntip);
		}
		else if (produkcija.nodes[2].znak.substr(0, produkcija.nodes[2].znak.find(" ")) == "KR_VOID")
		{
			xy = produkcija3(produkcija, tablica, ntip);
		}
		else
		{
			xy = produkcija4(produkcija, tablica, ntip);
		}
	}
	else {
		parametriGreska("Izravni_deklarator", produkcija.nodes.size());
	}

	return xy;
}

povratni_tip Izravni_deklarator::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip xy;
	
	xy.tip = ntip;
	std::string radni = vratiTrecistring(produkcija.nodes[0].znak);
	
	Znakovi znak;
	znak.ime = radni;
	znak.tip = xy.tip;

	tablica.lokalne_variable.push_back(znak);

	return xy;
}

povratni_tip Izravni_deklarator::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip xy;
	
	xy.tip = "niz(" + ntip + ")";

	std::string TreciDiostringa = produkcija.nodes[2].znak;
	TreciDiostringa = TreciDiostringa.substr(TreciDiostringa.find(" "));
	TreciDiostringa = TreciDiostringa.substr(TreciDiostringa.find(" "));

	xy.broj = atoi(TreciDiostringa.c_str());
	
	std::string radni = vratiTrecistring(produkcija.nodes[0].znak);

	Znakovi znak;
	znak.ime = radni;
	znak.tip = xy.tip;

	tablica.lokalne_variable.push_back(znak);

	return xy;
}

povratni_tip Izravni_deklarator::produkcija3(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip xy;
	
	xy.tip = "funkcija(void->" + ntip + ")";

	std::string radni = vratiTrecistring(produkcija.nodes[0].znak);

	Znakovi znak;
	znak.ime = radni;
	znak.tip = xy.tip;

	tablica.lokalne_variable.push_back(znak);

	return xy;
}

povratni_tip Izravni_deklarator::produkcija4(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip povratna ,xy;
	Lista_parametara ListaParametara;

	povratna = ListaParametara.produkcija(produkcija.nodes[2], tablica);
	
	xy.tip = "funkcija(" + povratna.tip + "->ntip)";
	
	std::string radni = vratiTrecistring(produkcija.nodes[0].znak);

	Znakovi znak;
	znak.ime = radni;
	znak.tip = xy.tip;

	tablica.lokalne_variable.push_back(znak);

	return xy;
}
