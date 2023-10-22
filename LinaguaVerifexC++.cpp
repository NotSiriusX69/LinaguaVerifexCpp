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


void ReAutomat_init (Automat*);

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

	Automat re_recogniser;
	ReAutomat_init (&re_recogniser);





}

void ReAutomat_init (Automat* autom) {

	char alphabet[nbSymbols];
	char states[nbStates];
	Transition delta[nbTransitions];
	char statesTerminal[nbStatesTerminal];


	autom->q0 = '';

	char temp_alphabet[26] = { 'a', 'b' ,'c' ,'d' ,'e' ,'f' ,'g' ,'h' ,'i' ,'j' ,'k' ,'l' ,'m' ,'n' ,'p' ,'q' ,'r' ,'s' ,'t' ,'o' ,'u' ,'v' ,'x' ,'y' , 'z' ,'w' };

	for (int i = 0; i < 26; i++) {
		autom->alphabet[i] = temp_alphabet[i];
	}
	


	autom->q0 = 'c';
	autom->q0 = 'c';
	autom->q0 = 'c';
}
