#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

using namespace std;

Node parse_input(vector<std::string> lines){
	Node node;
	vector<std::string> pom;
	vector<std::string>::iterator it;
	int first = 1, last = 1;

	node.znak = lines[0];
	if (lines[0][0] == '<') node.zavrsni = false;
	else node.zavrsni = true;

	if (lines.size() == 1) return node;

	for (unsigned i = 1; i < lines.size(); i++)
		lines[i].erase(0, 1); //brisanje prve poèetne praznine

	for (unsigned i = 1; i < lines.size(); i++){
		last = i;
		if (lines[i][0] != ' '){
			if (first == last) continue;
			pom.clear();
			it = pom.begin();
			pom.insert(it, lines.begin() + first, lines.begin() + last);
			node.nodes.push_back(parse_input(pom));
			first = last;
		}
	}

	pom.clear();
	it = pom.begin();
	pom.insert(it, lines.begin() + first, lines.end());
	node.nodes.push_back(parse_input(pom));

	return node;
}
int PronadiUVektoru(vector<string> vec, string ime) {
	for (unsigned i = 0; i < vec.size(); ++i) {
		if (vec[i].compare(ime) == 0)
			return i;
	}
	return -1;
}
Node read_input(){
	Node head;
	std::string input;
	vector <std::string> lines;
	while (getline(cin, input)){
		lines.push_back(input);
	}
	head = parse_input(lines);
	return head;
}

int main()
{
	Node head;
	head = read_input();
	Tablica_djelokruga globalna;
	globalna.is_global = true;
	globalna.ugnijezdena_tablica = NULL;

	try
    {
        FRISC::pocetneInstrukcije();
        
        Stvori_novu_labelu("TEMP", "0");
        
		Prijevodna_jedinica::produkcija(head, globalna);
		
		zapisiLabele();
		zapisiKonstante();

		//Ovdje se može upisati kod za provjeru nakon obilaska
		//if(man==false && funkcija==false) //cout<<"main"<<endl;
		//else if(postoji_nedefinirana_funkcija) //cout<<"funkcija"<<endl;
	}
	catch (std::string err)
    {
		cout << err << endl;

		//BITNO:
		//Funkciju Provjeri(<znak>) iz uputa nije potrebno explicitno ostvariti
		//veæ je sasvim dovoljno obaviti throw(error) prilikom nailaska prve greske
	}

	return 0;
}
