#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Naredba_petlje::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    cerr << "Naredba_petlje" << endl;
	if (produkcija.nodes.size() == 5)
		return produkcija1(produkcija, tablica);
	else if (produkcija.nodes.size() == 6)
		return produkcija2(produkcija, tablica);
	else
		return produkcija3(produkcija, tablica);
}

povratni_tip Naredba_petlje::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	povratni_tip izvedbena_vrijednost1;
	Izraz arg1;

	izvedbena_vrijednost1 = arg1.produkcija(produkcija.nodes[2], tablica);
	loop_status = LOOP;
	Naredba::produkcija(produkcija.nodes[4], tablica);
	loop_status = UNDEFINED_LOOP;
	
	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost;
}

povratni_tip Naredba_petlje::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	povratni_tip izvedbena_vrijednost2;

	Izraz_naredba::produkcija(produkcija.nodes[2], tablica);
	izvedbena_vrijednost2 = Izraz_naredba::produkcija(produkcija.nodes[3], tablica);

	loop_status = LOOP;
	Naredba::produkcija(produkcija.nodes[5], tablica);
	if (tablica.is_loop)
		loop_status = UNDEFINED_LOOP;
	else
		loop_status = NOT_LOOP;

	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost;
}

povratni_tip Naredba_petlje::produkcija3(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	povratni_tip izvedbena_vrijednost2;
	Izraz arg3;

	Izraz_naredba::produkcija(produkcija.nodes[2], tablica);
	izvedbena_vrijednost2 = Izraz_naredba::produkcija(produkcija.nodes[3], tablica);

	arg3.produkcija(produkcija.nodes[4], tablica);
	loop_status = LOOP;
	Naredba::produkcija(produkcija.nodes[6], tablica);
	if (tablica.is_loop)
		loop_status = UNDEFINED_LOOP;
	else
		loop_status = NOT_LOOP;
	
	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost;
}
