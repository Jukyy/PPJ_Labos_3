#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"
#include "pomocne_funkcije_roko.h"

povratni_tip Izraz_pridruzivanja::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    cerr << "Izraz_pridruzivanja" << endl;

	povratni_tip xy;

	if (produkcija.nodes.size() == 1) {
		xy = produkcija1(produkcija, tablica);
	}
	else if (produkcija.nodes.size() == 3) {
		xy = produkcija2(produkcija, tablica);
	}
	else {
		parametriGreska("Izraz_Pridruzivanja", produkcija.nodes.size());
		xy = produkcija2(produkcija, tablica);
	}

	return xy;
}

povratni_tip Izraz_pridruzivanja::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	
	povratni_tip povratna, xy;
	Log_ili_izraz LogIliIzraz;
	
	povratna = LogIliIzraz.produkcija(produkcija.nodes[0], tablica);
	
	xy.tip = povratna.tip;
	xy.l_izraz = povratna.l_izraz;
	
	//LABOS 4 prosljedjivanje imena_varijable
	xy.ime_varijable = povratna.ime_varijable;

	return xy;
}

povratni_tip Izraz_pridruzivanja::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip povratna1, povratna2, xy;
	Postfiks_izraz PostfiksIzraz;
	Izraz_pridruzivanja IzrazPridruzivanja;
	
	povratna1 = PostfiksIzraz.produkcija(produkcija.nodes[0], tablica);
	povratna2 = IzrazPridruzivanja.produkcija(produkcija.nodes[2], tablica);
	
	xy.tip = povratna1.tip;
	xy.l_izraz = false;

	return xy;
}
