#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Jednakosni_izraz::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    //cout << "Jednakosni_izraz" << endl;
	
	povratni_tip xy;

	if (produkcija.nodes.size() == 1) {
		xy = produkcija1(produkcija, tablica);
	}
	else if (produkcija.nodes.size() == 3) {
		xy = produkcija2(produkcija, tablica);
	}
	return xy; 
}

povratni_tip Jednakosni_izraz::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip povratna, xy;
	Odnosni_izraz OdnosniIzraz;

	if (produkcija.nodes[0].znak.compare("<odnosni_izraz>")) {
		greskaUmijesto("<odnosni_izraz>", produkcija.nodes[0].znak);
	}

	povratna = OdnosniIzraz.produkcija(produkcija.nodes[0], tablica);
	
	xy.tip = povratna.tip;
	xy.l_izraz = povratna.l_izraz;

	return xy;
}

povratni_tip Jednakosni_izraz::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	
	povratni_tip povratna1, povratna2, xy;
	Jednakosni_izraz JednakosniIzraz;
	Odnosni_izraz OdnosniIzraz;

	if (produkcija.nodes[0].znak.compare("<jednakosni_izraz>")) {
		greskaUmijesto("<jednakosni_izraz>", produkcija.nodes[0].znak);
	}

	povratna1 = JednakosniIzraz.produkcija(produkcija.nodes[0], tablica);

	if (produkcija.nodes[1].znak.compare(0, strlen("OP_EQ"), "OP_EQ") && produkcija.nodes[1].znak.compare(0, strlen("OP_NEQ"), "OP_NEQ")) {
		greskaUmijesto("OP_EQ | OP_NEQ", produkcija.nodes[1].znak);
	}


	if (produkcija.nodes[2].znak.compare("<odnosni_izraz>")) {
		greskaUmijesto("<odnosni_izraz>", produkcija.nodes[2].znak);
	}

	povratna2 = OdnosniIzraz.produkcija(produkcija.nodes[2], tablica);

	if (povratna1.l_izraz != 1) {
		throw form_error(produkcija);
	}

	if(!Ekvivaletni(povratna1.tip, "int")) {
		throw form_error(produkcija);
	}
	if(!Ekvivaletni(povratna2.tip, "int")) {
		throw form_error(produkcija);
	}
	xy.tip = "int";
	xy.l_izraz = false;

	return xy;
}

povratni_tip Jednakosni_izraz::produkcija3(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){ // ne koristimo je
	povratni_tip xy;

	return xy;
}
