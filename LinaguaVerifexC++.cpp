#include "Automat.h"
#include <map>
#include <iostream>
#include "Utilities.h"
using namespace std;



//Function to convert input into tokens
string tokenise_input (string);

//Here return Automat struct
Automat* bigDaddy_automat (Automat*);

void init_Automats(vector<Automat*>*);

bool init_Automat (vector<Automat*>*, vector<char>);

int init_object (vector<char>);//
bool init_object_sem (Automat*, vector<char>*);//

// ##### Main
int init_main (vector<char>);//
bool init_main_sem (Automat*, vector<char>*);//
int init_mainNb (vector<char>);// checks main curvedBrackets ex: {}
bool init_mainNb_sem (Automat*, vector<char>*);// if curvedBrackets correct, it deletes and handles logic
// ##### //

// ##### conditionals

//if
int init_if (Automat*, vector<char>);
bool init_if_sem (Automat*, vector<char>*);

//else
int init_else (vector<char>);
bool init_else_sem (Automat*, vector<char>*);

// ##### //

// ##### loops

//for
int init_for (vector<char>);
bool init_for_sem (Automat*, vector<char>*);

//while
int init_while (vector<char>);
bool init_while_sem (Automat*, vector<char>*);

//do while
int init_doWhile (vector<char>);
bool init_doWhile_sem (Automat*, vector<char>*);

// ##### //

// ##### vars

//int
int init_int (vector<char>);// checks if grammar and order correct
bool init_int_sem (Automat*, vector<char>*);// if grammar & order true it deletes them from input and saves their logic
int init_intNb (vector<char>);// checks digits ex: 123139
bool init_intNb_sem (Automat*, vector<char>*);// if digits correct, it deletes and handles logic

//double
int init_double (vector<char>);// checks if grammar and order correct
bool init_double_sem (Automat*, vector<char>*);
int init_doubleNb (vector<char>);// checks digits ex: 2.56
bool init_doubleNb_sem (Automat*, vector<char>*);

//float
int init_float (vector<char>);// checks if grammar and order correct
bool init_float_sem (Automat*, vector<char>*);
int init_floatNb (vector<char>);// checks digits ex: 2.56
bool init_floatNb_sem (Automat*, vector<char>*);

//char
int init_char (vector<char>);// checks if grammar and order correct
bool init_char_sem (Automat*, vector<char>*);
int init_charNb (vector<char>, bool);// checks chars ex: h
bool init_charNb_sem (Automat*, vector<char>*, bool);

//string
int init_string (vector<char>);// checks if grammar and order correct
bool init_string_sem (Automat*, vector<char>*);
int init_stringNb (vector<char>, bool);// checks string ex: hello


// ##### //

// ##### Arrays
int init_array (Automat*, vector<char>);
bool init_array_sem (Automat*, vector<char>*);

// ##### //

// #### Protection

//static
int init_static (vector<char>);
bool init_static_sem (Automat*, vector<char>*);// if grammar & order true it deletes them from input and saves their logic

//public
int init_public (vector<char>);
bool init_public_sem (Automat*, vector<char>*);// if grammar & order true it deletes them from input and saves their logic

//private
int init_private (vector<char>);
bool init_private_sem (Automat*, vector<char>*);// if grammar & order true it deletes them from input and saves their logic

//void
int init_void (vector<char>);
bool init_void_sem (Automat*, vector<char>*);// if grammar & order true it deletes them from input and saves their logic

// ##### //




//Insertion
void insertIdentifier(string *, string);
void insertQ0(string*, string);
void insertTransition(vector<Transition*>*, Transition*);
void insertTerminalState(vector<string*>*, string*);
void insertState(int*, int);


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

    cout << "Enter your c++ code to convert to java: " << endl;
    getline (cin, re);

    cout << re;

    //removing spaces from the input
    std::vector<char> newRe = convert_stringToVector (re);

    auto *re_recogniser = new vector<Automat*>;
    init_Automats(re_recogniser);

    bool test = init_Automat (re_recogniser, newRe);

    string hi = *(re_recogniser->at(4)->identifier);
    cout<<hi<<endl;

    /*for (const auto& autom : *re_recogniser) {
        std::cout << "Identifier: " << *autom->identifier << std::endl;
        // Print other members of Automat if needed
    }*/

    if (test) {
        cout << "Available language!" << endl;
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

void init_Automat_info(Automat* au, vector<Transition*>* tran, vector<Transition*>* terminal, int* states, string* identifier, string* q0){
    (au)->delta = tran;
    (au)->states = states;
    (au)->statesTerminal = reinterpret_cast<vector<std::string *> *>(terminal);
    (au)->identifier = identifier;
    (au)->q0 = q0;
}

void init_Automats(vector<Automat*>* au){
    auto* int_tran = new vector<Transition*>;
    auto* int_statesTerminal = new vector<Transition*>;
    auto* int_states = new int;
    auto* int_identifier = new string;
    auto* int_q0 = new string;

    auto* int_autom = new Automat;// <--
    init_Automat_info(int_autom, int_tran, int_statesTerminal, int_states, int_identifier, int_q0);


    auto* double_tran = new vector<Transition*>;
    auto* double_statesTerminal = new vector<Transition*>;
    auto* double_states = new int;
    auto* double_identifier = new string;
    auto* double_q0 = new string;

    auto* double_autom = new Automat;// <--
    init_Automat_info(double_autom, double_tran, double_statesTerminal, double_states, double_identifier, double_q0);

    auto* float_tran = new vector<Transition*>;
    auto* float_statesTerminal = new vector<Transition*>;
    auto* float_states = new int;
    auto* float_identifier = new string;
    auto* float_q0 = new string;
    auto* float_autom = new Automat;// <--
    init_Automat_info(float_autom, float_tran, float_statesTerminal, float_states, float_identifier, float_q0);

    auto* char_tran = new vector<Transition*>;
    auto* char_statesTerminal = new vector<Transition*>;
    auto* char_states = new int;
    auto* char_identifier = new string;
    auto* char_q0 = new string;
    auto* char_autom = new Automat;// <--
    init_Automat_info(char_autom, char_tran, char_statesTerminal, char_states, char_identifier, char_q0);

    auto* string_tran = new vector<Transition*>;
    auto* string_statesTerminal = new vector<Transition*>;
    auto* string_states = new int;
    auto* string_identifier = new string;
    auto* string_q0 = new string;
    auto* string_autom = new Automat;// <--
    init_Automat_info(string_autom, string_tran, string_statesTerminal, string_states, string_identifier, string_q0);

    auto* for_tran = new vector<Transition*>;
    auto* for_statesTerminal = new vector<Transition*>;
    auto* for_states = new int;
    auto* for_identifier = new string;
    auto* for_q0 = new string;
    auto* for_autom = new Automat;// <--
    init_Automat_info(for_autom, for_tran, for_statesTerminal, for_states, for_identifier, for_q0);

    auto* while_tran = new vector<Transition*>;
    auto* while_statesTerminal = new vector<Transition*>;
    auto* while_states = new int;
    auto* while_identifier = new string;
    auto* while_q0 = new string;
    auto* while_autom = new Automat;// <--
    init_Automat_info(while_autom, while_tran, while_statesTerminal, while_states, while_identifier, while_q0);


    auto* if_tran = new vector<Transition*>;
    auto* if_statesTerminal = new vector<Transition*>;
    auto* if_states = new int;
    auto* if_identifier = new string;
    auto* if_q0 = new string;
    auto* if_autom = new Automat;// <--
    init_Automat_info(if_autom, if_tran, if_statesTerminal, if_states, if_identifier, if_q0);

    auto* doWhile_tran = new vector<Transition*>;
    auto* doWhile_statesTerminal = new vector<Transition*>;
    auto* doWhile_states = new int;
    auto* doWhile_identifier = new string;
    auto* doWhile_q0 = new string;
    auto* doWhile_autom = new Automat;// <--
    init_Automat_info(doWhile_autom, doWhile_tran, doWhile_statesTerminal, doWhile_states, doWhile_identifier, doWhile_q0);

    auto* array_tran = new vector<Transition*>;
    auto* array_statesTerminal = new vector<Transition*>;
    auto* array_states = new int;
    auto* array_identifier = new string;
    auto* array_q0 = new string;
    auto* array_autom = new Automat;// <--
    init_Automat_info(array_autom, array_tran, array_statesTerminal, array_states, array_identifier, array_q0);

    auto* public_tran = new vector<Transition*>;
    auto* public_statesTerminal = new vector<Transition*>;
    auto* public_states = new int;
    auto* public_identifier = new string;
    auto* public_q0 = new string;
    auto* public_autom = new Automat;// <--
    init_Automat_info(public_autom, public_tran, public_statesTerminal, public_states, public_identifier, public_q0);

    auto* static_tran = new vector<Transition*>;
    auto* static_statesTerminal = new vector<Transition*>;
    auto* static_states = new int;
    auto* static_identifier = new string;
    auto* static_q0 = new string;
    auto* static_autom = new Automat;// <--
    init_Automat_info(static_autom, static_tran, static_statesTerminal, static_states, static_identifier, static_q0);

    auto* void_tran = new vector<Transition*>;
    auto* void_statesTerminal = new vector<Transition*>;
    auto* void_states = new int;
    auto* void_identifier = new string;
    auto* void_q0 = new string;
    auto* void_autom = new Automat;// <--
    init_Automat_info(void_autom, void_tran, void_statesTerminal, void_states, void_identifier, void_q0);

    auto* main_tran = new vector<Transition*>;
    auto* main_statesTerminal = new vector<Transition*>;
    auto* main_states = new int;
    auto* main_identifier = new string;
    auto* main_q0 = new string;
    auto* main_autom = new Automat;// <--
    init_Automat_info(main_autom, main_tran, main_statesTerminal, main_states, main_identifier, main_q0);

    auto* private_tran = new vector<Transition*>;
    auto* private_statesTerminal = new vector<Transition*>;
    auto* private_states = new int;
    auto* private_identifier = new string;
    auto* private_q0 = new string;
    auto* private_autom = new Automat;// <--
    init_Automat_info(private_autom, private_tran, private_statesTerminal, private_states, private_identifier, private_q0);

    auto* object_tran = new vector<Transition*>;
    auto* object_statesTerminal = new vector<Transition*>;
    auto* object_states = new int;
    auto* object_identifier = new string;
    auto* object_q0 = new string;
    auto* object_autom = new Automat;// <--
    init_Automat_info(object_autom, object_tran, object_statesTerminal, object_states, object_identifier, object_q0);

    auto* else_tran = new vector<Transition*>;
    auto* else_statesTerminal = new vector<Transition*>;
    auto* else_states = new int;
    auto* else_identifier = new string;
    auto* else_q0 = new string;
    auto* else_autom = new Automat;// <--
    init_Automat_info(else_autom, else_tran, else_statesTerminal, else_states, else_identifier, else_q0);


    au->push_back(int_autom);
    au->push_back(double_autom);
    au->push_back(float_autom);
    au->push_back(char_autom);
    au->push_back(string_autom);
    au->push_back(for_autom);
    au->push_back(while_autom);
    au->push_back(if_autom);
    au->push_back(doWhile_autom);
    au->push_back(array_autom);
    au->push_back(public_autom);
    au->push_back(static_autom);
    au->push_back(void_autom);
    au->push_back(main_autom);
    au->push_back(private_autom);
    au->push_back(object_autom);
    au->push_back(else_autom);
}


void insertTransition(vector<Transition*>* mainTransition, Transition* newTran){
    //How to fill / print info in created transition
    mainTransition->push_back(newTran);

    cout<<endl;
    cout << (mainTransition->at(0)->origin);
    cout<<endl;
}

void insertState(int* mainState, int newState){
    //How to fill / print info in created transition
    *mainState = newState;

    cout<<endl;
    cout << (mainState);
    cout<<endl;
}

void insertTerminalState(vector<string*>* mainTerminal, string* newTerminal){
    //How to fill / print info in created transition
    mainTerminal->push_back(newTerminal);

    cout<<endl;
    cout << (mainTerminal->at(0));
    cout<<endl;
}

void insertIdentifier(string *identifier, string text){
    //How to fill / print info in created identifier
    *identifier = text;

    cout<<endl;
    cout<<*(identifier);
    cout<<endl;

}

void insertQ0(string* q0, string text){
    //How to fill / print info in created identifier
    *q0 = text;

    cout<<endl;
    cout<<*(q0);
    cout<<endl;

}



bool init_Automat (vector<Automat*>* au, vector<char> input) {

    map<string, bool> allowedAutomats = {
            {"int", true},
            {"double", false},
            {"float", false},
            {"char", false},
            {"string", false},
            {"variable", false},
            {"if", true},
            {"do_while", false},
            {"while", false},
            {"for", false},
            {"main", true},
            {"array", false}
    };

    Automat* string_automat = &((*au->at(4)));
    vector<Transition*>* string_tran = (string_automat->delta);
    vector<string*>* string_terminals = (string_automat->statesTerminal);

    auto* testing = new Transition;
    testing->origin = "i";

    auto* testing2 = new string("State terminal example");

    insertIdentifier((string_automat->identifier), "Hello world");
    insertQ0(string_automat->q0, "i");
    insertTransition(string_automat->delta, testing);
    insertTerminalState(string_automat->statesTerminal, testing2);
    insertState(string_automat->states, 3);

    cout<<"How to print Q0: ";
    cout<<*string_automat->q0<<endl;

    cout<<"How to print identifier: ";
    cout<<*string_automat->identifier<<endl;


    cout<<"How to print any element in transition of automat"<<endl;
    cout<<endl;
    cout<<string_tran->at(0)->origin<<endl;

    cout<<"How to print states terminal: ";
    cout<<*string_terminals->at(0)<<endl;

    cout<<"How to print states count: ";
    cout<<*string_automat->states<<endl;


    /*cout<<"Print of Transition Origin element 0"<<endl;
    cout << (string_automat).delta->at(4)->origin;
    cout<<endl;*/


    /*// This handles stuff related to the initiation of the language conditions
    bool allValuesZero = true;
    int oneValueTrue = 0;

    for (const auto& key : allowedAutomats) {
        if (key.second) {
            allValuesZero = false;
            ++oneValueTrue;
            if (oneValueTrue > 1) {
                break;
            }

        }
    }

    // This handles the language conditions
    bool repeat = true;

    vector<char>* temp = &input;


        //This is the Main case with code inside it
        if (allowedAutomats["main"] && oneValueTrue > 1) {

            if(init_public(*temp) > -1){
                init_public_sem (au, temp);

            }
            else if (init_main (*temp)) {
                init_main_sem (au, temp);

                cout << "Entered Main" << endl;
                for (char c : *temp)
                {
                    cout << c;
                }
                do {


                    if (init_string (*temp) > -1) {
                        init_string_sem (au, temp);
                        return true;
                    }

                    else if (init_double (*temp) > -1) {
                        init_double_sem (au, temp);
                        cout << "Entered DOUBLE" << endl;

                        //Here its explode
                        int obj = init_object (*temp);
                        if (obj > 0) {
                            init_object_sem (au, temp);

                            if (init_doubleNb (*temp) > -1) {
                                init_doubleNb_sem (au, temp);

                                return true;
                            }
                            *//*else {
								return false;
							}*//*


						}
						*//*else {
							return false;
						}*//*
					}
					else if (init_float (*temp) > -1) {
						init_float_sem (au, temp);
						cout << "Entered FLOAT" << endl;

						//Here its explode
						int obj = init_object (*temp);
						if (obj > 0) {
							init_object_sem (au, temp);

							if (init_floatNb (*temp) > -1) {

								init_floatNb_sem (au, temp);

								return true;
							}
							*//*else {
								return false;
							}*//*


						}
						*//*else {
							return false;
						}*//*
					}
					else if (init_char (*temp) > -1) {
						init_char_sem (au, temp);
						cout << "Entered CHAR" << endl;

						//Here its explode
						int obj = init_object (*temp);
						if (obj > 0) {
							init_object_sem (au, temp);

							if (init_charNb (*temp, true) > -1) {

								init_charNb_sem (au, temp, true);

								return true;
							}
							*//*else {
								return false;
							}*//*


						}
						*//*else {
							return false;
						}*//*
					}
					else if (init_int (*temp) > -1) {
						cout << "Entered INT" << endl;

						for (char c : *temp)
						{
							cout << c;
						}

                        if (init_array(au, *temp) > -1) {
                            init_array_sem (au, temp);
                            return true;
                        }
						//Here its explode
						int obj = init_object (*temp);
						cout << obj;
						if (obj > 0) {
							init_object_sem (au, temp);

							if (init_intNb (*temp) > -1) {

								init_intNb_sem (au, temp);

								return true;
							}
							*//*else {
								return false;
							}*//*


						}
						*//*else {
							return false;
						}*//*

					}
					else if (init_object (*temp) > -1) {
						init_object_sem (au, temp);
						return true;
					}
					//else if (init_if (*temp)) {
					//	init_if_sem (au, temp);

					//	//Here its explode
					//	int obj = init_object (*temp);
					//	if (obj > 0) {
					//		init_object_sem (au, temp);

					//		if (init_charNb (*temp, true)) {

					//			init_charNb_sem (au, temp, true);

					//			return true;
					//		}
					//		else {
					//			return false;
					//		}


					//	}
					//	else {
					//		return false;
					//	}
					//}
					*//*else if (init_for (*temp)) {
						init_for_sem (au, temp);
					}*//*


				} while (repeat);
			}

		}
		//This is the case where user wants to just write main case
		else if (allowedAutomats["main"] && oneValueTrue == 1) {

		}
		//This is the condition where user doesnt want to write main and just wants to convert his unNested code
		else if (!allValuesZero && !allowedAutomats["main"]) {

		}
		//Program Exit because no selected Automats
		else if (allValuesZero) {
			return false;
		}

*/

    return false;




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

int init_public(vector<char> input) {
    int state = 0;
    char c;

    for (int i = 0; i < input.size (); i++) {
        c = (input)[i];

        switch (state) {

            case 0: {
                if (c == 'p') {
                    state = 1;

                }
                else {
                    return -1;
                }

            }
                break;
            case 1: {
                if (c == 'u') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;
            case 2: {
                if (c == 'b') {
                    state = 3;
                }
                else {
                    return -1;
                }

            }
                break;

            case 3: {
                if (c == 'l') {
                    state = 4;
                }
                else {
                    return -1;
                }

            }
                break;

            case 4: {
                if (c == 'i') {
                    state = 5;
                }
                else {
                    return -1;
                }

            }
                break;

            case 5: {
                if (c == 'c') {
                    state = 5;
                    return i;
                }
                else {
                    return -1;
                }

            }
                break;

        }
    }

}
bool init_public_sem (Automat* au, vector<char>* input){

    int state = 0;
    char c;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];

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
        --i;
    }

}

int init_private(vector<char> input) {
    int state = 0;
    char c;

    for (int i = 0; i < input.size (); i++) {
        c = (input)[i];

        switch (state) {

            case 0: {
                if (c == 'p') {
                    state = 1;

                }
                else {
                    return -1;
                }

            }
                break;
            case 1: {
                if (c == 'r') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;
            case 2: {
                if (c == 'i') {
                    state = 3;
                }
                else {
                    return -1;
                }

            }
                break;

            case 3: {
                if (c == 'v') {
                    state = 4;
                }
                else {
                    return -1;
                }

            }
                break;

            case 4: {
                if (c == 'a') {
                    state = 5;
                }
                else {
                    return -1;
                }

            }
                break;

            case 5: {
                if (c == 't') {
                    state = 6;
                }
                else {
                    return -1;
                }

            }
                break;

            case 6: {
                if (c == 'e') {
                    state = 6;
                    return i;
                }
                else {
                    return -1;
                }

            }
                break;

        }
    }

}
bool init_private_sem (Automat* au, vector<char>* input){

    int state = 0;
    char c;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];

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
        --i;
    }

}

int init_static(vector<char> input) {
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
                    return -1;
                }

            }
                break;
            case 1: {
                if (c == 't') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;
            case 2: {
                if (c == 'a') {
                    state = 3;
                }
                else {
                    return -1;
                }

            }
                break;

            case 3: {
                if (c == 't') {
                    state = 4;
                }
                else {
                    return -1;
                }

            }
                break;

            case 4: {
                if (c == 'i') {
                    state = 5;
                }
                else {
                    return -1;
                }

            }
                break;

            case 5: {
                if (c == 'c') {
                    state = 5;
                    return i;
                }
                else {
                    return -1;
                }

            }
                break;

        }
    }

}
bool init_static_sem (Automat* au, vector<char>* input){

    int state = 0;
    char c;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];

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
        --i;
    }

}

int init_void(vector<char> input) {
    int state = 0;
    char c;

    for (int i = 0; i < input.size (); i++) {
        c = (input)[i];

        switch (state) {

            case 0: {
                if (c == 'v') {
                    state = 1;

                }
                else {
                    return -1;
                }

            }
                break;
            case 1: {
                if (c == 'o') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;
            case 2: {
                if (c == 'i') {
                    state = 3;
                }
                else {
                    return -1;
                }

            }
                break;

            case 3: {
                if (c == 'd') {
                    state = 3;
                    return i;
                }
                else {
                    return -1;
                }

            }
                break;


        }
    }

}
bool init_void_sem (Automat* au, vector<char>* input){

    int state = 0;
    char c;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];

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
        --i;
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

int init_charNb (vector<char> input, bool isDeclaration) {

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
                    return -1;
                }
            }
                break;
            case 1: {
                if (isalpha (c) || isdigit (c) || c == ' ') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;

            case 2: {
                if (c == '\'') {
                    state = 2;
                    if (!isDeclaration) {
                        return i;
                    }
                }
                else if (c == ';') {
                    return i;
                }
                else {
                    return -1;
                }

            }
                break;
        }
    }

}


int init_floatNb (vector<char> input) {

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
                    return -1;
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
                    return -1;
                }

            }
                break;
            case 2: {
                if (isdigit (c)) {
                    state = 2;
                }
                else if (c == ';') {
                    return i;
                }
                else if (digits_counter + 1 > 7) {
                    return -1;
                }
                else {
                    return -1;
                }
            }
                break;
        }

        digits_counter++;
    }

    return -1;
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


int init_doubleNb (vector<char> input) {

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
                    return -1;
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
                    return -1;
                }

            }
                break;
            case 2: {
                if (isdigit (c)) {
                    state = 2;
                }
                else if (c == ';') {
                    return i;
                }
                else if (digits_counter + 1 > 15) {
                    return -1;
                }
                else {
                    return -1;
                }
            }
                break;
        }

        digits_counter++;
    }

    return -1;


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
        --i;
    }

    return true;


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
                if (int temp = init_object (*input) > 0) {
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
                else if (checkIfRegex (c, "-+/%*")) {
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
        --i;

    }
    return false;


}


int init_if (Automat* au, vector<char> input) {
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



int init_array (Automat* au, vector<char> input) {

    int state = 0;
    char c;
    int bracket_counter = 0;
    int curvedBracket_counter = 0;

    for (int i = 0; i < input.size (); i++) {
        c = (input)[i];
        cout << endl;
        cout << "Entered array" << endl;
        cout << c;
        switch (state) {

            case 0: {
                if (init_int (input)) {
                    init_int_sem (au, &input);

                    for (char c : input) {
                        cout << c << endl;
                    }

                    state = 1;
                }
                else if (init_double (input)) {
                    init_double_sem (au, &input);
                    state = 1;
                }
                else if (init_float (input)) {
                    init_float_sem (au, &input);
                    state = 1;
                }
                else if (init_char (input)) {
                    init_char_sem (au, &input);
                    state = 1;
                }
                else if (init_string (input)) {
                    init_string_sem (au, &input);
                    state = 1;
                }
                else {
                    return -1;
                }
            }
                break;

            case 1: {
                if (init_object(input) > -1) {
                    init_object_sem (au, &input);

                    cout<<endl;

                    for (char c : input) {
                        cout << c << endl;
                    }

                    state = 1;
                }
                else if (c == '[') {
                    state = 2;
                    bracket_counter++;
                }
                else {
                    return -1;
                }
            }
                break;

                //if its being declared
            case 2: {
                if (init_object (input)) {
                    state = 3;
                }
                else if (isdigit (c)) {
                    state = 2;
                }
                else if (c == ']') {
                    state = 4;
                    bracket_counter--;
                }
                else {
                    return -1;
                }

            }
                break;

                //if its not being declared
            case 3: {
                if (c == ']') {
                    state = 4;
                    bracket_counter--;
                }
                else {
                    return -1;
                }
            }
                break;

            case 4: {
                if (c == ';') {
                    return i;
                }
                else if (c == '=') {
                    state = 5;
                }
                else {
                    return -1;
                }

            }
                break;

            case 5: {
                if (c == '{') {
                    state = 6;
                    curvedBracket_counter++;
                }
                else if (curvedBracket_counter > 0) {
                    if (init_object (input)) {
                        return i;
                    }
                }
                else if (curvedBracket_counter == 0) {
                    init_object(input);

                }
                else if (c == '}') {
                    state = 6;
                }
                else {
                    return -1;
                }

            }
                break;

            case 6: {
                if (c == ';') {
                    return i;
                }
                else {
                    return -1;
                }
            }
        }
    }

    return -1;

}

bool init_array_sem (Automat* au, vector<char>* input) {

    int state = 0;
    char c;
    int bracket_counter = 0;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];
        input->erase (input->begin ());
        cout << endl;
        cout << "Entered array" << endl;
        cout << c;
        switch (state) {

            case 0: {
                if (init_int (*input)) {
                    init_int_sem (au, input);
                    state = 1;
                }
                else if (init_double (*input)) {
                    init_double_sem (au, input);
                    state = 1;
                }
                else if (init_float (*input)) {
                    init_float_sem (au, input);
                    state = 1;
                }
                else if (init_char (*input)) {
                    init_char_sem (au, input);
                    state = 1;
                }
                else if (init_string (*input)) {
                    init_string_sem (au, input);
                    state = 1;
                }
                else {
                    return -1;
                }
            }
                break;

            case 1: {
                if (init_object (*input) > -1) {
                    init_object_sem (au, input);
                    state = 1;
                }
                else if (c == '[') {
                    state = 2;
                }
                else {
                    return -1;
                }
            }
                break;

                //if its being declared
            case 2: {
                if (init_object (*input)) {
                    state = 3;
                }
                else if (isdigit (c)) {
                    state = 2;
                }
                else if (c == ']') {
                    state = 4;
                }
                else {
                    return -1;
                }

            }
                break;

                //if its not being declared
            case 3: {
                if (c == ']') {
                    state = 4;
                }
                else {
                    return -1;
                }
            }
                break;

            case 4: {
                if (c == ';') {
                    return i;
                }
                else if (c == '=') {
                    state = 5;
                }
                else {
                    return -1;
                }

            }
                break;

            case 5: {
                if (c == '{') {
                    state = 6;
                    bracket_counter++;
                }
                else if (bracket_counter > 0) {
                    if (init_object (*input)) {
                        return i;
                    }
                }
                else if (bracket_counter == 0) {
                    init_object (*input);

                }
                else if (c == '}') {
                    state = 6;
                }
                else {
                    return -1;
                }

            }
                break;

            case 6: {
                if (c == ';') {
                    return i;
                }
                else {
                    return -1;
                }
            }
        }
        --i;
    }

    return -1;

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


int init_float (vector<char> input) {

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
                    return -1;
                }

            }
                break;
            case 1: {
                if (c == 'l') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;
            case 2: {
                if (c == 'o') {
                    state = 3;
                }
                else {
                    return -1;
                }

            }
                break;

            case 3: {
                if (c == 'a') {
                    state = 4;
                }
                else {
                    return -1;
                }

            }
                break;

            case 4: {
                if (c == 't') {
                    state = 4;
                    return i;
                }
                else {
                    return -1;
                }

            }
                break;

        }
    }

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



int init_double (vector<char> input) {
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
                    return -1;
                }

            }
                break;
            case 1: {
                if (c == 'o') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;
            case 2: {
                if (c == 'u') {
                    state = 3;
                }
                else {
                    return -1;
                }

            }
                break;

            case 3: {
                if (c == 'b') {
                    state = 4;
                }
                else {
                    return -1;
                }

            }
                break;

            case 4: {
                if (c == 'l') {
                    state = 5;
                }
                else {
                    return -1;
                }

            }
                break;

            case 5: {
                if (c == 'e') {
                    state = 5;
                    return i;
                }
                else {
                    return -1;
                }

            }
                break;

        }
    }


}


int init_char (vector<char> input) {
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
                    return -1;
                }

            }
                break;
            case 1: {
                if (c == 'h') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;
            case 2: {
                if (c == 'a') {
                    state = 3;
                }
                else {
                    return -1;
                }

            }
                break;

            case 3: {
                if (c == 'r') {
                    state = 3;
                    return i;
                }
                else {
                    return -1;
                }

            }
                break;
        }
    }

}


int init_string (vector<char> input) {
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
                    return -1;
                }

            }
                break;
            case 1: {
                if (c == 't') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;
            case 2: {
                if (c == 'r') {
                    state = 3;
                }
                else {
                    return -1;
                }

            }
                break;

            case 3: {
                if (c == 'i') {
                    state = 4;
                }
                else {
                    return -1;
                }

            }
                break;

            case 4: {
                if (c == 'n') {
                    state = 5;
                }
                else {
                    return -1;
                }

            }
                break;

            case 5: {
                if (c == 'g') {
                    state = 5;
                    return i;
                }
                else {
                    return -1;
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
        --i;
    }
    return false;

}


int init_intNb (vector<char> input) {

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
                    return i;
                }
                else {
                    return -1;
                }

            }
                break;

        }
    }
    return -1;

}

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
                else if (checkIfRegex(c, "[];=")) {
                    return true;
                }
                else if (c == ' ') {
                    return false;
                }

            }
                break;
        }
        --i;
    }
    return false;

}


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
                else if (checkIfRegex(c, "[];=")) {
                    return i - 1;
                }
                else if (c == ' ') {
                    return -1;
                }
                else{
                    return -1;
                }
            }
                break;
        }
    }
    return -1;

}

int init_main (vector<char> input) {

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
                    return -1;
                }

            }
                break;

            case 1: {
                if (c == 'a') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;

            case 2: {
                if (c == 'i') {
                    state = 3;
                }
                else {
                    return -1;
                }

            }
                break;


            case 3: {
                if (c == 'n') {
                    state = 4;
                }
                else {
                    return -1;
                }

            }
                break;


            case 4: {
                if (c == '(') {
                    state = 5;
                }
                else {
                    return -1;
                }

            }
                break;



            case 5: {
                if (c == ')') {
                    state = 5;
                    return i;
                }
                else {
                    return -1;
                }

            }
                break;

        }
    }

    return false;

}




int init_int (vector<char> input) {

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
                    return -1;
                }

            }
                break;
            case 1: {
                if (c == 'n') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;
            case 2: {
                if (c == 't') {
                    state = 3;
                    return i;
                }
                else {
                    return -1;
                }

            }
                break;
        }
    }


}


bool init_int_sem (Automat* au, vector<char>* input) {

    int state = 0;
    char c;
    //starts with default first element
    char prev = (*input)[0];
    char next;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];
        //gets next element to save in automat
        if(i + 1 < input->size()){
            next = (*input)[i + 1];
        }

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
        prev = c;
        i--;
    }


}



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
        i--;
    }

    return false;

}