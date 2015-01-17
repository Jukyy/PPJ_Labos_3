#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Lista_naredbi::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    cerr << "Lista_naredbi" << endl;
	if (produkcija.nodes[0].znak == "<naredba>")
		return produkcija1(produkcija, tablica);
	else
		return produkcija2(produkcija, tablica);
}

povratni_tip Lista_naredbi::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	Naredba::produkcija(produkcija.nodes[0], tablica);

	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost;
}

povratni_tip Lista_naredbi::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	Lista_naredbi::produkcija(produkcija.nodes[0], tablica);
	Naredba::produkcija(produkcija.nodes[1], tablica);
	
	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost; 
}
