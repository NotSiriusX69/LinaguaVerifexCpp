//general include
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

//async include
#include <future>

//headers include
#include "JsonManip.h"
#include "Automat.h"
#include "utilities.h"


using namespace std;

//function that contains all logic to initialize an automat based on user RE
bool init_Automat (Automat*, vector<char>);

//function that places user input RE into a char array called alphabet
void init_automatAlphabet (Automat*, string);

//function that converts the alphabet of automat into multiple blocks of chars and puts them in transitions based on user input
//of states and transitions
void init_reToTransitionsBlocks (Automat*, vector<Transition>*);

//function that adds the transitions
void init_reTransitions (Automat* autom, string re);

//function that translates each regex into a specific token with an id
void tokenize_reInput (Automat*, int, char);


//All automats inits

//Object random name
bool init_object (Automat*, vector<char>*);//

//conditionals
bool init_if (Automat*, vector<char>);
bool init_else (Automat*, vector<char>);
bool init_switch (Automat*, vector<char>);

//loops
bool init_for (Automat*, vector<char>);
bool init_while (Automat*, vector<char>);
bool init_doWhile (Automat*, vector<char>);

//vars
bool init_int (Automat*, vector<char>*);//
bool init_intNb (Automat*, vector<char>*);//
bool init_double (Automat*, vector<char>*);//
bool init_doubleNb (Automat*, vector<char>*);//
bool init_float (Automat*, vector<char>*);//
bool init_floatNb (Automat*, vector<char>*);//
bool init_char (Automat*, vector<char>*);//
bool init_charNb (Automat*, vector<char>*, bool);//

bool init_string (Automat*, vector<char>*);//
bool init_stringNb (Automat*, vector<char>*, bool);//

bool init_main (Automat*, vector<char>);
bool init_array (Automat*, vector<char>);

//functions
bool init_static (Automat*, vector<char>);
bool init_public (Automat*, vector<char>);
bool init_private (Automat*, vector<char>);
bool init_void (Automat*, vector<char>);



int main ()
{

	//call c;
	//string file_path = "data/trigger.json";

	//ifstream f (file_path);
	//json data = json::parse (f);

	//future<void> asyncTrigger = async (&readFileOnInit, &c, file_path);

	////testing response
	//string response;
	//int keep = 0;
	//do
	//{
	//	cout << " do you want to send response: ";
	//	cin >> response;
	//	cout << endl;
	//	if (response == "yes") {
	//		sendResponse (file_path, data);
	//	}
	//	else {
	//		cout << "no response" << endl;
	//	}

	//	cout << "keep going: (0 to keep going)";
	//	cin >> keep;
	//	if (keep != 1 || keep != 0) {
	//		keep = 1;
	//	}

	//} while (keep == 0);

	if (int i = 0 < 9) {
		cout << "Its smaller";
	}

	string re;

	cout << "Enter your c++ code to convert to java: " << endl;
	getline (cin, re);

	cout << re;

	//removing spaces from the input
	std::vector<char> newRe = convert_stringToVector (re);

	Automat re_recogniser[100];

	bool test = init_Automat (re_recogniser, newRe);

	if (test) {
		cout << "AVailable language!" << endl;
	}
	else {
		cout << "Not available language!" << endl;
	}

	//init_Automat (re_recogniser, &re);





	//Testing functions: convert_vectorToArr() and convert_arrToVector()

	/*init_reTransitions (&re_recogniser, "HelloWorld");
	cout << re_recogniser.delta[0].regexBlock;

	Transition* transArr = convert_vectorToArr (re_recogniser.delta);

	cout << transArr[0].regexBlock;*/

}


bool init_object (Automat* au, vector<char>* input) {

	int state = 0;
	char c;

	for (int i = 0; i < input->size (); i++) {
		c = (*input)[i];
		input->erase (input->begin ());

		switch (state) {

		case 0: {
			if (isalpha(c)) {
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
			else if(c== ';') {
				return true;
			}
			else if(c== ' ') {
				return false;
			}

		}
			  break;
		}
	}
	return true;

}


bool init_int (Automat* au, vector<char>* input) {

	int state = 0;
	char c;

	for (int i = 0; i < input->size(); i++) {
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

bool init_intNb (Automat* au, vector<char>* input) {

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

bool init_floatNb (Automat* au, vector<char>* input) {

	int state = 0;
	char c;
	int digits_counter = 0;

	for (int i = 0; i < input->size (); i++) {
		c = (*input)[i];
		input->erase (input->begin ());

		switch (state) {

		case 0: {
			if (isdigit(c)) {
				state = 1;
			}
			else {
				return false;
			}

		}
			  break;
		case 1: {
			if (isdigit(c)) {
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
			if (isdigit(c)) {
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

bool init_float (Automat* au, vector<char>* input) {

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

bool init_doubleNb (Automat* au, vector<char>* input) {

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

bool init_double (Automat* au, vector<char>* input) {

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

bool init_char (Automat* au, vector<char>* input) {
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

bool init_charNb (Automat* au, vector<char>* input, bool isDeclaration) {

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

bool init_string (Automat* au, vector<char>* input) {
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

bool init_stringNb (Automat* au, vector<char>* input, bool isDeclaration) {

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


bool init_Automat (Automat* autom, vector<char> input) {

	vector<char>* temp = &input;

	for (int i = 0; i < 1; i++) {
		//if case initialization
		if (init_int (autom, temp)) {

			
			if (init_object (autom, temp)) {
				char c = (*temp)[0];

				if (c == '=') {
					temp->erase (temp->begin ());
					//Handle here stuff related to = , which means add the = to be recognised later
				}
				if (init_intNb (autom, temp)) {
					cout << "Entered" << endl;
					return true;

				}
				else {
					return false;
				}
				

			}
			else {
				return false;
			}
		}
		else {
			cout << "Entered the dungeon" << endl;
			return false;
		}

	}

	for (char c : (*temp)) {
		cout << c << ' ';
	}

	return true;

	

	
	// // Debug purpose
	/*cout << "Label - Origin - Target:" << endl;
	for (int i = 0; i < autom->delta.size (); i++) {
		cout << autom->delta[i].regexBlock << "\t";
		cout << autom->delta[i].origin << "\t";
		cout << autom->delta[i].target << "\t";
		cout << endl;

		cout << "State: " << endl;
		cout << autom->states[i];
		cout << endl;
		cout << endl;
	}*/

	/*char states[nbStates];					//Del this later
	Transition delta[nbTransitions];
	char statesTerminal[nbStatesTerminal];*/
	//char temp_alphabet[26] = { 'a', 'b' ,'c' ,'d' ,'e' ,'f' ,'g' ,'h' ,'i' ,'j' ,'k' ,'l' ,'m' ,'n' ,'p' ,'q' ,'r' ,'s' ,'t' ,'o' ,'u' ,'v' ,'x' ,'y' , 'z' ,'w' };


}

void init_automatAlphabet (Automat* autom, string re) {
	int alphabet_counter = 0;

	for (int i = 0; i < re.length (); i++) {
		//if (re[i] == ' ') {
		//	continue;
		//}

		//Adding each char from user input into alphabet
		autom->alphabet[alphabet_counter] = re[i];
		cout << autom->alphabet[alphabet_counter] << endl;


		alphabet_counter++;

		
	}
}

void init_reToTransitionsBlocks (Automat* autom, vector<Transition>* transitionsArr) {

}

//Old automat that reads regex
//void init_reToTransitionsBlocks (Automat* autom, vector<Transition>* transitionsArr) {
//
//	//counters that count for any brackets / paranthesis that are open, example: a(  / a[
//	int opened_brackets = 0;
//	int opened_paranthesis = 0;
//
//	char q0 = autom->q0;
//
//	//state that we should enter in the upcoming iteration
//	int enterState = 0;
//
//	for (int i = 0; i < autom->alphabet.size(); i++) {
//		//filling on each iteration the values or each delta
//		if (i > 0) {
//			char prevChar = autom->alphabet[i - 1];
//		}
//
//		char currentChar = 'k';
//		if (i < autom->alphabet.size () - 1) {
//			char nextChar = autom->alphabet[i + 1];
//		}
//
//		int target = 0;
//
//		int states_counter = 0;
//
//
//		switch (enterState) {
//			//alphabet char entered: [a-z]
//		case 1: {
//			if (isalpha (target)) {
//				autom->states[states_counter + 1] = 1;
//			}
//			else if (target == '(') {
//				autom->states[states_counter + 1] = 2;
//			}
//			else if (target == '[') {
//				autom->states[states_counter + 1] = 3;
//			}
//			else if (target == ')' && (isalpha (label) || checkIfSymbol (label, "*+")) && opened_paranthesis > 0) {
//				autom->states[states_counter + 1] = 5;
//			}
//			else if (target == ']' && isdigit (label) && opened_brackets > 0) {
//				autom->states[states_counter + 1] = 6;
//			}
//			else if (checkIfSymbol (target, "*+")) {
//				autom->states[states_counter + 1] = 7;
//			}
//
//		}
//			  break;
//			  //paranthesis entered: (
//		case 2: {
//			opened_paranthesis++;
//			if (isalpha (target)) {
//				autom->states[states_counter + 1] = 1;
//			}
//			else if (target == '(') {
//				autom->states[states_counter + 1] = 2;
//			}
//			else if (target == '[') {
//				autom->states[states_counter + 1] = 3;
//			}
//
//		}
//			  break;
//			  //brackets entered: [
//		case 3: {
//			opened_brackets++;
//			if (isdigit (target)) {
//				autom->states[states_counter + 1] = 4;
//			}
//		}
//			  break;
//
//			  //digit entered or - entered (for letters, do same but with isalpha)
//		case 4: {
//			if ((target == '-' && isdigit (label)) && opened_brackets > 0) {
//				autom->states[states_counter + 1] = 4;
//			}
//			else if (label == '-' && opened_brackets > 0 && isdigit (target)) {
//				autom->states[states_counter + 1] = 4;
//			}
//			else if (isdigit (label) && opened_brackets > 0 && target != ']') {
//				autom->states[states_counter + 1] = 4;
//			}
//			else if (target == ']' && isdigit (label) && opened_brackets > 0) {
//				autom->states[states_counter + 1] = 6;
//			}
//		}
//			  break;
//
//			  //paranthesis closed
//		case 5: {
//			opened_paranthesis--;
//			if (isalpha (target)) {
//				autom->states[states_counter + 1] = 1;
//			}
//			else if (target == '(') {
//				autom->states[states_counter + 1] = 2;
//			}
//			else if (target == '[') {
//				autom->states[states_counter + 1] = 3;
//			}
//			else if (checkIfSymbol (target, "*+")) {
//				autom->states[states_counter + 1] = 7;
//			}
//
//		}
//			  break;
//			  //brackets closed
//		case 6: {
//			opened_brackets--;
//			opened_paranthesis--;
//			if (isalpha (target)) {
//				autom->states[states_counter + 1] = 1;
//			}
//			else if (target == '(') {
//				autom->states[states_counter + 1] = 2;
//			}
//			else if (target == '[') {
//				autom->states[states_counter + 1] = 3;
//			}
//			else if (checkIfSymbol (target, "*+")) {
//				autom->states[states_counter + 1] = 7;
//			}
//		}
//			  break;
//
//			  //number repetitions specifier entered (* or +)
//		case 7: {
//			if (isalpha (target)) {
//				autom->states[states_counter + 1] = 1;
//			}
//			else if (target == ')' && (isalpha (label) || checkIfSymbol (label, "*+")) && opened_paranthesis > 0) {
//				autom->states[states_counter + 1] = 5;
//			}
//			else if (target == '(') {
//				autom->states[states_counter + 1] = 2;
//			}
//			else if (target == '[') {
//				autom->states[states_counter + 1] = 3;
//			}
//
//		}
//			  break;
//
//
//		default: {
//			cout << "Error" << endl;
//		}
//			   break;
//
//
//		}
//
//
//		states_counter++;
//	}
//}

void tokenize_reInput (Automat* autom, int, char) {

}

//to fix later
void init_reTransitions (Automat* autom, string re) {
	//Adding the transitions
	int alphabet_counter = 0;

	for (int i = 0; i < re.length (); i++) {
		Transition transition;

		transition.regexBlock = re[i];

		//has to be done so its not out of bounds
		if (alphabet_counter != 0) {
			transition.origin = autom->alphabet[alphabet_counter - 1];
			//Tyo add the last target because the for loop will never get to it
			if (i + 1 <= re.length () - 1) {
				transition.target = re[i + 1];
			}

		}
		else {
			transition.origin = re[0];
			transition.target = re[1];
		}

		autom->delta.push_back (transition);

		alphabet_counter++;
	}
}


