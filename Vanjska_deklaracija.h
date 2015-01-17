#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Vanjska_deklaracija::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    //cout << "Vanjska_deklaracija" << endl;
	if (produkcija.nodes[0].znak == "<definicija_funkcije>")
		return produkcija1(produkcija, tablica);
	else
		return produkcija2(produkcija, tablica);
}

povratni_tip Vanjska_deklaracija::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	Definicija_funkcije arg1;

	arg1.produkcija(produkcija.nodes[0], tablica);

	//mo�e se vratiti prazna izvedbena_vrijednost jer
	//produkcija ni�ta nevra�a
	return izvedbena_vrijednost;
}

povratni_tip Vanjska_deklaracija::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	Deklaracija arg1;
	arg1.produkcija(produkcija.nodes[0], tablica);

	//mo�e se vratiti prazna izvedbena_vrijednost jer
	//produkcija ni�ta nevra�a
	return izvedbena_vrijednost;
}
