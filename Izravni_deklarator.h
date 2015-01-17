#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"
#include "pomocne_funkcije_roko.h"

povratni_tip Izravni_deklarator::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    //cout << "Izravni_deklarator" << endl;

	povratni_tip xy;
	if (produkcija.nodes.size() == 1) {
		xy = produkcija1(produkcija, tablica, ntip);
	}
	else if (produkcija.nodes.size() == 4)
	{
		if (produkcija.nodes[1].znak.substr(0, produkcija.nodes[1].znak.find(" ")) == "L_UGL_ZAGRADA")
		{
			xy = produkcija2(produkcija, tablica, ntip);
		}
		else if (produkcija.nodes[2].znak.substr(0, produkcija.nodes[2].znak.find(" ")) == "KR_VOID")
		{
			xy = produkcija3(produkcija, tablica, ntip);
		}
		else
		{
			xy = produkcija4(produkcija, tablica, ntip);
		}
	}
	else {
		parametriGreska("Izravni_deklarator", produkcija.nodes.size());
	}

	return xy;
}

povratni_tip Izravni_deklarator::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip xy;

	if (produkcija.nodes[0].znak.compare(0, strlen("IDN"), "IDN")) {
		greskaUmijesto("IDN", produkcija.nodes[0].znak);
	}

	xy.tip = ntip;
	
	if (!ntip.compare("void")) {
		throw form_error(produkcija);
	}

	std::string radni = vratiTrecistring(produkcija.nodes[0].znak);

	if (NalaziSeUVektoru(tablica.lokalne_variable, radni)) {
		throw form_error(produkcija);
	}

	Znakovi znak;
	znak.ime = radni;
	znak.tip = xy.tip;

	tablica.lokalne_variable.push_back(znak);

	return xy;
}

povratni_tip Izravni_deklarator::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip xy;

	if (produkcija.nodes[0].znak.compare(0, strlen("IDN"), "IDN")) {
		greskaUmijesto("IDN", produkcija.nodes[0].znak);
	}
	if (produkcija.nodes[1].znak.compare(0, strlen("L_UGL_ZAGRADA"), "L_UGL_ZAGRADA")) {
		greskaUmijesto("L_UGL_ZAGRADA", produkcija.nodes[1].znak);
	}
	if (produkcija.nodes[2].znak.compare(0, strlen("BROJ"), "BROJ")) {
		greskaUmijesto("BROJ", produkcija.nodes[2].znak);
	}
	if (produkcija.nodes[3].znak.compare(0, strlen("D_UGL_ZAGRADA"), "D_UGL_ZAGRADA")) {
		greskaUmijesto("D_UGL_ZAGRADA", produkcija.nodes[3].znak);
	}

	xy.tip = "niz(" + ntip + ")";

	std::string TreciDiostringa = produkcija.nodes[2].znak;
	TreciDiostringa = TreciDiostringa.substr(TreciDiostringa.find(" "));
	TreciDiostringa = TreciDiostringa.substr(TreciDiostringa.find(" "));

	if (atoi(TreciDiostringa.c_str()) <= 0 || atoi(TreciDiostringa.c_str())>1024) {
		throw form_error(produkcija);
	}

	xy.broj = atoi(TreciDiostringa.c_str());

	if (!ntip.compare("void")) {
		throw form_error(produkcija);
	}
	
	std::string radni = vratiTrecistring(produkcija.nodes[0].znak);

	if (NalaziSeUVektoru(tablica.lokalne_variable, radni)) {
		throw form_error(produkcija);
	}

	Znakovi znak;
	znak.ime = radni;
	znak.tip = xy.tip;

	tablica.lokalne_variable.push_back(znak);

	return xy;
}

povratni_tip Izravni_deklarator::produkcija3(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip xy;

	if (produkcija.nodes[0].znak.compare(0, strlen("IDN"), "IDN")) {
		greskaUmijesto("IDN", produkcija.nodes[0].znak);
	}
	if (produkcija.nodes[1].znak.compare(0, strlen("L_ZAGRADA"), "L_ZAGRADA")) {
		greskaUmijesto("L_ZAGRADA", produkcija.nodes[1].znak);
	}
	if (produkcija.nodes[2].znak.compare(0, strlen("KR_VOID"), "KR_VOID")) {
		greskaUmijesto("KR_VOID", produkcija.nodes[2].znak);
	}
	if (produkcija.nodes[3].znak.compare(0, strlen("D_ZAGRADA"), "D_ZAGRADA")) {
		greskaUmijesto("D_ZAGRADA", produkcija.nodes[3].znak);
	}
	xy.tip = "funkcija(void->" + ntip + ")";

	std::string radni = vratiTrecistring(produkcija.nodes[0].znak);

	if (NalaziSeUVektoru(tablica.lokalne_variable, radni, 1, xy.tip)) {
		throw form_error(produkcija);
	}

	Znakovi znak;
	znak.ime = radni;
	znak.tip = xy.tip;

	tablica.lokalne_variable.push_back(znak);

	return xy;
}

povratni_tip Izravni_deklarator::produkcija4(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip povratna ,xy;
	Lista_parametara ListaParametara;
	if (produkcija.nodes[0].znak.compare(0, strlen("IDN"), "IDN")) {
		greskaUmijesto("IDN", produkcija.nodes[0].znak);
	}
	if (produkcija.nodes[1].znak.compare(0, strlen("L_ZAGRADA"), "L_ZAGRADA")) {
		greskaUmijesto("L_ZAGRADA", produkcija.nodes[1].znak);
	}
	if (produkcija.nodes[2].znak.compare("<lista_parametara>")) {
		greskaUmijesto("KR_VOID", produkcija.nodes[2].znak);
	}

	povratna = ListaParametara.produkcija(produkcija.nodes[2], tablica);

	if (produkcija.nodes[3].znak.compare(0, strlen("D_ZAGRADA"), "D_ZAGRADA")) {
		greskaUmijesto("D_ZAGRADA", produkcija.nodes[3].znak);
	}
	
	xy.tip = "funkcija(" + povratna.tip + "->ntip)";
	
	std::string radni = vratiTrecistring(produkcija.nodes[0].znak);

	if (NalaziSeUVektoru(tablica.lokalne_variable, radni, 1, xy.tip)) {
		form_error(produkcija);
	}

	Znakovi znak;
	znak.ime = radni;
	znak.tip = xy.tip;

	tablica.lokalne_variable.push_back(znak);

	return xy;
}
