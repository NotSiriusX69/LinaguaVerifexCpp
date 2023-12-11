#pragma once
#include <vector>
using namespace std;

//Grammar checking functions:
// 
//Object random name
int init_object (vector<char>);//

//conditionals
bool init_if (vector<char>);
bool init_else (vector<char>);
bool init_switch (vector<char>); // WIlL NOT BE DONE

//loops
bool init_for (vector<char>);
bool init_while (vector<char>);
bool init_doWhile (vector<char>);

//vars
bool init_int (vector<char>);//
bool init_intNb (vector<char>);//
bool init_double (vector<char>);//
bool init_doubleNb (vector<char>);//
bool init_float (vector<char>);//
bool init_floatNb (vector<char>);//
bool init_char (vector<char>);//
bool init_charNb (vector<char>, bool);//

bool init_string (vector<char>);//
bool init_stringNb (vector<char>, bool);//

bool init_main (vector<char>);//
bool init_array (vector<char>);//

//functions
bool init_static (vector<char>);
bool init_public (vector<char>);
bool init_private (vector<char>);
bool init_void (vector<char>);



int init_object (vector<char> input) {

	int state = 0;
	char c;

	for (int i = 0; i < input.size (); i++) {
		c = (input)[i];

		switch (state) {

		case 0: {
			if (isalpha (c)) {
				state = 1;
			}
			else {
				return -1;
			}
		}
			  break;
		case 1: {
			if (isalpha (c) || isdigit (c)) {
				state = 1;
			}
			else if (c == ';') {
				return 0;
			}
			else if (c == ' ') {
				return -1;
			}
			else {
				return i;
			}
		}
			  break;
		}
	}
	return 0;

}


bool init_if (vector<char> input) {
	int state = 0;
	char c;
	int parenthesis_counter = 0;
	int equal_counter = 0;

	for (int i = 0; i < input.size (); i++) {
		c = (input)[i];


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
			if (int temp = init_object (input) > 0) {
				for (int i = 0; i < temp; i++) {
					input.erase (input.begin ());
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
			else if (checkIfRegex (c, "-+/%*")) {
				state = 3;
			}
			else if (equal_counter == 2 && init_object (input)) {
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


bool init_int (vector<char> input) {

	int state = 0;
	char c;

	for (int i = 0; i < input.size (); i++) {
		c = (input)[i];


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

bool init_intNb (vector<char> input) {

	int state = 0;
	char d;

	for (int i = 0; i < input.size (); i++) {
		d = (input)[i];

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

bool init_floatNb (vector<char> input) {

	int state = 0;
	char c;
	int digits_counter = 0;

	for (int i = 0; i < input.size (); i++) {
		c = (input)[i];


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

bool init_float (vector<char> input) {

	int state = 0;
	char c;

	for (int i = 0; i < input.size (); i++) {
		c = (input)[i];

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

bool init_doubleNb (vector<char> input) {

	int state = 0;
	char c;
	int digits_counter = 0;

	for (int i = 0; i < input.size (); i++) {
		c = (input)[i];

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

bool init_double (vector<char> input) {

	int state = 0;
	char c;

	for (int i = 0; i < input.size (); i++) {
		c = (input)[i];

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

bool init_char (vector<char> input) {
	int state = 0;
	char c;

	for (int i = 0; i < input.size (); i++) {
		c = (input)[i];

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

bool init_charNb (vector<char> input, bool isDeclaration) {

	int state = 0;
	char c;

	for (int i = 0; i < input.size (); i++) {
		c = (input)[i];

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

bool init_string (vector<char> input) {
	int state = 0;
	char c;

	for (int i = 0; i < input.size (); i++) {
		c = (input)[i];

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

bool init_stringNb (vector<char> input, bool isDeclaration) {

	int state = 0;
	char c;
	int openedString = 0;

	for (int i = 0; i < input.size (); i++) {
		c = (input)[i];

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
bool init_main (vector<char> input) {

	int state = 0;
	char c;

	for (int i = 0; i < input.size (); i++) {
		c = (input)[i];

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