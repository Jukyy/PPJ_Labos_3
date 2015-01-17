#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Slozena_naredba::produkcija(Node produkcija, Tablica_djelokruga &tablica, vector<Znakovi> init_znakovi){
    //cout << "Slozena_naredba" << endl;
	if (produkcija.nodes.size() == 3)
		return produkcija1(produkcija, tablica, init_znakovi);
	else
		return produkcija2(produkcija, tablica, init_znakovi);
}

povratni_tip Slozena_naredba::produkcija1(Node produkcija, Tablica_djelokruga &tablica, vector<Znakovi> init_znakovi){
	povratni_tip izvedbena_vrijednost;
	Tablica_djelokruga nova_tablica;

	nova_tablica.ugnijezdena_tablica = &tablica;
	nova_tablica.is_global = false;
	if (loop_status == LOOP)
		nova_tablica.is_loop = true;
	else if (loop_status == UNDEFINED_LOOP)
		nova_tablica.is_loop = tablica.is_loop;
	else
		nova_tablica.is_loop = false;
	nova_tablica.lokalne_variable = init_znakovi; //primaju se znakovi od funkcije (ako postoje)
	Lista_naredbi::produkcija(produkcija.nodes[1], nova_tablica);
	tablica.lokalne_tablice.push_back(nova_tablica);

	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost;
}

povratni_tip Slozena_naredba::produkcija2(Node produkcija, Tablica_djelokruga &tablica, vector<Znakovi> init_znakovi){
	povratni_tip izvedbena_vrijednost;
	Tablica_djelokruga nova_tablica;
	Lista_deklaracija arg1;

	nova_tablica.ugnijezdena_tablica = &tablica;
	nova_tablica.is_global = false;
	if (loop_status == LOOP)
		nova_tablica.is_loop = true;
	else if (loop_status == UNDEFINED_LOOP)
		nova_tablica.is_loop = tablica.is_loop;
	else
		nova_tablica.is_loop = false;
	nova_tablica.lokalne_variable = init_znakovi; //primaju se znakovi od funkcije (ako postoje)
	arg1.produkcija(produkcija.nodes[1], nova_tablica);
	Lista_naredbi::produkcija(produkcija.nodes[2], nova_tablica);
	tablica.lokalne_tablice.push_back(nova_tablica);
	
	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost;
}
