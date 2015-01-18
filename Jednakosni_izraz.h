#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Jednakosni_izraz::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    cerr << "Jednakosni_izraz" << endl;
	
	povratni_tip xy;

	if (produkcija.nodes.size() == 1) {
		xy = produkcija1(produkcija, tablica);
	}
	else if (produkcija.nodes.size() == 3 && produkcija.nodes[1].znak[3] == 'E') {
		xy = produkcija2(produkcija, tablica);
	}
	else if (produkcija.nodes.size() == 3 && produkcija.nodes[1].znak[3] == 'N') {
		xy = produkcija3(produkcija, tablica);
	}
	return xy; 
}

povratni_tip Jednakosni_izraz::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){

	povratni_tip povratna, xy;
	Odnosni_izraz OdnosniIzraz;
	
	povratna = OdnosniIzraz.produkcija(produkcija.nodes[0], tablica);
	
	xy.tip = povratna.tip;
	xy.l_izraz = povratna.l_izraz;
	
	//LABOS 4 prosljedjivanje imena_varijable
	xy.ime_varijable = povratna.ime_varijable;

	return xy;
}

povratni_tip Jednakosni_izraz::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	
	povratni_tip povratna1, povratna2, xy;
	Jednakosni_izraz JednakosniIzraz;
	Odnosni_izraz OdnosniIzraz;

	povratna1 = JednakosniIzraz.produkcija(produkcija.nodes[0], tablica);
	FRISC::LOAD("R0", povratna1.ime_varijable, tablica.lok_var);
	povratna2 = OdnosniIzraz.produkcija(produkcija.nodes[2], tablica);
	FRISC::LOAD("R1", povratna2.ime_varijable, tablica.lok_var);
	
	FRISC::CMP("R0", "R1");
	Stvori_novu_labelu("U_EQ_t");
	Stvori_novu_labelu("U_EQ_f");
	FRISC::JP("EQ", Vrati_labelu("U_EQ_t"));
	FRISC::MOVE("0", "R0");
	FRISC::STORE("R0", "TEMP", tablica.lok_var);
	FRISC::JP(Vrati_labelu("U_EQ_f"));
	FRISC::label(Vrati_labelu("U_EQ_t"));
	FRISC::MOVE("1", "R0");
	FRISC::STORE("R0", "TEMP", tablica.lok_var);
	FRISC::label(Vrati_labelu("U_EQ_f"));
	
	xy.tip = "int";
	xy.l_izraz = false;
	xy.ime_varijable = "TEMP";

	return xy;
}

povratni_tip Jednakosni_izraz::produkcija3(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){ // ne koristimo je

	povratni_tip povratna1, povratna2, xy;
	Jednakosni_izraz JednakosniIzraz;
	Odnosni_izraz OdnosniIzraz;

	povratna1 = JednakosniIzraz.produkcija(produkcija.nodes[0], tablica);
	FRISC::LOAD("R0", povratna1.ime_varijable, tablica.lok_var);
	povratna2 = OdnosniIzraz.produkcija(produkcija.nodes[2], tablica);
	FRISC::LOAD("R1", povratna2.ime_varijable, tablica.lok_var);
	
	FRISC::CMP("R0", "R1");
	Stvori_novu_labelu("U_NE_t");
	Stvori_novu_labelu("U_NE_f");
	FRISC::JP("NE", Vrati_labelu("U_NE_t"));
	FRISC::MOVE("0", "R0");
	FRISC::STORE("R0", "TEMP", tablica.lok_var);
	FRISC::JP(Vrati_labelu("U_NE_f"));
	FRISC::label(Vrati_labelu("U_NE_t"));
	FRISC::MOVE("1", "R0");
	FRISC::STORE("R0", "TEMP", tablica.lok_var);
	FRISC::label(Vrati_labelu("U_NE_f"));
	
	xy.tip = "int";
	xy.l_izraz = false;
	xy.ime_varijable = "TEMP";

	return xy;
}
