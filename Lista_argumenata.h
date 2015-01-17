#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"
#include "pomocne_funkcije_roko.h"

povratni_tip Lista_argumenata::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    //cout << "Lista_argumenata" << endl;
	povratni_tip xy;
	if (produkcija.nodes.size() == 1) {
		xy = produkcija1(produkcija, tablica);
	}
	else if (produkcija.nodes.size() == 3) {
		xy = produkcija2(produkcija, tablica);
	}
	else {
		parametriGreska("Lista argumenata", produkcija.nodes.size());
	}
	return xy;
}

povratni_tip Lista_argumenata::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip xy, povratna;
	Izraz_pridruzivanja IzrazPridruzivanja;

	if (produkcija.nodes[0].znak.compare("<izraz_pridruzivanja>")) {
		greskaUmijesto("<izraz_pridruzivanja>", produkcija.nodes[0].znak);
	}

	povratna = IzrazPridruzivanja.produkcija(produkcija.nodes[0], tablica);

	xy.tip = povratna.tip;

	return xy;
}

povratni_tip Lista_argumenata::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip povratna1, povratna2, xy;
	Lista_argumenata ListaArgumenata;
	Izraz_pridruzivanja IzrazPridurzivanja;

	if (produkcija.nodes[0].znak.compare("<lista_argumenata>")) {
		greskaUmijesto("<lista_argumenata>", produkcija.nodes[0].znak);
	}

	povratna1 = ListaArgumenata.produkcija(produkcija.nodes[0], tablica);

	if (produkcija.nodes[1].znak.compare(0, strlen("ZAREZ"), "ZAREZ")) {
		greskaUmijesto("ZAREZ", produkcija.nodes[1].znak);
	}
	
	if (produkcija.nodes[2].znak.compare("<izraz_pridruzivanja>")) {
		greskaUmijesto("<izraz_pridruzivanja>", produkcija.nodes[2].znak);
	}

	povratna2 = IzrazPridurzivanja.produkcija(produkcija.nodes[2], tablica);
	
	xy.tip = povratna1.tip + "," + povratna2.tip;

	return xy;
}
