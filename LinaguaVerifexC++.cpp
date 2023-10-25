//general include
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

//async include
#include <future>

//headers include
#include "JsonManip.h"
#include "Automat.h"

using namespace std;

//function to remove spaces in RE
string remove_reSpaces (string input);
//function that contains all logic to initialize an automat based on user RE
void init_reAutomat (Automat*, string);
//function that places user input RE into a char array called alphabet and then organizes the transitions between each char
void organize_reInput (Automat*, string);
//function that draws the states of the automat
void calculate_reInputStates (Automat*);
//function that translates each char into a specific token with an id
void tokenize_reInput (Automat*, int, char);
//function that checks if the input is equal to one of the specified regex elements
bool checkIfSymbol (char, string);



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

	string re;

	cout << "Enter your RE: " << endl;
	getline (cin, re);

	cout << re;
	Automat re_recogniser;
	init_reAutomat (&re_recogniser, re);





}

string remove_reSpaces (string input) {
	string result;

	for (char c : input) {
		if (c != ' ') {
			result += c;
		}
	}

	return result;
}


void init_reAutomat (Automat* autom, string re) {

	//removing spaces from the input
	re = remove_reSpaces (re);

	autom->q0 = re[0];

	//filling user input (RE) into the alphabet array
	organize_reInput (autom, re);

	//calculating states and tokenising the input that is filled in the alphabet array
	calculate_reInputStates (autom);

	// // Debug purpose
	cout << "Label - Origin - Target:" << endl;
	for (int i = 0; i < autom->delta.size (); i++) {
		cout << autom->delta[i].label << "\t";
		cout << autom->delta[i].origin << "\t";
		cout << autom->delta[i].target << "\t";
		cout << endl;

		cout << "State: " << endl;
		cout << autom->states[i];
		cout << endl;
		cout << endl;
	}

	/*char states[nbStates];					//Del this later
	Transition delta[nbTransitions];
	char statesTerminal[nbStatesTerminal];*/
	//char temp_alphabet[26] = { 'a', 'b' ,'c' ,'d' ,'e' ,'f' ,'g' ,'h' ,'i' ,'j' ,'k' ,'l' ,'m' ,'n' ,'p' ,'q' ,'r' ,'s' ,'t' ,'o' ,'u' ,'v' ,'x' ,'y' , 'z' ,'w' };


}

void organize_reInput (Automat* autom, string re) {
	int alphabet_counter = 0;

	for (int i = 0; i < re.length (); i++) {
		if (re[i] == ' ') {
			continue;
		}

		//Adding each char from user input into alphabet
		autom->alphabet[alphabet_counter] = re[i];
		cout << autom->alphabet[alphabet_counter] << endl;


		//Adding the transitions
		Transition transition;

		transition.label = re[i];

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

bool checkIfSymbol (char input, string regex) {

	for (char c : regex) {
		if (c == input) {
			return true;
		}
	}

	return false;
}

void calculate_reInputStates (Automat* autom) {
	int states_counter = 0;

	//counters that count for any brackets / paranthesis that are open, example: a(  / a[
	int opened_brackets = 0;
	int opened_paranthesis = 0;

	//calculating initial state value (for the state values and what they represent, reffer to whiteboard drawing)
	if (isalpha (autom->q0)) {
		autom->states[0] = 1;
	}
	else if (autom->q0 == '(') {
		autom->states[0] = 2;
	}
	else if (autom->q0 == '[') {
		autom->states[0] = 3;
	}
	else {
		//state -1 indicates error
		//autom->states[0] = -1;
	}


	for (int i = 0; i < autom->delta.size (); i++) {
		//filling on each iteration the values or each delta
		char origin = autom->delta[i].origin;
		char label = autom->delta[i].label;
		char target = autom->delta[i].target;

		switch (autom->states[states_counter]) {
			//alphabet char entered: [a-z]
		case 1: {
			if (isalpha (target)) {
				autom->states[states_counter + 1] = 1;
			}
			else if (target == '(') {
				autom->states[states_counter + 1] = 2;
			}
			else if (target == '[') {
				autom->states[states_counter + 1] = 3;
			}
			else if (target == ')' && (isalpha (label) || checkIfSymbol (label, "*+")) && opened_paranthesis > 0) {
				autom->states[states_counter + 1] = 5;
			}
			else if (target == ']' && isdigit (label) && opened_brackets > 0) {
				autom->states[states_counter + 1] = 6;
			}
			else if (checkIfSymbol (target, "*+")) {
				autom->states[states_counter + 1] = 7;
			}

		}
			  break;
			  //paranthesis entered: (
		case 2: {
			opened_paranthesis++;
			if (isalpha (target)) {
				autom->states[states_counter + 1] = 1;
			}
			else if (target == '(') {
				autom->states[states_counter + 1] = 2;
			}
			else if (target == '[') {
				autom->states[states_counter + 1] = 3;
			}

		}
			  break;
			  //brackets entered: [
		case 3: {
			opened_brackets++;
			if (isdigit (target)) {
				autom->states[states_counter + 1] = 4;
			}
		}
			  break;

			  //digit entered or - entered (for letters, do same but with isalpha)
		case 4: {
			if ((target == '-' && isdigit (label)) && opened_brackets > 0) {
				autom->states[states_counter + 1] = 4;
			}
			else if (label == '-' && opened_brackets > 0 && isdigit (target)) {
				autom->states[states_counter + 1] = 4;
			}
			else if (isdigit (label) && opened_brackets > 0 && target != ']') {
				autom->states[states_counter + 1] = 4;
			}
			else if (target == ']' && isdigit (label) && opened_brackets > 0) {
				autom->states[states_counter + 1] = 6;
			}
		}
			  break;

			  //paranthesis closed
		case 5: {
			opened_paranthesis--;
			if (isalpha (target)) {
				autom->states[states_counter + 1] = 1;
			}
			else if (target == '(') {
				autom->states[states_counter + 1] = 2;
			}
			else if (target == '[') {
				autom->states[states_counter + 1] = 3;
			}
			else if (checkIfSymbol (target, "*+")) {
				autom->states[states_counter + 1] = 7;
			}

		}
			  break;
			  //brackets closed
		case 6: {
			opened_brackets--;
			opened_paranthesis--;
			if (isalpha (target)) {
				autom->states[states_counter + 1] = 1;
			}
			else if (target == '(') {
				autom->states[states_counter + 1] = 2;
			}
			else if (target == '[') {
				autom->states[states_counter + 1] = 3;
			}
			else if (checkIfSymbol (target, "*+")) {
				autom->states[states_counter + 1] = 7;
			}
		}
			  break;

			  //number repetitions specifier entered (* or +)
		case 7: {
			if (isalpha (target)) {
				autom->states[states_counter + 1] = 1;
			}
			else if (target == ')' && (isalpha (label) || checkIfSymbol (label, "*+")) && opened_paranthesis > 0) {
				autom->states[states_counter + 1] = 5;
			}
			else if (target == '(') {
				autom->states[states_counter + 1] = 2;
			}
			else if (target == '[') {
				autom->states[states_counter + 1] = 3;
			}

		}
			  break;


		default: {
			cout << "Error" << endl;
		}
			   break;


		}


		states_counter++;
	}
}

void tokenize_reInput (Automat*, int, char) {

}
