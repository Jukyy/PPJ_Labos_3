#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Naredba::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    cerr << "Naredba" << endl;
	if (produkcija.nodes[0].znak == "<slozena_naredba>")
		return produkcija1(produkcija, tablica);
	else if (produkcija.nodes[0].znak == "<izraz_naredba>")
		return produkcija2(produkcija, tablica);
	else if (produkcija.nodes[0].znak == "<naredba_grananja>")
		return produkcija3(produkcija, tablica);
	else if (produkcija.nodes[0].znak == "<naredba_petlje>")
		return produkcija4(produkcija, tablica);
	else
		return produkcija5(produkcija, tablica);
}

povratni_tip Naredba::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;

	Slozena_naredba::produkcija(produkcija.nodes[0], tablica);

	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost;
}

povratni_tip Naredba::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;

	Izraz_naredba::produkcija(produkcija.nodes[0], tablica);

	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost;
}

povratni_tip Naredba::produkcija3(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;

	Naredba_grananja::produkcija(produkcija.nodes[0], tablica);

	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost;
}

povratni_tip Naredba::produkcija4(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	
	tablica.is_loop = true;
	Naredba_petlje::produkcija(produkcija.nodes[0], tablica);

	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost;
}

povratni_tip Naredba::produkcija5(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;

	Naredba_skoka::produkcija(produkcija.nodes[0], tablica);

	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost;
}
