#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"
#include <climits>
#include <string>
#include "pomocne_funkcije_roko.h"
using namespace std;

povratni_tip Primarni_izraz::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
    cerr << "Primarni_izraz" << endl;
	if (produkcija.nodes.size() == 1) {
        char c = produkcija.nodes[0].znak[0];
        switch(c) {
			case 'I':
			{
				povratni_tip p = produkcija1(produkcija, tablica);
				return p;
			}
			case 'B':
    			return produkcija2(produkcija, tablica);
    		case 'Z':
    			return produkcija3(produkcija, tablica);
    		default:
    			return produkcija4(produkcija, tablica);
        }
	}
	else return produkcija5(produkcija, tablica);
}

povratni_tip Primarni_izraz::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip izvedbena_vrijednost;

    Node node = produkcija.nodes[0];
    std::string ime = node.znak;
    for(unsigned i = 0; i < node.znak.length(); ++i)
    {
        if(node.znak[i] == ' ') ime = node.znak.substr(i+1); 
    }
	bool found = false;
    Tablica_djelokruga *t = &tablica;
    while(!found && t)
    {
		for (unsigned i = 0; i < (*t).lokalne_variable.size(); ++i)
        {
            if(ime == (*t).lokalne_variable[i].ime)
            {
                izvedbena_vrijednost.tip = (*t).lokalne_variable[i].tip;
                izvedbena_vrijednost.l_izraz = (*t).lokalne_variable[i].l_izraz;
                found = true;
                break;
            }
        }
        t = (*t).ugnijezdena_tablica;
    }
    
    //LABOS 4 dodavanje imena varijable ako je IDN
    izvedbena_vrijednost.ime_varijable = "V_" + ime;

	return izvedbena_vrijednost;
}

povratni_tip Primarni_izraz::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	izvedbena_vrijednost.tip = "int";
	izvedbena_vrijednost.l_izraz = false;
    	
	Node node = produkcija.nodes[0];
	string znak = vratiTrecistring(node.znak);
	
	//LABOS 4
	Stvori_novu_labelu("K_K", znak);
	izvedbena_vrijednost.ime_varijable = Vrati_labelu("K_K");

	return izvedbena_vrijednost;
}

povratni_tip Primarni_izraz::produkcija3(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	izvedbena_vrijednost.tip = "char";
	izvedbena_vrijednost.l_izraz = false;
    
    Node node = produkcija.nodes[0];
	string znak = vratiTrecistring(node.znak);
	
	//LABOS 4
	Stvori_novu_labelu("K_K", znak);
	izvedbena_vrijednost.ime_varijable = Vrati_labelu("K_K");
	//OVDJE JURE NASTUPA;
    
	return izvedbena_vrijednost;
}

povratni_tip Primarni_izraz::produkcija4(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	izvedbena_vrijednost.tip = "niz(char)";
	izvedbena_vrijednost.constant = true;
	izvedbena_vrijednost.l_izraz = false;
    
	string niz = vratiTrecistring(produkcija.nodes[0].znak);
	string temp_niz;

	return izvedbena_vrijednost;
}

povratni_tip Primarni_izraz::produkcija5(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	
	Node node = produkcija.nodes[1];
	Izraz izraz;
	izvedbena_vrijednost = izraz.produkcija(node, tablica);
    
	return izvedbena_vrijednost;
}
