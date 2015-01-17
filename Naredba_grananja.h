#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Naredba_grananja::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    //cout << "Naredba_grananja" << endl;
	if (produkcija.nodes.size() == 5)
		return produkcija1(produkcija, tablica);
	else
		return produkcija2(produkcija, tablica);
}

povratni_tip Naredba_grananja::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	povratni_tip izvedbena_vrijednost1;
	Izraz arg1;
	izvedbena_vrijednost1 = arg1.produkcija(produkcija.nodes[2], tablica);
	if (!(Ekvivaletni(izvedbena_vrijednost1.tip, "int")))
		throw form_error(produkcija);

	Naredba::produkcija(produkcija.nodes[4], tablica);
	
	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost;
}

povratni_tip Naredba_grananja::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	povratni_tip izvedbena_vrijednost1;
	Izraz arg1;
	izvedbena_vrijednost1 = arg1.produkcija(produkcija.nodes[2], tablica);
	if (!(Ekvivaletni(izvedbena_vrijednost1.tip, "int")))
		throw form_error(produkcija);

	Naredba::produkcija(produkcija.nodes[4], tablica);
	Naredba::produkcija(produkcija.nodes[6], tablica);
	
	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost;
}
