#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Izraz::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    cerr << "Izraz" << endl;

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
	povratna = IzrazPridruzivanja.produkcija(produkcija.nodes[0], tablica);

	return povratna;
}

povratni_tip Izraz::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip povratna2, povratna1, xy;
	Izraz izraz;
	Izraz_pridruzivanja IzrazPridruzivanja;
	
	povratna1 = izraz.produkcija(produkcija.nodes[0], tablica);
	povratna2 = IzrazPridruzivanja.produkcija(produkcija.nodes[2], tablica);
	
	povratna2.l_izraz = 0;

	return povratna2;
}
