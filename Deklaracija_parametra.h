#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"
#include "pomocne_funkcije_roko.h"


povratni_tip Deklaracija_parametra::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    cerr << "Deklaracija_parametra" << endl;

	povratni_tip xy;

	if (produkcija.nodes.size() == 4) {
		xy = produkcija1(produkcija, tablica);
	}
	else if (produkcija.nodes.size() == 2) {
		xy = produkcija2(produkcija, tablica);
	}
	else {
		parametriGreska("Deklaracija_parametra", produkcija.nodes.size());
		xy = produkcija2(produkcija, tablica);
	}
	return xy;
}

povratni_tip Deklaracija_parametra::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip povratna1;
	Ime_tipa imeTipa;
	povratna1 = imeTipa.produkcija(produkcija.nodes[0], tablica);
	
	povratna1.ime = vratiTrecistring(produkcija.nodes[1].znak);
	povratna1.ime_varijable = povratna1.ime;

	return povratna1;
}

povratni_tip Deklaracija_parametra::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip povratna1;
	Ime_tipa imeTipa;
	povratna1 = imeTipa.produkcija(produkcija.nodes[0], tablica);

	povratna1.ime = vratiTrecistring(produkcija.nodes[1].znak);
	povratna1.ime_varijable = povratna1.ime;

	return povratna1;
}

