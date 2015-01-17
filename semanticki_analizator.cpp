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
//TEST
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

int ProvjeriDeklaracijeUTablici(_Tablica_djelokruga globalna) {

	for (unsigned i = 0; i < globalna.lokalne_variable.size(); ++i) {
		string ime = globalna.lokalne_variable[i].ime;
		if (globalna.lokalne_variable[i].tip.find("->") != string::npos) {
			string ime_funkcije = ime.substr(0, ime.find("("));
			if (PronadiUVektoru(definicije, ime_funkcije) == -1) {
				cout << "funkcija" << endl;
				return 1; // return 1 treba prekinuti trazenje
			}
		}
	}
	for (unsigned i = 0; i < globalna.lokalne_tablice.size(); ++i) {
		if (ProvjeriDeklaracijeUTablici(globalna.lokalne_tablice[i])){
			return 1;
		}
	}
	return 0; // nije pronasao gresku
}

int main(){
	Node head;
	head = read_input();
	Tablica_djelokruga globalna;
	globalna.is_global = true;
	globalna.ugnijezdena_tablica = NULL;

	try{
		Prijevodna_jedinica::produkcija(head, globalna);

		int flag = 0;
		for (unsigned i = 0; i < globalna.lokalne_variable.size(); ++i) {
			if (globalna.lokalne_variable[i].ime == "main" && 
				globalna.lokalne_variable[i].tip == "funkcija(void->int)") {
				flag = 1;
				break;
			}
		}

		if (flag == 0) 
			cout << "main" << endl;
		else 
			ProvjeriDeklaracijeUTablici(globalna);

		//Ovdje se može upisati kod za provjeru nakon obilaska
		//if(man==false && funkcija==false) //cout<<"main"<<endl;
		//else if(postoji_nedefinirana_funkcija) //cout<<"funkcija"<<endl;
	}
	catch (std::string err){
		cout << err << endl;

		//BITNO:
		//Funkciju Provjeri(<znak>) iz uputa nije potrebno explicitno ostvariti
		//veæ je sasvim dovoljno obaviti throw(error) prilikom nailaska prve greske
	}

	return 0;
}
