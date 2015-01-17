#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Izraz_naredba::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    cerr << "Izraz_naredba" << endl;
	if (produkcija.nodes.size() == 1)
		return produkcija1(produkcija, tablica);
	else
		return produkcija2(produkcija, tablica);
}

povratni_tip Izraz_naredba::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	izvedbena_vrijednost.tip = "int";
	return izvedbena_vrijednost;
	
}

povratni_tip Izraz_naredba::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	povratni_tip izvedbena_vrijednost1;
	Izraz arg1;
	izvedbena_vrijednost1 = arg1.produkcija(produkcija.nodes[0], tablica, "");
	izvedbena_vrijednost.tip = izvedbena_vrijednost1.tip;
	return izvedbena_vrijednost;
}
