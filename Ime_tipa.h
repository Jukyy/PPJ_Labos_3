#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"
#include "pomocne_funkcije_roko.h"

povratni_tip Ime_tipa::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    //cout << "Ime_tipa" << endl;

	povratni_tip xy;

	if (produkcija.nodes.size() == 1) {
		xy = produkcija1(produkcija, tablica);
	}
	else if (produkcija.nodes.size() == 2) {
		xy = produkcija2(produkcija, tablica);
	}
	else {
		parametriGreska("ime_tipa", produkcija.nodes.size());
		xy = produkcija2(produkcija, tablica);
	}
	return xy; 
}

povratni_tip Ime_tipa::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	
	povratni_tip povratna, xy;
	Specifikator_tipa SpecifikatorTipa;

	if (produkcija.nodes[0].znak.compare("<specifikator_tipa>")) {
		greskaUmijesto("<specifikator_tipa>", produkcija.nodes[0].znak);
	}
	povratna = SpecifikatorTipa.produkcija(produkcija.nodes[0], tablica);

	xy.tip = povratna.tip;

	return xy;
}

povratni_tip Ime_tipa::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip povratna, xy;
	Specifikator_tipa SpecifikatorTipa;

	if (produkcija.nodes[0].znak.compare(0, strlen("KR_CONST"), "KR_CONST")) {
		greskaUmijesto("KR_CONST", produkcija.nodes[0].znak);
	}

	if (produkcija.nodes[1].znak.compare("<specifikator_tipa>")) {
		greskaUmijesto("<specifikator_tipa>", produkcija.nodes[1].znak);
	}
	povratna = SpecifikatorTipa.produkcija(produkcija.nodes[1], tablica);

	xy.tip = "const(" + povratna.tip + ")";
	xy.constant = true;

	if (!povratna.tip.compare("void")) {
		throw form_error(produkcija);
	}
	return xy;
}
