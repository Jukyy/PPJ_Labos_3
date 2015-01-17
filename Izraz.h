#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Izraz::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    //cout << "Izraz" << endl;

	povratni_tip xy;
	if (produkcija.nodes.size() == 1) {
		xy = produkcija1(produkcija, tablica);
	}
	else if (produkcija.nodes.size() == 3) {
		xy = produkcija2(produkcija, tablica);
	}
	else {
		parametriGreska("Izraz", produkcija.nodes.size());
		xy = produkcija2(produkcija, tablica);
	}
	return xy;
}

povratni_tip Izraz::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip xy, povratna;
	Izraz_pridruzivanja IzrazPridruzivanja;

	if (produkcija.nodes[0].znak.compare("<izraz_pridruzivanja>")) {
		greskaUmijesto("<izraz_pridruzivanja>", produkcija.nodes[0].znak);
	}

	povratna = IzrazPridruzivanja.produkcija(produkcija.nodes[0], tablica);

	xy.tip = povratna.tip;
	xy.l_izraz = povratna.l_izraz;
	return xy;
}

povratni_tip Izraz::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip povratna2, povratna1, xy;
	Izraz izraz;
	Izraz_pridruzivanja IzrazPridruzivanja;

	if (produkcija.nodes[0].znak.compare("<izraz>")) {
		greskaUmijesto("<izraz>", produkcija.nodes[0].znak);
	}

	povratna1 = izraz.produkcija(produkcija.nodes[0], tablica);

	if (produkcija.nodes[1].znak.compare(0, strlen("ZAREZ"), "ZAREZ")) {
		greskaUmijesto("ZAREZ", produkcija.nodes[1].znak);
	}

	if (produkcija.nodes[2].znak.compare("<izraz_pridruzivanja>")) {
		greskaUmijesto("<izraz_pridruzivanja>", produkcija.nodes[2].znak);
	}

	povratna2 = IzrazPridruzivanja.produkcija(produkcija.nodes[2], tablica);
	
	xy.tip = povratna2.tip;
	xy.l_izraz = 0;

	return xy;
}
