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
    //cout << "Primarni_izraz" << endl;
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
    if(!found) throw form_error(produkcija);

	return izvedbena_vrijednost;
}

povratni_tip Primarni_izraz::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	izvedbena_vrijednost.tip = "int";
	izvedbena_vrijednost.l_izraz = false;
    	
	Node node = produkcija.nodes[0];
	string znak = vratiTrecistring(node.znak);

	if (znak.size() > string("2147483647").size()) 
		throw form_error(produkcija);
	else if (znak.size() == string("2147483647").size() && znak.compare(string("2147483647"))) {
		if (!znak.compare(string("2147483648"))) {
			// ako je unarni nije prije throw form_error(produkcija);
		}
		else throw form_error(produkcija);
	}

	return izvedbena_vrijednost;
}

povratni_tip Primarni_izraz::produkcija3(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	izvedbena_vrijednost.tip = "char";
	izvedbena_vrijednost.l_izraz = false;
    
    Node node = produkcija.nodes[0];
    std::string znak = node.znak;
	for (unsigned i = 0; i < node.znak.length(); ++i) {
        if(node.znak[i] == ' ') znak = node.znak.substr(i+1); 
    }
	if (znak.size() == 4) {
		if (znak != "'\\t'" && znak != "'\\n'" &&
			znak != "'\\0'" && znak != "'\\''" &&
			znak != "'\\\"'" && znak != "'\\\\'") throw form_error(produkcija);
		// && znak != "'"'" &&)
	}
        
	return izvedbena_vrijednost;
}

povratni_tip Primarni_izraz::produkcija4(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	izvedbena_vrijednost.tip = "niz(char)";
	izvedbena_vrijednost.constant = true;
	izvedbena_vrijednost.l_izraz = false;
    

	string niz = vratiTrecistring(produkcija.nodes[0].znak);
	string temp_niz;
	for (int brojac = 0; brojac != produkcija.nodes[0].znak.size() - 1; brojac++)
	{
		temp_niz = produkcija.nodes[0].znak.at(brojac) + produkcija.nodes[0].znak.at(brojac + 1);
		if (temp_niz != "\\t" && temp_niz != "\\n" &&
			temp_niz != "\\0" && temp_niz != "\\'" &&
			temp_niz != "\\\"" && temp_niz != "\\\\") throw form_error(produkcija);
	}


	return izvedbena_vrijednost;
}

povratni_tip Primarni_izraz::produkcija5(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	
	Node node = produkcija.nodes[1];
	Izraz izraz;
	izvedbena_vrijednost = izraz.produkcija(node, tablica);
    
	return izvedbena_vrijednost;
}
