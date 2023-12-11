#pragma once

#include <vector>
#include "GrammarCheckers.h"


using namespace std;

//All automats inits

//Object random name
bool init_object_sem (Automat*, vector<char>*);//

//conditionals
bool init_if_sem (Automat*, vector<char>*);//
bool init_else_sem (Automat*, vector<char>*);
bool init_switch_sem (Automat*, vector<char>*); // WILL NOT BE DONE

//loops
bool init_for_sem (Automat*, vector<char>*);
bool init_while_sem (Automat*, vector<char>*);
bool init_doWhile_sem (Automat*, vector<char>*);

//vars
bool init_int_sem (Automat*, vector<char>*);//
bool init_intNb_sem (Automat*, vector<char>*);//

bool init_double_sem (Automat*, vector<char>*);//
bool init_doubleNb_sem (Automat*, vector<char>*);//

bool init_float_sem (Automat*, vector<char>*);//
bool init_floatNb_sem (Automat*, vector<char>*);//

bool init_char_sem (Automat*, vector<char>*);//
bool init_charNb_sem (Automat*, vector<char>*, bool);//

bool init_string_sem (Automat*, vector<char>*);//
bool init_stringNb_sem (Automat*, vector<char>*, bool);//

bool init_main_sem (Automat*, vector<char>*);//
bool init_array_sem (Automat*, vector<char>*);//

//functions
bool init_static_sem (Automat*, vector<char>*);//
bool init_public_sem (Automat*, vector<char>*);//
bool init_private_sem (Automat*, vector<char>*);//
bool init_void_sem (Automat*, vector<char>*);//




bool init_object_sem (Automat* au, vector<char>* input) {

	int state = 0;
	char c;

	for (int i = 0; i < input->size (); i++) {
		c = (*input)[i];
		input->erase (input->begin ());

		switch (state) {

		case 0: {
			if (isalpha (c)) {
				state = 1;
			}
			else {
				return false;
			}
		}
			  break;
		case 1: {
			if (isalpha (c) || isdigit (c)) {
				state = 1;
			}
			else if (c == ';') {
				return true;
			}
			else if (c == ' ') {
				return false;
			}

		}
			  break;
		}
	}
	return true;

}



bool init_static_sem (Automat* au, vector<char>* input) {

	int state = 0;
	char c;

	for (int i = 0; i < input->size (); i++) {
		c = (*input)[i];
		input->erase (input->begin ());


		switch (state) {

		case 0: {
			if (c == 's') {
				state = 1;

			}
			else {
				return false;
			}

		}
			  break;
		case 1: {
			if (c == 't') {
				state = 2;
			}
			else {
				return false;
			}

		}
			  break;
		case 2: {
			if (c == 'a') {
				state = 3;
			}
			else {
				return false;
			}

		}
			  break;

		case 3: {
			if (c == 't') {
				state = 4;
			}
			else {
				return false;
			}

		}
			  break;

		case 4: {
			if (c == 'i') {
				state = 5;
			}
			else {
				return false;
			}

		}
			  break;

		case 5: {
			if (c == 'c') {
				state = 5;
				return true;
			}
			else {
				return false;
			}
		}
			  break;
		}
	}

}


bool init_if_sem (Automat* au, vector<char>* input) {
	int state = 0;
	char c;
	int parenthesis_counter = 0;
	int equal_counter = 0;

	for (int i = 0; i < input->size (); i++) {
		c = (*input)[i];
		input->erase (input->begin ());


		switch (state) {

		case 0: {
			if (c == 'i') {
				state = 1;

			}
			else {
				return false;
			}

		}
			  break;
		case 1: {
			if (c == 'f') {
				state = 2;
			}
			else {
				return false;
			}

		}
			  break;
		case 2: {
			if (c == '(') {
				state = 3;
				parenthesis_counter++;
			}
			else {
				return false;
			}

		}
			  break;

		case 3: {
			if (int temp = init_object(*input) > 0) {
				for (int i = 0; i < temp; i++) {
					input->erase (input->begin ());
				}
				state = 4;
			}
			else if (c == '=' && equal_counter == 1) {
				state = 4;
				equal_counter++;
			}
			else {
				return false;
			}

		}
			  break;

		case 4: {
			if (c == '=' && equal_counter < 2) {
				state = 3;
				equal_counter++;
			}
			else if (checkIfRegex(c, "-+/%*")) {
				state = 3;
			}
			else if (equal_counter == 2 && init_object (*input)) {
				state = 5;

			}
			else {
				return false;
			}

		}
			  break;

		case 5: {
			if (c == ')') {
				state = 5;
				parenthesis_counter--;
				return true;
			}
			else {
				return false;
			}

		}
			  break;
		}
		
	}
	return false;


}

bool init_public_sem (Automat* au, vector<char>* input) {

	int state = 0;
	char c;

	for (int i = 0; i < input->size (); i++) {
		c = (*input)[i];
		input->erase (input->begin ());


		switch (state) {

		case 0: {
			if (c == 'p') {
				state = 1;

			}
			else {
				return false;
			}

		}
			  break;
		case 1: {
			if (c == 'u') {
				state = 2;
			}
			else {
				return false;
			}

		}
			  break;
		case 2: {
			if (c == 'b') {
				state = 3;
			}
			else {
				return false;
			}

		}
			  break;

		case 3: {
			if (c == 'l') {
				state = 4;
			}
			else {
				return false;
			}

		}
			  break;

		case 4: {
			if (c == 'i') {
				state = 5;
			}
			else {
				return false;
			}

		}
			  break;

		case 5: {
			if (c == 'c') {
				state = 5;
				return true;
			}
			else {
				return false;
			}
		}
			  break;
		}
	}

}

bool init_private_sem (Automat* au, vector<char>* input) {

	int state = 0;
	char c;

	for (int i = 0; i < input->size (); i++) {
		c = (*input)[i];
		input->erase (input->begin ());


		switch (state) {

		case 0: {
			if (c == 'p') {
				state = 1;

			}
			else {
				return false;
			}

		}
			  break;
		case 1: {
			if (c == 'r') {
				state = 2;
			}
			else {
				return false;
			}

		}
			  break;
		case 2: {
			if (c == 'i') {
				state = 3;
			}
			else {
				return false;
			}

		}
			  break;

		case 3: {
			if (c == 'v') {
				state = 4;
			}
			else {
				return false;
			}

		}
			  break;

		case 4: {
			if (c == 'a') {
				state = 5;
			}
			else {
				return false;
			}

		}
			  break;

		case 5: {
			if (c == 't') {
				state = 6;
			}
			else {
				return false;
			}
		}
			  break;

		case 6: {
			if (c == 'e') {
				state = 6;
				return true;
			}
			else {
				return false;
			}
		}
			  break;
		}
	}

}

bool init_void_sem (Automat* au, vector<char>* input) {

	int state = 0;
	char c;

	for (int i = 0; i < input->size (); i++) {
		c = (*input)[i];
		input->erase (input->begin ());


		switch (state) {

		case 0: {
			if (c == 'v') {
				state = 1;

			}
			else {
				return false;
			}

		}
			  break;
		case 1: {
			if (c == 'o') {
				state = 2;
			}
			else {
				return false;
			}

		}
			  break;
		case 2: {
			if (c == 'i') {
				state = 3;
			}
			else {
				return false;
			}

		}
			  break;

		case 3: {
			if (c == 'd') {
				state = 3;
				return true;
			}
			else {
				return false;
			}

		}
			  break;
		}
	}

}


bool init_int_sem (Automat* au, vector<char>* input) {

	int state = 0;
	char c;

	for (int i = 0; i < input->size (); i++) {
		c = (*input)[i];
		input->erase (input->begin ());


		switch (state) {

		case 0: {
			if (c == 'i') {
				state = 1;

			}
			else {
				return false;
			}

		}
			  break;
		case 1: {
			if (c == 'n') {
				state = 2;
			}
			else {
				return false;
			}

		}
			  break;
		case 2: {
			if (c == 't') {
				state = 3;
				return true;
			}
			else {
				return false;
			}

		}
			  break;
		}
		i--;
	}


}

bool init_intNb_sem (Automat* au, vector<char>* input) {

	int state = 0;
	char d;

	for (int i = 0; i < input->size (); i++) {
		d = (*input)[i];
		input->erase (input->begin ());

		switch (state) {

		case 0: {
			if (isdigit (d)) {
				state = 0;
			}
			else if (d == ';') {
				return true;
			}
			else {
				return false;
			}

		}
			  break;

		}
	}
	return false;

}

bool init_floatNb_sem (Automat* au, vector<char>* input) {

	int state = 0;
	char c;
	int digits_counter = 0;

	for (int i = 0; i < input->size (); i++) {
		c = (*input)[i];
		input->erase (input->begin ());

		switch (state) {

		case 0: {
			if (isdigit (c)) {
				state = 1;
			}
			else {
				return false;
			}

		}
			  break;
		case 1: {
			if (isdigit (c)) {
				state = 1;
			}
			else if (c == '.') {
				state = 2;
			}
			else {
				return false;
			}

		}
			  break;
		case 2: {
			if (isdigit (c)) {
				state = 2;
			}
			else if (c == ';') {
				return true;
			}
			else if (digits_counter + 1 > 7) {
				return false;
			}
			else {
				return false;
			}
		}
			  break;
		}

		digits_counter++;
	}

	return true;


}

bool init_float_sem (Automat* au, vector<char>* input) {

	int state = 0;
	char c;

	for (int i = 0; i < input->size (); i++) {
		c = (*input)[i];
		input->erase (input->begin ());

		switch (state) {

		case 0: {
			if (c == 'f') {
				state = 1;

			}
			else {
				return false;
			}

		}
			  break;
		case 1: {
			if (c == 'l') {
				state = 2;
			}
			else {
				return false;
			}

		}
			  break;
		case 2: {
			if (c == 'o') {
				state = 3;
			}
			else {
				return false;
			}

		}
			  break;

		case 3: {
			if (c == 'a') {
				state = 4;
			}
			else {
				return false;
			}

		}
			  break;

		case 4: {
			if (c == 't') {
				state = 4;
				return true;
			}
			else {
				return false;
			}

		}
			  break;

		}
	}

}

bool init_doubleNb_sem (Automat* au, vector<char>* input) {

	int state = 0;
	char c;
	int digits_counter = 0;

	for (int i = 0; i < input->size (); i++) {
		c = (*input)[i];
		input->erase (input->begin ());

		switch (state) {

		case 0: {
			if (isdigit (c)) {
				state = 1;
			}
			else {
				return false;
			}

		}
			  break;
		case 1: {
			if (isdigit (c)) {
				state = 1;
			}
			else if (c == '.') {
				state = 2;
			}
			else {
				return false;
			}

		}
			  break;
		case 2: {
			if (isdigit (c)) {
				state = 2;
			}
			else if (c == ';') {
				return true;
			}
			else if (digits_counter + 1 > 15) {
				return false;
			}
			else {
				return false;
			}
		}
			  break;
		}

		digits_counter++;
	}

	return true;


}

bool init_double_sem (Automat* au, vector<char>* input) {

	int state = 0;
	char c;

	for (int i = 0; i < input->size (); i++) {
		c = (*input)[i];
		input->erase (input->begin ());

		switch (state) {

		case 0: {
			if (c == 'd') {
				state = 1;

			}
			else {
				return false;
			}

		}
			  break;
		case 1: {
			if (c == 'o') {
				state = 2;
			}
			else {
				return false;
			}

		}
			  break;
		case 2: {
			if (c == 'u') {
				state = 3;
			}
			else {
				return false;
			}

		}
			  break;

		case 3: {
			if (c == 'b') {
				state = 4;
			}
			else {
				return false;
			}

		}
			  break;

		case 4: {
			if (c == 'l') {
				state = 5;
			}
			else {
				return false;
			}

		}
			  break;

		case 5: {
			if (c == 'e') {
				state = 5;
				return true;
			}
			else {
				return false;
			}

		}
			  break;

		}
	}


}

bool init_char_sem (Automat* au, vector<char>* input) {
	int state = 0;
	char c;

	for (int i = 0; i < input->size (); i++) {
		c = (*input)[i];
		input->erase (input->begin ());

		switch (state) {

		case 0: {
			if (c == 'c') {
				state = 1;

			}
			else {
				return false;
			}

		}
			  break;
		case 1: {
			if (c == 'h') {
				state = 2;
			}
			else {
				return false;
			}

		}
			  break;
		case 2: {
			if (c == 'a') {
				state = 3;
			}
			else {
				return false;
			}

		}
			  break;

		case 3: {
			if (c == 'r') {
				state = 3;
				return true;
			}
			else {
				return false;
			}

		}
			  break;
		}
	}

}

bool init_charNb_sem (Automat* au, vector<char>* input, bool isDeclaration) {

	int state = 0;
	char c;

	for (int i = 0; i < input->size (); i++) {
		c = (*input)[i];
		input->erase (input->begin ());

		switch (state) {

		case 0: {
			if (c == '\'') {
				state = 1;
			}
			else {
				return false;
			}
		}
			  break;
		case 1: {
			if (isalpha (c) || isdigit (c) || c == ' ') {
				state = 2;
			}
			else {
				return false;
			}

		}
			  break;

		case 2: {
			if (c == '\'') {
				state = 2;
				if (!isDeclaration) {
					return true;
				}
			}
			else if (c == ';') {
				return true;
			}
			else {
				return false;
			}

		}
			  break;
		}
	}

}

bool init_string_sem (Automat* au, vector<char>* input) {
	int state = 0;
	char c;

	for (int i = 0; i < input->size (); i++) {
		c = (*input)[i];
		input->erase (input->begin ());

		switch (state) {

		case 0: {
			if (c == 's') {
				state = 1;

			}
			else {
				return false;
			}

		}
			  break;
		case 1: {
			if (c == 't') {
				state = 2;
			}
			else {
				return false;
			}

		}
			  break;
		case 2: {
			if (c == 'r') {
				state = 3;
			}
			else {
				return false;
			}

		}
			  break;

		case 3: {
			if (c == 'i') {
				state = 4;
			}
			else {
				return false;
			}

		}
			  break;

		case 4: {
			if (c == 'n') {
				state = 5;
			}
			else {
				return false;
			}

		}
			  break;

		case 5: {
			if (c == 'g') {
				state = 5;
				return true;
			}
			else {
				return false;
			}

		}
			  break;

		}
	}

}

bool init_stringNb_sem (Automat* au, vector<char>* input, bool isDeclaration) {

	int state = 0;
	char c;
	int openedString = 0;

	for (int i = 0; i < input->size (); i++) {
		c = (*input)[i];
		input->erase (input->begin ());

		switch (state) {

		case 0: {
			if (c == '\"') {
				state = 1;
				openedString++;
			}
			else {
				return false;
			}
		}
			  break;
		case 1: {
			if (isalpha (c) || isdigit (c) || c == ' ') {
				state = 2;
			}
			else if (c == '\"') {
				openedString--;
				state = 2;
			}
			else {
				return false;
			}

		}
			  break;

		case 2: {
			if (c == '\"') {
				state = 2;

				if (openedString == 0) {
					++openedString;
				}
				else {
					--openedString;
				}

				if (!isDeclaration && openedString == 0) {
					return true;
				}
			}
			else if (c == ';') {
				return true;
			}
			else if (openedString != 0 && (isdigit (c) || isalpha (c))) {
				state = 2;
			}
			else {
				return false;
			}

		}
			  break;
		}
	}

}

//continue fixing the brackets
bool init_main_sem (Automat* au, vector<char>* input) {

	int state = 0;
	char c;

	for (int i = 0; i < input->size (); i++) {
		c = (*input)[i];
		input->erase (input->begin ());

		switch (state) {

		case 0: {
			if (c == 'm') {
				state = 1;
			}
			else {
				return false;
			}

		}
			  break;

		case 1: {
			if (c == 'a') {
				state = 2;
			}
			else {
				return false;
			}

		}
			  break;

		case 2: {
			if (c == 'i') {
				state = 3;
			}
			else {
				return false;
			}

		}
			  break;


		case 3: {
			if (c == 'n') {
				state = 4;
			}
			else {
				return false;
			}

		}
			  break;


		case 4: {
			if (c == '(') {
				state = 5;
			}
			else {
				return false;
			}

		}
			  break;



		case 5: {
			if (c == ')') {
				state = 5;
				return true;
			}
			else {
				return false;
			}

		}
			  break;

		}
	}

	return false;

}


bool init_array_sem (Automat* au, vector<char>* input) {

	int state = 0;
	char c;
	int bracket_counter = 0;

	for (int i = 0; i < input->size (); i++) {
		c = (*input)[i];
		input->erase (input->begin ());



		switch (state) {

		case 0: {
			if (init_int (*input) || init_double (*input) || init_float (*input) || init_char (*input) || init_string (*input)) {
				state = 1;
			}
			else {
				return false;
			}
		}
			  break;

		case 1: {
			if (c == '[') {
				state = 2;
			}
			else {
				return false;
			}
		}
			  break;

		//if its being declared
		case 2: {
			if (init_object_sem (au, input)) {
				state = 3;

			}
			else {
				return false;
			}

		}
			  break;

		//if its not being declared
		case 3: {
			if (c == ']') {
				state = 4;
			}
			else {
				return false;
			}
		}
			  break;

		case 4: {
			if (c == ';') {
				return true;
			}
			else if (c == '=') {
				state = 5;
			}
			else {
				return false;
			}

		}
			  break;

		case 5: {
			if (c == '{') {
				state = 6;
				bracket_counter++;
			}
			else if (bracket_counter > 0) {
				if (init_object_sem (au, input)) {
					return true;
				}
			}
			else if(bracket_counter == 0){
				init_object_sem (au, input);
				
			}
			else if (c == '}') {
				state = 6;
			}
			else {
				return false;
			}

		}
			  break;

		case 6: {
			if (c == ';') {
				return true;
			}
			else {
				return false;
			}
		}
		}
	}

	return false;

}