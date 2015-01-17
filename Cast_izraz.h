#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

bool JeLiBrojevno(std::string str) {
	str = skini(str, "niz");
	str = skini(str, "const");
	str = skini(str, "niz");
	if (str == "char" || str == "niz")
		return true;
	return false;
}

povratni_tip Cast_izraz::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    //cout << "Cast_izraz" << endl;
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
	if (!(JeLiBrojevno(vrijednost1.tip) && JeLiBrojevno(vrijednost2.tip))) {
		throw form_error(produkcija);
	}
	izvedbena_vrijednost.l_izraz = false;
	
	return izvedbena_vrijednost;
}
