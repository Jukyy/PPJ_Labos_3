#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Lista_parametara::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
    cerr << "Lista_parametara" << endl;
	povratni_tip xy;
	
	//produkcija 1
	if(produkcija.nodes.size() == 1
    && produkcija.nodes[0].znak == "<deklaracija_parametra>")
	   xy = Lista_parametara::produkcija1(produkcija, tablica, ntip);
    //produkcija 2
    else if(produkcija.nodes.size() == 3
         && produkcija.nodes[0].znak == "<lista_parametara>"
         && produkcija.nodes[1].znak.substr(0, produkcija.nodes[1].znak.find(" ")) == "ZAREZ"
         && produkcija.nodes[2].znak == "<deklaracija_parametra>")
       xy = Lista_parametara::produkcija2(produkcija, tablica, ntip);
	
	return xy; //nasumièna varijabla xy je tu samo radi toènosti kompaliranja (zamjeni je s potrebnim vrijednostima)
}

povratni_tip Lista_parametara::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	Deklaracija_parametra deklaracija_parametra;
	
	//1
	xy = deklaracija_parametra.produkcija(produkcija.nodes[0], tablica, ntip);
	
	return xy;
}

povratni_tip Lista_parametara::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	povratni_tip xy2;
	Deklaracija_parametra deklaracija_parametra;
	
	//1
	xy = Lista_parametara::produkcija(produkcija.nodes[0], tablica, ntip);
	//2
	xy2 = deklaracija_parametra.produkcija(produkcija.nodes[2], tablica, ntip);
	//3
	std::string temp = xy.ime + ",";
	std::string rijec = "a";
	while(temp != "")
	{
       rijec = temp.substr(0, temp.find(","));
       temp = temp.substr(temp.find(",")+1);
    }
	
	xy.tip = xy.tip + "," + xy2.tip;
	xy.ime = xy.ime + "," + xy2.ime;
	
	return xy;
}
