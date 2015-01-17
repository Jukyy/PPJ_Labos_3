#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"
#include "pomocne_funkcije_roko.h"

povratni_tip Init_deklarator::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    cerr << "Init_deklarator" << endl;

	povratni_tip xy;
	
	if (produkcija.nodes.size() == 1) {
		xy = produkcija1(produkcija, tablica, ntip);
	}
	else if (produkcija.nodes.size() == 3) {
		xy = produkcija2(produkcija, tablica, ntip);
	}
	else {
		parametriGreska("Init_deklarator", produkcija.nodes.size());
	}
	return xy; 
}

povratni_tip Init_deklarator::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip xy, povratna;
	Izravni_deklarator IzravniDeklarator;
	
	povratna = IzravniDeklarator.produkcija(produkcija.nodes[0], tablica, ntip);
	
	return xy;
}

povratni_tip Init_deklarator::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip povratna1, povratna2, xy;
	Izravni_deklarator IzravniDeklarator;
	Inicijalizator inicijalizator;
	
	povratna1 = IzravniDeklarator.produkcija(produkcija.nodes[0], tablica, ntip);
	povratna2 = inicijalizator.produkcija(produkcija.nodes[2], tablica);

	std::string tip = povratna1.tip;
	if (tip.find("niz") == std::string::npos)
		tip = skini(tip, "const");
	else
    {
		tip = skini(tip, "niz");
		tip = skini(tip, "const");

		std::string tipovi = povratna2.tip;
		while (tipovi.find(",") != std::string::npos)
        {
			std::string radna = tipovi.substr(0, tipovi.find(","));
			tipovi = tipovi.substr(tipovi.find(","));
		}
	}

	return xy;
}
