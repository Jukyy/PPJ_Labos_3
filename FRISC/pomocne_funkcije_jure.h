#pragma once
#include <iostream>
#include <string>

using namespace std;

int string_to_int(std::string input){
	if (input[1] == '\\'){
		if (input[2] == 't')
			return (int)('\t');

		else if (input[2] == 'n')
			return (int)('\n');

		else if (input[2] == '0')
			return (int)('\0');

		else if (input[2] == '\'')
			return (int)('\'');

		else if (input[2] == '\"')
			return (int)('\"');

		else if (input[2] == '\\')
			return (int)('\\');
	}
	else {
		return (int)input[1];
	}
}

void zapisiLabele(){
	map<std::string, int>::iterator it;
	for (it = labele.begin(); it != labele.end(); it++){
		if (it->first[0] == 'V'){
			FRISC::spremiKonstantu(it->first, it->second);
		}
	}
}

void zapisiKonstante(){
	string label;
	char num[16];
	for (unsigned i = 0; i < konstante.size(); i++){
		label.clear();
		label.append("K_K_");
		sprintf(num, "%d", i);
		label.append(num);
		FRISC::spremiKonstantu(label, atoi(konstante[i].c_str()));
	}
}
