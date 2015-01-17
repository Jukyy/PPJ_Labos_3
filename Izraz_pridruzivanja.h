#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"
#include "pomocne_funkcije_roko.h"

povratni_tip Izraz_pridruzivanja::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    //cout << "Izraz_pridruzivanja" << endl;

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

	if (produkcija.nodes[0].znak.compare("<log_ili_izraz>")) {
		greskaUmijesto("<log_ili_izraz>", produkcija.nodes[0].znak);
	}
	povratna = LogIliIzraz.produkcija(produkcija.nodes[0], tablica);
	

	xy.tip = povratna.tip;
	xy.l_izraz = povratna.l_izraz;

	return xy;
}

povratni_tip Izraz_pridruzivanja::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip povratna1, povratna2, xy;
	Postfiks_izraz PostfiksIzraz;
	Izraz_pridruzivanja IzrazPridruzivanja;

	if (produkcija.nodes[0].znak.compare("<postfiks_izraz>")) {
		greskaUmijesto("<postfiks_izraz>", produkcija.nodes[0].znak);
	}

	povratna1 = PostfiksIzraz.produkcija(produkcija.nodes[0], tablica);

	if (produkcija.nodes[1].znak.compare(0, strlen("OP_PRIDRUZI"), "OP_PRIDRUZI")) {
		greskaUmijesto("OP_PRIDRUZI", produkcija.nodes[1].znak);
	}

	if (produkcija.nodes[2].znak.compare("<izraz_pridruzivanja>")) {
		greskaUmijesto("<izraz_pridruzivanja>", produkcija.nodes[2].znak);
	}

	povratna2 = IzrazPridruzivanja.produkcija(produkcija.nodes[2], tablica);

	if (povratna1.l_izraz != 1) {
		throw form_error(produkcija);
	}

	if(!Ekvivaletni(povratna2.tip, povratna1.tip)) {
		throw form_error(produkcija);
	}

	xy.tip = povratna1.tip;
	xy.l_izraz = false;

	return xy;
}
