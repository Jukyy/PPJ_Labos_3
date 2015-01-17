#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Jednakosni_izraz::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    cerr << "Jednakosni_izraz" << endl;
	
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
	
	povratna = OdnosniIzraz.produkcija(produkcija.nodes[0], tablica);
	
	xy.tip = povratna.tip;
	xy.l_izraz = povratna.l_izraz;

	return xy;
}

povratni_tip Jednakosni_izraz::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	
	povratni_tip povratna1, povratna2, xy;
	Jednakosni_izraz JednakosniIzraz;
	Odnosni_izraz OdnosniIzraz;

	povratna1 = JednakosniIzraz.produkcija(produkcija.nodes[0], tablica);
	povratna2 = OdnosniIzraz.produkcija(produkcija.nodes[2], tablica);
	
	xy.tip = "int";
	xy.l_izraz = false;

	return xy;
}

povratni_tip Jednakosni_izraz::produkcija3(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){ // ne koristimo je
	povratni_tip xy;

	return xy;
}
