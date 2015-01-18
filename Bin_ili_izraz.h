#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Bin_ili_izraz::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    cerr << "Bin_ili_izraz" << endl;
	if (produkcija.nodes.size() == 1) return produkcija1(produkcija, tablica);
	else return produkcija2(produkcija, tablica);
}

povratni_tip Bin_ili_izraz::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	Node node = produkcija.nodes[0];
	
	Bin_xili_izraz izraz;
	izvedbena_vrijednost = izraz.produkcija(node, tablica);
	
	return izvedbena_vrijednost;
}

povratni_tip Bin_ili_izraz::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	Node node1 = produkcija.nodes[0];
	Node node2 = produkcija.nodes[2];
	
    Bin_ili_izraz izraz1;
	povratni_tip vrijednost1 = izraz1.produkcija(node1, tablica);
	FRISC::LOAD("R5", vrijednost1.ime_varijable, tablica.lok_var);
	Bin_xili_izraz izraz2;
	povratni_tip vrijednost2 = izraz2.produkcija(node2, tablica);
    FRISC::LOAD("R4", vrijednost2.ime_varijable, tablica.lok_var);
	
	vrijednost1.tip = "int";
	vrijednost1.l_izraz = false;
	
	//LABOS 4
    FRISC::OR("R5", "R4", "R5");
    FRISC::STORE("R5", "TEMP", tablica.lok_var);
    vrijednost1.ime_varijable = "TEMP";
	
	return vrijednost1;
}
