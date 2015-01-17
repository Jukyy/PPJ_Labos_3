#pragma once
#include <string>
#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

int BrojAcsiZnakova(std::string str);

std::string skini(std::string str, std::string zaSkinuti) {
	if (str.find(zaSkinuti) == 0) {
		str = str.substr(zaSkinuti.length() + 1);
		str = str.substr(0, str.find_last_of(")"));
	}
	return str;
}
bool NalaziSeUVektoru(vector<Znakovi> vector, std::string str,int br = 0, std::string znak = "") {
	for (unsigned i = 0; i < vector.size(); ++i) {
		if (!vector[i].ime.compare(str)) {
			if (br == 0) {
				return true;
			}
			else {
				return !(vector[i].tip.compare(znak));
			}
		}
	}
	return false;
}

std::string vratiTrecistring(std::string str) {
	std::string localstring = str;
	if (localstring.find(" ") != std::string::npos) {
		localstring = localstring.substr(localstring.find(" ") + 1);
	}
	if (localstring.find(" ") != std::string::npos) {
		localstring = localstring.substr(localstring.find(" ") + 1);
	}
	return localstring;
}
void greskaUmijesto(std::string str1, std::string str2) {
	cerr << "Greska, sljedece nije" << str1 << " vec  " << str2 << "." << endl;
}
void parametriGreska(std::string str1, int brpar) {
	cerr << "YO, Greška, YO (produkcija " << str1 <<" ima " << brpar << "produkcija." << endl;
}
namespace MojaKlasa {
		void method1() {
			//cout << 1 << endl;
		}

};

pair<std::string, int> DuljinaNiza(Node pocetna) {

	if (!pocetna.zavrsni) {
		if (pocetna.nodes.size() != 0) {
			return make_pair(std::string("ERROR"), -1);
		}
		else return DuljinaNiza(pocetna.nodes[0]);
	}
	else {
		pair<std::string, int> zaReturnati;
		if (pocetna.znak.compare(0, strlen("BROJ"), "BROJ")) { 
			zaReturnati.first = "int";
			zaReturnati.second = -1;
		}
		else if (pocetna.znak.compare(0, strlen("ZNAK"), "ZNAK")) { 
			zaReturnati.first = "char";
			zaReturnati.second = -1;
		}
		else if (pocetna.znak.compare(0, strlen("NIZ_ZNAKOVA"), "NIZ_ZNAKOVA")) {
			zaReturnati.first = "niz(const(char))";
			std::string Znakovi = pocetna.znak;
			Znakovi = Znakovi.substr(Znakovi.find(" "));
			Znakovi = Znakovi.substr(Znakovi.find(" "));

			zaReturnati.second = BrojAcsiZnakova(Znakovi); 
		}
		return zaReturnati;
	}
}

int BrojAcsiZnakova(std::string str) {
	int brojac = 0;
	bool prefiksiran = false;
	char dopusteni[] = { 't', 'n', '0', '\'', '\"', '\\'};
	for (unsigned i = 0; i < str.size(); ++i) {
		if (prefiksiran) {
			int j;
			for (j = 0; j < sizeof(dopusteni) / sizeof(dopusteni[0]); ++j)
			{
				if (str.at(i) == dopusteni[j]) {
					break;
				}
			}
			if (j == sizeof(dopusteni) / sizeof(dopusteni[0])) {
				return -1; //DOSLO JE DO GRESKE!!!!
			}
			brojac++;
			prefiksiran = false;
		}
		else {
			if (str.at(i) == '\\') {
				prefiksiran = true;
			}
			else {
				brojac++;
			}
		}
	}
	return brojac;
}
