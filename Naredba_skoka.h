#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Naredba_skoka::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    cerr << "Naredba_skoka" << endl;
	if (produkcija.nodes[0].znak.substr(0,produkcija.nodes[0].znak.find(" ")) == "KR_CONTINUE" 
		|| produkcija.nodes[0].znak.substr(0, produkcija.nodes[0].znak.find(" ")) == "KR_BREAK")
		return produkcija1_2(produkcija, tablica);
	else {
		if (produkcija.nodes[1].znak != "<izraz>")
			return produkcija3(produkcija, tablica);
		else
			return produkcija4(produkcija, tablica);
	}

}

povratni_tip Naredba_skoka::produkcija1_2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;

	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost;
}

povratni_tip Naredba_skoka::produkcija3(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	std::string trenutna_funkcija = ime_trenutne_funkcije;
	std::string ftip;
	bool found=false;
	Tablica_djelokruga nova_tablica = tablica;

	while (true){
		for (unsigned i = 0; i < nova_tablica.lokalne_variable.size(); i++){
			if (nova_tablica.lokalne_variable[i].ime == ime_trenutne_funkcije){
				ftip = nova_tablica.lokalne_variable[i].tip;
				ftip = ftip.substr(ftip.find("->") + 2, ftip.find(")") - ftip.find("->") - 2);
				found = true;
				break;
			}
		}
		if (found)
			break;
		nova_tablica = *nova_tablica.ugnijezdena_tablica;
	}

	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost;
}

povratni_tip Naredba_skoka::produkcija4(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	povratni_tip izvedbena_vrijednost1;
	Izraz arg1;
	std::string trenutna_funkcija = ime_trenutne_funkcije;
	std::string ftip;
	bool found = false;
	Tablica_djelokruga nova_tablica = tablica;

	izvedbena_vrijednost1 = arg1.produkcija(produkcija.nodes[1], tablica);

	while (true){
		for (unsigned i = 0; i < nova_tablica.lokalne_variable.size(); i++){
			if (nova_tablica.lokalne_variable[i].ime == ime_trenutne_funkcije){
				ftip = nova_tablica.lokalne_variable[i].tip;
				ftip = ftip.substr(ftip.find("->") + 2, ftip.find(")") - ftip.find("->") - 2);
				found = true;
				break;
			}
		}
		if (found)
			break;
		nova_tablica = *nova_tablica.ugnijezdena_tablica;
	}
	
	//može se vratiti prazna izvedbena_vrijednost jer
	//produkcija ništa nevraèa
	return izvedbena_vrijednost;
}
