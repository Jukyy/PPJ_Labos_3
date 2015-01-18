#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"
#include "FRISC/FRISC_instrukcije.h"

povratni_tip Naredba_grananja::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    cerr << "Naredba_grananja" << endl;
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
	FRISC::LOAD("R1",izvedbena_vrijednost1.ime_varijable, tablica.lok_var);
	FRISC::CMP("R1", "0");
	
	Stvori_novu_labelu("IF_f");
	string labela1 = Vrati_labelu("IF_f");
	FRISC::JP("EQ", labela1);
    
	Naredba::produkcija(produkcija.nodes[4], tablica);
	FRISC::label(labela1);
	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost1;
}

povratni_tip Naredba_grananja::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	povratni_tip izvedbena_vrijednost1;
	Izraz arg1;
	
	izvedbena_vrijednost1 = arg1.produkcija(produkcija.nodes[2], tablica);
	FRISC::LOAD("R1",izvedbena_vrijednost1.ime_varijable, tablica.lok_var);
	FRISC::CMP("R1", "0");
	
	Stvori_novu_labelu("IF_f");
	string labela1 = Vrati_labelu("IF_f");
	FRISC::JP("EQ", labela1);
	
	Stvori_novu_labelu("IF_t");
    string labela2 = Vrati_labelu("IF_t");
    
	Naredba::produkcija(produkcija.nodes[4], tablica);
	FRISC::JP(labela2);
	FRISC::label(labela1);
	
    Naredba::produkcija(produkcija.nodes[6], tablica);
	FRISC::label(labela2);
	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost;
}
