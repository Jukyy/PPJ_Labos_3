#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"
#include "pomocne_funkcije_roko.h"

povratni_tip Init_deklarator::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    //cout << "Init_deklarator" << endl;

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

	if (produkcija.nodes[0].znak.compare("<izravni_deklarator>")) {
		greskaUmijesto("<izravni_deklarator>", produkcija.nodes[0].znak);
	}
	povratna = IzravniDeklarator.produkcija(produkcija.nodes[0], tablica, ntip);

	if (!povratna.tip.substr(0, 5).compare("const") || !povratna.tip.substr(0, 9).compare("niz(const")) {
		throw form_error(produkcija);
	}


	return xy;
}

povratni_tip Init_deklarator::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip povratna1, povratna2, xy;
	Izravni_deklarator IzravniDeklarator;
	Inicijalizator inicijalizator;

	if (produkcija.nodes[0].znak.compare("<izravni_deklarator>")) {
		greskaUmijesto("<izravni_deklarator>", produkcija.nodes[0].znak);
	}

	povratna1 = IzravniDeklarator.produkcija(produkcija.nodes[0], tablica, ntip);

	if (produkcija.nodes[1].znak.compare(0, strlen("OP_PRIDRUZI"), "OP_PRIDRUZI")) {
		greskaUmijesto("OP_PRIDRUZI", produkcija.nodes[1].znak);
	}

	if (produkcija.nodes[2].znak.compare("<inicijalizator>")) {
		greskaUmijesto("<inicijalizator>", produkcija.nodes[2].znak);
	}

	povratna2 = inicijalizator.produkcija(produkcija.nodes[2], tablica);

	std::string tip = povratna1.tip;
	if (tip.find("niz") == std::string::npos) {
		tip = skini(tip, "const");
		if (!Ekvivaletni(povratna2.tip, tip)) {
			throw form_error(produkcija);
		}
	}
	else {
		tip = skini(tip, "niz");
		tip = skini(tip, "const");
		if (povratna2.broj > povratna1.broj) {
			throw form_error(produkcija);
		}

		std::string tipovi = povratna2.tip;
		while (tipovi.find(",") != std::string::npos) {
			std::string radna = tipovi.substr(0, tipovi.find(","));
			if (!Ekvivaletni(radna, tip)) {
				throw form_error(produkcija);
			}
			tipovi = tipovi.substr(tipovi.find(","));
		}
		if (!Ekvivaletni(tipovi, tip)) {
			throw form_error(produkcija);
		}
	}

	return xy;
}
