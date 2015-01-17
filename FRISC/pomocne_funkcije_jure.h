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
