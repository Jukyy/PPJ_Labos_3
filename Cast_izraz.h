#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Cast_izraz::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    cerr << "Cast_izraz" << endl;
	if(produkcija.nodes.size() == 1) return produkcija1(produkcija, tablica);
	else return produkcija2(produkcija, tablica);
 }

povratni_tip Cast_izraz::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	Node node = produkcija.nodes[0];
	
	Unarni_izraz izraz;
	izvedbena_vrijednost = izraz.produkcija(node, tablica);
	
	return izvedbena_vrijednost;
}

povratni_tip Cast_izraz::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	Node node1 = produkcija.nodes[1];
	Node node2 = produkcija.nodes[3];
	
	Ime_tipa tip;
	povratni_tip vrijednost1 = tip.produkcija(node1, tablica);
	Cast_izraz izraz;
    povratni_tip vrijednost2 = izraz.produkcija(node2, tablica);
	izvedbena_vrijednost.l_izraz = false;
	
	//LABOS 4 prosljedjivanje imena_varijable
	izvedbena_vrijednost.ime_varijable = vrijednost2.ime_varijable;
	
	return izvedbena_vrijednost;
}
