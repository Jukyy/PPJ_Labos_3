#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"
#include "pomocne_funkcije_roko.h"

povratni_tip Inicijalizator::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    //cout << "Inicijalizator" << endl;

	povratni_tip xy;
	if (produkcija.nodes.size() == 1) {
		xy = produkcija1(produkcija, tablica);
	}
	else if (produkcija.nodes.size() == 3) {
		xy = produkcija2(produkcija, tablica);
	}
	else {
		parametriGreska("Inicijalizaotr", produkcija.nodes.size());
	}
	return xy;
}

povratni_tip Inicijalizator::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip) {
	
	povratni_tip xy, povratna;
	Izraz_pridruzivanja IzrazPridruzivanja;

	if (produkcija.nodes[0].znak.compare("<izraz_pridruzivanja>")) {
		greskaUmijesto("<izraz_pridruzivanja>", produkcija.nodes[0].znak);
	}
	povratna = IzrazPridruzivanja.produkcija(produkcija.nodes[0], tablica);
	
	pair<std::string, int> rjesenje = DuljinaNiza(produkcija);
	xy.tip = "";
	
	if (rjesenje.first == "niz(const(char))")
	{
		if (rjesenje.second > 0)
		{
			for (int i = 0; i < rjesenje.second - 1; ++i)
			{
				xy.tip += "char,";
			}
			xy.tip += "char";
		}
		xy.broj = rjesenje.second;
	}
	else {
		xy.tip = povratna.tip;
	}

	return xy;
}

povratni_tip Inicijalizator::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	
	povratni_tip xy, povratna;
	Izraz_pridruzivanja IzrazPridruzivanja;

	if (produkcija.nodes[0].znak.compare(0, strlen("L_VIT_ZAGRADA"), "L_VIT_ZAGRADA")) {
		greskaUmijesto("L_VIT_ZAGRADA", produkcija.nodes[0].znak);
	}
	if (produkcija.nodes[1].znak.compare("<lista_izraza_pridruzivanja>")) {
		greskaUmijesto("<lista_izraza_pridruzivanja>", produkcija.nodes[1].znak);
	}
	povratna = IzrazPridruzivanja.produkcija(produkcija.nodes[1], tablica);

	if (produkcija.nodes[2].znak.compare(0, strlen("D_VIT_ZAGRADA"), "D_VIT_ZAGRADA")) {
		greskaUmijesto("D_VIT_ZAGRADA", produkcija.nodes[2].znak);
	}

	xy.broj = povratna.broj;
	xy.tip = povratna.tip;

	return xy;
}
