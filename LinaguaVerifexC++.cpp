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

string removeSpaces (string input);
void reAutomat_init (Automat*, string);


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

	Automat re_recogniser;
	reAutomat_init (&re_recogniser, re);





}

string removeSpaces (string input) {
	string result;

	for (char c : input) {
		if (c != ' ') {
			result += c;
		}
	}

	return result;
}


void reAutomat_init (Automat* autom, string re) {

	//counters that count for any brackets / paranthesis that are open, example: a(  / a[
	int indented_brackets = 0;
	int indented_paranthesis = 0;

	//removing spaces from the input
	re = removeSpaces (re);

	autom->q0 = re[0];

	//filling user input (RE) into the alphabet array
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
		}

		autom->delta.push_back (transition);

		alphabet_counter++;
	}

	// // Debug purpose
	for (int i = 0; i < autom->delta.size (); i++) {
		cout << autom->delta[i].label;
		cout << autom->delta[i].origin;
		cout << autom->delta[i].target;
		cout << endl;
	}

	/*char states[nbStates];					//Del this later
	Transition delta[nbTransitions];
	char statesTerminal[nbStatesTerminal];*/
	//char temp_alphabet[26] = { 'a', 'b' ,'c' ,'d' ,'e' ,'f' ,'g' ,'h' ,'i' ,'j' ,'k' ,'l' ,'m' ,'n' ,'p' ,'q' ,'r' ,'s' ,'t' ,'o' ,'u' ,'v' ,'x' ,'y' , 'z' ,'w' };


}
