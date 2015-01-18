#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"
#include "pomocne_funkcije_roko.h"

povratni_tip Lista_argumenata::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    cerr << "Lista_argumenata" << endl;
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

	povratni_tip povratna;
	Izraz_pridruzivanja IzrazPridruzivanja;

	povratna = IzrazPridruzivanja.produkcija(produkcija.nodes[0], tablica);

	return povratna;
}

povratni_tip Lista_argumenata::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip povratna1, povratna2, xy;
	Lista_argumenata ListaArgumenata;
	Izraz_pridruzivanja IzrazPridurzivanja;

	povratna1 = ListaArgumenata.produkcija(produkcija.nodes[0], tablica);
	povratna2 = IzrazPridurzivanja.produkcija(produkcija.nodes[2], tablica);
	
	xy.tip = povratna1.tip + "," + povratna2.tip;
	xy.ime_varijable = povratna1.ime_varijable + "," + povratna2.ime_varijable;

	return xy;
}
