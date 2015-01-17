#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"
#include "pomocne_funkcije_roko.h"


povratni_tip Deklaracija_parametra::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    //cout << "Deklaracija_parametra" << endl;

	povratni_tip xy;

	if (produkcija.nodes.size() == 4) {
		xy = produkcija1(produkcija, tablica);
	}
	else if (produkcija.nodes.size() == 2) {
		xy = produkcija2(produkcija, tablica);
	}
	else {
		parametriGreska("Deklaracija_parametra", produkcija.nodes.size());
		xy = produkcija2(produkcija, tablica);
	}
	return xy;
}

povratni_tip Deklaracija_parametra::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip povratna1, xy;
	Ime_tipa imeTipa;
	if (produkcija.nodes[0].znak.compare("<ime_tipa>")) {
		greskaUmijesto("<ime_tipa>", produkcija.nodes[0].znak);
	}
	povratna1 = imeTipa.produkcija(produkcija.nodes[0], tablica);
	if (produkcija.nodes[1].znak.compare(0, strlen("IDN"), "IDN")) {
		greskaUmijesto("IDN", produkcija.nodes[1].znak);
	}
	if (produkcija.nodes[2].znak.compare(0, strlen("L_UGL_ZAGRADA"), "L_UGL_ZAGRADA")) {
		greskaUmijesto("L_UGL_ZAGRADA", produkcija.nodes[2].znak);
	}
	if (produkcija.nodes[3].znak.compare(0, strlen("D_UGL_ZAGRADA"), "D_UGL_ZAGRADA")) {
		greskaUmijesto("D_UGL_ZAGRADA", produkcija.nodes[3].znak);
	}
	xy.tip = povratna1.tip;
	xy.ime = vratiTrecistring(produkcija.nodes[1].znak);

	if (!xy.tip.compare("void")) {
		throw form_error(produkcija);
	}

	return xy;
}

povratni_tip Deklaracija_parametra::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip povratna1, xy;
	Ime_tipa imeTipa;

	if (produkcija.nodes[0].znak.compare("<ime_tipa>")) {
		greskaUmijesto("<ime_tipa>", produkcija.nodes[0].znak);
	}
	povratna1 = imeTipa.produkcija(produkcija.nodes[0], tablica);
	if (produkcija.nodes[1].znak.compare(0, strlen("IDN"), "IDN")) {
		greskaUmijesto("IDN", produkcija.nodes[1].znak);
	}
	xy.tip = povratna1.tip;
	xy.ime = vratiTrecistring(produkcija.nodes[1].znak);

	if (!xy.tip.compare("void")) {
		throw form_error(produkcija);
	}

	return xy;
}

