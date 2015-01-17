#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Prijevodna_jedinica::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    cerr << "Prijevodna_jedinica" << endl;
	if (produkcija.nodes.size() == 1)
		return produkcija1(produkcija, tablica);
	else
		return produkcija2(produkcija, tablica);
}

povratni_tip Prijevodna_jedinica::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	Vanjska_deklaracija::produkcija(produkcija.nodes[0], tablica);

	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost;
}

povratni_tip Prijevodna_jedinica::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	Prijevodna_jedinica::produkcija(produkcija.nodes[0], tablica);
	Vanjska_deklaracija::produkcija(produkcija.nodes[1], tablica);

	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost;
}
