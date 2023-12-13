#include "Declarations/Automat.h"
#include <map>
#include <iostream>
#include "Declarations/utilities.h"
#include "Declarations/Insersion.h"
#include "Declarations/Variables.h"
#include "Declarations/Protection.h"


using namespace std;

//Function to convert input into tokens
string tokenise_input (string);

//Here return Automat struct
Automat* bigDaddy_automat (Automat*);

void init_Automats(vector<Automat*>*);

bool init_Automat (vector<Automat*>*, vector<char>);

bool init_check_symbol(vector<char>*);


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

//Main function that contains all automat logic
bool init_Automat (vector<Automat*>* au, vector<char> input) {

    map<string, bool> allowedAutomats = {
            {"int", true},
            {"double", true},
            {"float", true},
            {"char", true},
            {"string", false},
            {"variable", false},
            {"if", false},
            {"do_while", false},
            {"while", false},
            {"for", false},
            {"main", false},
            {"array", false}
    };

    //This is used to save all created objects and their values
    //Ex: int nb = 6;

    //type: int => nb
    //value: nb => 6
    auto* createdObjectsTypes = new map<string, string>;
    auto* createdObjectsValues = new map<string, string>;

    Automat* int_automat = &((*au->at(0)));
    Automat* double_automat = &((*au->at(1)));
    Automat* float_automat = &((*au->at(2)));
    Automat* char_automat = &((*au->at(3)));
    Automat* string_automat = &((*au->at(4)));

    Automat* for_automat = &((*au->at(5)));
    Automat* while_automat = &((*au->at(6)));
    Automat* if_automat = &((*au->at(7)));
    Automat* doWhile_automat = &((*au->at(8)));
    Automat* array_automat = &((*au->at(9)));

    Automat* public_automat = &((*au->at(10)));
    Automat* static_automat = &((*au->at(11)));
    Automat* void_automat = &((*au->at(12)));
    Automat* main_automat = &((*au->at(13)));
    Automat* private_automat = &((*au->at(14)));

    Automat* object_automat = &((*au->at(15)));
    Automat* else_automat = &((*au->at(16)));

    vector<Transition*>* string_tran = (string_automat->delta);
    vector<Transition*>* int_tran = (int_automat->delta);
    vector<string*>* string_terminals = (string_automat->statesTerminal);

    auto* int_state_0 = new Transition;
    int_state_0->origin = "i";
    int_state_0->current = "i";
    int_state_0->target = "n";

    auto* int_state_1 = new Transition;
    int_state_1->origin = "i";
    int_state_1->current = "n";
    int_state_1->target = "t";

    auto* int_state_2 = new Transition;
    int_state_2->origin = "n";
    int_state_2->current = "t";
    int_state_2->target = "t";

    insertTransition(int_automat->delta, int_state_0);
    insertTransition(int_automat->delta, int_state_1);
    insertTransition(int_automat->delta, int_state_2);

    auto* testing2 = new string("State terminal example");

    insertIdentifier((string_automat->identifier), "Hello world");
    insertQ0(string_automat->q0, "i");
    insertTerminalState(string_automat->statesTerminal, testing2);
    insertState(string_automat->states, 3);

    //insertObject(createdObjects, "int", "6");

    cout<<"How to print Q0: ";
    cout<<*string_automat->q0<<endl;

    cout<<"How to print identifier: ";
    cout<<*string_automat->identifier<<endl;


    cout<<"How to print any element in transition of automat"<<endl;
    cout<<endl;
    cout<<int_tran->at(0)->origin<<endl;

    cout<<"How to print states terminal: ";
    cout<<*string_terminals->at(0)<<endl;

    cout<<"How to print states count: ";
    cout<<*string_automat->states<<endl;


    /*cout<<"Print of Transition Origin element 0"<<endl;
    cout << (string_automat).delta->at(4)->origin;
    cout<<endl;*/


    // This handles stuff related to the initiation of the language conditions
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
    auto* tempForSacrifice = new vector<char>(*temp);

    bool safeToCopy = false;
    bool acceptableInput = false;



    //This is the Main case with code inside it
    if (allowedAutomats["main"] && oneValueTrue > 1) {

        if(init_public(*temp) > -1){
            init_public_sem (public_automat, temp);

        }
        else if (init_main (*temp)) {
            init_main_sem (main_automat, temp);

            cout << "Entered Main" << endl;
            /*for (char c : *temp)
            {
                cout << c;
            }*/
            do {
                *tempForSacrifice = *temp;

                safeToCopy = false;

                cout<<"Printing output: "<<endl;
                for (char c : *temp)
                {
                    cout << c;
                }
                cout<<endl;


                /*if (init_string (*tempForSacrifice) > -1) {
                    init_string_sem (string_automat, tempForSacrifice);
                    *temp = *tempForSacrifice;
                    safeToCopy = true;
                }else{
                    *tempForSacrifice = *temp;
                    safeToCopy = false;
                }

                if(safeToCopy){
                    *temp = *tempForSacrifice;
                }
                else{
                    *tempForSacrifice = *temp;
                }*/

                if(allowedAutomats["double"]){
                    if (init_double (*tempForSacrifice) > -1) {
                        acceptableInput = true;
                        init_double_sem (double_automat, tempForSacrifice);
                        cout << "Entered DOUBLE" << endl;

                        //Here its explode
                        int obj = init_object (*tempForSacrifice);
                        if (obj > 0) {
                            string concatObj;
                            for(int i = 0; i < init_object(*tempForSacrifice); i++){
                                concatObj += tempForSacrifice->at(i);
                            }
                            insertObjectType(createdObjectsTypes, concatObj, "double");

                            init_object_sem (object_automat, tempForSacrifice);

                            if (init_doubleNb (*tempForSacrifice) > -1) {
                                string concatValue;
                                for(int i = 0; i < init_doubleNb(*tempForSacrifice); i++){
                                    concatValue += tempForSacrifice->at(i);
                                }
                                insertObjectValue(createdObjectsValues, concatObj, concatValue);

                                init_doubleNb_sem (double_automat, tempForSacrifice);
                                *temp = *tempForSacrifice;
                                safeToCopy = true;
                            }else{
                                *tempForSacrifice = *temp;
                                safeToCopy = false;
                            }


                        }else{
                            *tempForSacrifice = *temp;
                            safeToCopy = false;
                        }

                    }else{
                        *tempForSacrifice = *temp;
                        safeToCopy = false;
                    }
                }
                if(safeToCopy){
                    *temp = *tempForSacrifice;
                }
                else{
                    *tempForSacrifice = *temp;
                }

                if(allowedAutomats["float"]){
                    if (init_float (*tempForSacrifice) > -1) {
                        acceptableInput = true;
                        init_float_sem (float_automat, tempForSacrifice);
                        cout << "Entered FLOAT" << endl;

                        //Here its explode
                        int obj = init_object (*tempForSacrifice);
                        if (obj > 0) {
                            string concatObj;
                            for(int i = 0; i < init_object(*tempForSacrifice); i++){
                                concatObj += tempForSacrifice->at(i);
                            }
                            insertObjectType(createdObjectsTypes, concatObj, "float");

                            init_object_sem (object_automat, tempForSacrifice);

                            if (init_floatNb (*tempForSacrifice) > -1) {
                                string concatValue;
                                for(int i = 0; i < init_floatNb(*tempForSacrifice); i++){
                                    concatValue += tempForSacrifice->at(i);
                                }
                                insertObjectValue(createdObjectsValues, concatObj, concatValue);

                                init_floatNb_sem (float_automat, tempForSacrifice);
                                *temp = *tempForSacrifice;
                                safeToCopy = true;
                            }else{
                                *tempForSacrifice = *temp;
                                safeToCopy = false;
                            }

                        }else{
                            *tempForSacrifice = *temp;
                            safeToCopy = false;
                        }

                    }else{
                        *tempForSacrifice = *temp;
                        safeToCopy = false;
                    }


                }
                if(safeToCopy){
                    *temp = *tempForSacrifice;
                }
                else{
                    *tempForSacrifice = *temp;
                }



                if(allowedAutomats["char"]){
                    if (init_char (*tempForSacrifice) > -1) {
                        acceptableInput = true;
                        init_char_sem (char_automat, tempForSacrifice);
                        cout << "Entered CHAR" << endl;

                        //Here its explode
                        int obj = init_object (*tempForSacrifice);
                        if (obj > 0) {
                            string concatObj;
                            for(int i = 0; i < init_object(*tempForSacrifice); i++){
                                concatObj += tempForSacrifice->at(i);
                            }
                            insertObjectType(createdObjectsTypes, concatObj, "char");

                            init_object_sem (object_automat, tempForSacrifice);

                            if (init_charNb (*tempForSacrifice, true) > -1) {
                                string concatValue;
                                for(int i = 0; i < init_charNb(*tempForSacrifice, true); i++){
                                    concatValue += tempForSacrifice->at(i);
                                }
                                insertObjectValue(createdObjectsValues, concatObj, concatValue);

                                init_charNb_sem (char_automat, tempForSacrifice, true);
                                *temp = *tempForSacrifice;
                                safeToCopy = true;
                            }else{
                                *tempForSacrifice = *temp;
                                safeToCopy = false;

                            }

                        }else{
                            *tempForSacrifice = *temp;
                            safeToCopy = false;

                        }



                    }
                    else{
                        *tempForSacrifice = *temp;
                        safeToCopy = false;

                    }
                }
                if(safeToCopy){
                    *temp = *tempForSacrifice;
                }
                else{
                    *tempForSacrifice = *temp;
                }


                /*if (init_object (*tempForSacrifice) > -1) {
                    init_object_sem (object_automat, tempForSacrifice);
                    *temp = *tempForSacrifice;
                    safeToCopy = true;
                }
                else{
                    *tempForSacrifice = *temp;
                    safeToCopy = false;
                }

                if(safeToCopy){
                    *temp = *tempForSacrifice;
                }
                else{
                    *tempForSacrifice = *temp;
                }*/


                /*if (init_if (if_automat, *tempForSacrifice) > -1) {
                    init_if_sem (if_automat, tempForSacrifice);

                    //Here its explode
                    int obj = init_object (*tempForSacrifice);
                    if (obj > 0) {
                        init_object_sem (object_automat, tempForSacrifice);

                        if (init_charNb (*tempForSacrifice, true)) {

                            init_charNb_sem (char_automat, tempForSacrifice, true);
                            *temp = *tempForSacrifice;
                            safeToCopy = true;
                        }else{
                            *tempForSacrifice = *temp;
                            safeToCopy = false;
                        }

                    }else{
                        *tempForSacrifice = *temp;
                        safeToCopy = false;
                    }



                }
                else{
                    *tempForSacrifice = *temp;
                    safeToCopy = false;
                }

                if(safeToCopy){
                    *temp = *tempForSacrifice;
                }
                else{
                    *tempForSacrifice = *temp;
                }*/

                /*else if (init_for (*tempForSacrifice)) {
                    init_for_sem (for_automat, tempForSacrifice);
                }*/
                if(allowedAutomats["array"]){
                    if (init_array(array_automat, *tempForSacrifice) > -1) {
                        acceptableInput = true;
                        cout<<"Entered Array"<<endl;
                        init_array_sem (array_automat, tempForSacrifice);
                        *temp = *tempForSacrifice;
                        safeToCopy = true;
                    }else{
                        *tempForSacrifice = *temp;
                        safeToCopy = false;
                    }
                }
                if(safeToCopy){
                    *temp = *tempForSacrifice;
                }
                else{
                    *tempForSacrifice = *temp;
                }

                if(allowedAutomats["int"]){
                    acceptableInput = true;
                    if(init_int(*tempForSacrifice) > -1){
                        init_int_sem(int_automat, tempForSacrifice);
                        cout<<"Enterer INT"<<endl;

                        if(init_object(*tempForSacrifice) > -1){
                            string concatObj;
                            for(int i = 0; i < init_object(*tempForSacrifice); i++){
                                concatObj += tempForSacrifice->at(i);
                            }
                            insertObjectType(createdObjectsTypes, concatObj, "int");
                            init_object_sem(object_automat, tempForSacrifice);

                            cout<<"Entered before symbol"<<endl;

                            cout<<"Entered after symbol"<<endl;

                            if(init_intNb(*tempForSacrifice) > -1){
                                string concatValue;
                                for(int i = 0; i < init_intNb(*tempForSacrifice); i++){
                                    concatValue += tempForSacrifice->at(i);
                                }
                                insertObjectValue(createdObjectsValues, concatObj, concatValue);

                                init_intNb_sem(int_automat, tempForSacrifice);
                                *temp = *tempForSacrifice;
                                safeToCopy = true;

                                string typeObj = getObjectType(createdObjectsTypes, concatObj);
                                string valueObj = getObjectValue(createdObjectsValues, concatObj);

                                cout<<endl;
                                cout<<"Object type is: " <<  typeObj  <<endl;
                                cout<<"Object value is: " <<  valueObj  <<endl;
                            }else{
                                *tempForSacrifice = *temp;
                                safeToCopy = false;
                            }


                        }else{
                            *tempForSacrifice = *temp;
                            safeToCopy = false;
                        }


                    }else{
                        *tempForSacrifice = *temp;
                        safeToCopy = false;
                    }
                }
                if(safeToCopy){
                    *temp = *tempForSacrifice;
                }
                else{
                    *tempForSacrifice = *temp;
                }


                if(temp->empty()){
                    repeat = false;
                    return true;
                }

                cout<<"Sacrifice: "<<endl;
                for (char c : *temp)
                {
                    cout << c;
                }
                cout<<endl;


                if(safeToCopy){
                    *temp = *tempForSacrifice;
                }
                else{
                    *tempForSacrifice = *temp;
                }

                if(!acceptableInput){
                    return false;
                }

            } while (repeat);
        }

    }
        //This is the case where user wants to just write main case
    else if (allowedAutomats["main"] && oneValueTrue == 1) {

        if(init_public(*temp) > -1){
            init_public_sem (public_automat, temp);

        }
        else if (init_main (*temp)) {
            init_main_sem (main_automat, temp);

            cout << "Entered Main" << endl;
            /*for (char c : *temp)
            {
                cout << c;
            }*/
            do {
                *tempForSacrifice = *temp;

                safeToCopy = false;

                cout<<"Printing output: "<<endl;
                for (char c : *temp)
                {
                    cout << c;
                }
                cout<<endl;


                /*if (init_string (*tempForSacrifice) > -1) {
                    init_string_sem (string_automat, tempForSacrifice);
                    *temp = *tempForSacrifice;
                    safeToCopy = true;
                }else{
                    *tempForSacrifice = *temp;
                    safeToCopy = false;
                }

                if(safeToCopy){
                    *temp = *tempForSacrifice;
                }
                else{
                    *tempForSacrifice = *temp;
                }*/

                if(allowedAutomats["double"]){
                    if (init_double (*tempForSacrifice) > -1) {
                        acceptableInput = true;
                        init_double_sem (double_automat, tempForSacrifice);
                        cout << "Entered DOUBLE" << endl;

                        //Here its explode
                        int obj = init_object (*tempForSacrifice);
                        if (obj > 0) {
                            string concatObj;
                            for(int i = 0; i < init_object(*tempForSacrifice); i++){
                                concatObj += tempForSacrifice->at(i);
                            }
                            insertObjectType(createdObjectsTypes, concatObj, "double");

                            init_object_sem (object_automat, tempForSacrifice);

                            if (init_doubleNb (*tempForSacrifice) > -1) {
                                string concatValue;
                                for(int i = 0; i < init_doubleNb(*tempForSacrifice); i++){
                                    concatValue += tempForSacrifice->at(i);
                                }
                                insertObjectValue(createdObjectsValues, concatObj, concatValue);

                                init_doubleNb_sem (double_automat, tempForSacrifice);
                                *temp = *tempForSacrifice;
                                safeToCopy = true;
                            }else{
                                *tempForSacrifice = *temp;
                                safeToCopy = false;
                            }


                        }else{
                            *tempForSacrifice = *temp;
                            safeToCopy = false;
                        }

                    }else{
                        *tempForSacrifice = *temp;
                        safeToCopy = false;
                    }
                }
                if(safeToCopy){
                    *temp = *tempForSacrifice;
                }
                else{
                    *tempForSacrifice = *temp;
                }

                if(allowedAutomats["float"]){
                    if (init_float (*tempForSacrifice) > -1) {
                        acceptableInput = true;
                        init_float_sem (float_automat, tempForSacrifice);
                        cout << "Entered FLOAT" << endl;

                        //Here its explode
                        int obj = init_object (*tempForSacrifice);
                        if (obj > 0) {
                            string concatObj;
                            for(int i = 0; i < init_object(*tempForSacrifice); i++){
                                concatObj += tempForSacrifice->at(i);
                            }
                            insertObjectType(createdObjectsTypes, concatObj, "float");

                            init_object_sem (object_automat, tempForSacrifice);

                            if (init_floatNb (*tempForSacrifice) > -1) {
                                string concatValue;
                                for(int i = 0; i < init_floatNb(*tempForSacrifice); i++){
                                    concatValue += tempForSacrifice->at(i);
                                }
                                insertObjectValue(createdObjectsValues, concatObj, concatValue);

                                init_floatNb_sem (float_automat, tempForSacrifice);
                                *temp = *tempForSacrifice;
                                safeToCopy = true;
                            }else{
                                *tempForSacrifice = *temp;
                                safeToCopy = false;
                            }

                        }else{
                            *tempForSacrifice = *temp;
                            safeToCopy = false;
                        }

                    }else{
                        *tempForSacrifice = *temp;
                        safeToCopy = false;
                    }


                }
                if(safeToCopy){
                    *temp = *tempForSacrifice;
                }
                else{
                    *tempForSacrifice = *temp;
                }



                if(allowedAutomats["char"]){
                    if (init_char (*tempForSacrifice) > -1) {
                        acceptableInput = true;
                        init_char_sem (char_automat, tempForSacrifice);
                        cout << "Entered CHAR" << endl;

                        //Here its explode
                        int obj = init_object (*tempForSacrifice);
                        if (obj > 0) {
                            string concatObj;
                            for(int i = 0; i < init_object(*tempForSacrifice); i++){
                                concatObj += tempForSacrifice->at(i);
                            }
                            insertObjectType(createdObjectsTypes, concatObj, "char");

                            init_object_sem (object_automat, tempForSacrifice);

                            if (init_charNb (*tempForSacrifice, true) > -1) {
                                string concatValue;
                                for(int i = 0; i < init_charNb(*tempForSacrifice, true); i++){
                                    concatValue += tempForSacrifice->at(i);
                                }
                                insertObjectValue(createdObjectsValues, concatObj, concatValue);

                                init_charNb_sem (char_automat, tempForSacrifice, true);
                                *temp = *tempForSacrifice;
                                safeToCopy = true;
                            }else{
                                *tempForSacrifice = *temp;
                                safeToCopy = false;

                            }

                        }else{
                            *tempForSacrifice = *temp;
                            safeToCopy = false;

                        }



                    }
                    else{
                        *tempForSacrifice = *temp;
                        safeToCopy = false;

                    }
                }
                if(safeToCopy){
                    *temp = *tempForSacrifice;
                }
                else{
                    *tempForSacrifice = *temp;
                }


                /*if (init_object (*tempForSacrifice) > -1) {
                    init_object_sem (object_automat, tempForSacrifice);
                    *temp = *tempForSacrifice;
                    safeToCopy = true;
                }
                else{
                    *tempForSacrifice = *temp;
                    safeToCopy = false;
                }

                if(safeToCopy){
                    *temp = *tempForSacrifice;
                }
                else{
                    *tempForSacrifice = *temp;
                }*/


                /*if (init_if (if_automat, *tempForSacrifice) > -1) {
                    init_if_sem (if_automat, tempForSacrifice);

                    //Here its explode
                    int obj = init_object (*tempForSacrifice);
                    if (obj > 0) {
                        init_object_sem (object_automat, tempForSacrifice);

                        if (init_charNb (*tempForSacrifice, true)) {

                            init_charNb_sem (char_automat, tempForSacrifice, true);
                            *temp = *tempForSacrifice;
                            safeToCopy = true;
                        }else{
                            *tempForSacrifice = *temp;
                            safeToCopy = false;
                        }

                    }else{
                        *tempForSacrifice = *temp;
                        safeToCopy = false;
                    }



                }
                else{
                    *tempForSacrifice = *temp;
                    safeToCopy = false;
                }

                if(safeToCopy){
                    *temp = *tempForSacrifice;
                }
                else{
                    *tempForSacrifice = *temp;
                }*/

                /*else if (init_for (*tempForSacrifice)) {
                    init_for_sem (for_automat, tempForSacrifice);
                }*/
                if(allowedAutomats["array"]){
                    if (init_array(array_automat, *tempForSacrifice) > -1) {
                        acceptableInput = true;
                        cout<<"Entered Array"<<endl;
                        init_array_sem (array_automat, tempForSacrifice);
                        *temp = *tempForSacrifice;
                        safeToCopy = true;
                    }else{
                        *tempForSacrifice = *temp;
                        safeToCopy = false;
                    }
                }
                if(safeToCopy){
                    *temp = *tempForSacrifice;
                }
                else{
                    *tempForSacrifice = *temp;
                }

                if(allowedAutomats["int"]){
                    if(init_int(*tempForSacrifice) > -1){
                        acceptableInput = true;
                        init_int_sem(int_automat, tempForSacrifice);
                        cout<<"Enterer INT"<<endl;

                        if(init_object(*tempForSacrifice) > -1){
                            string concatObj;
                            for(int i = 0; i < init_object(*tempForSacrifice); i++){
                                concatObj += tempForSacrifice->at(i);
                            }
                            insertObjectType(createdObjectsTypes, concatObj, "int");
                            init_object_sem(object_automat, tempForSacrifice);

                            cout<<"Entered before symbol"<<endl;

                            cout<<"Entered after symbol"<<endl;

                            if(init_intNb(*tempForSacrifice) > -1){
                                string concatValue;
                                for(int i = 0; i < init_intNb(*tempForSacrifice); i++){
                                    concatValue += tempForSacrifice->at(i);
                                }
                                insertObjectValue(createdObjectsValues, concatObj, concatValue);

                                init_intNb_sem(int_automat, tempForSacrifice);
                                *temp = *tempForSacrifice;
                                safeToCopy = true;

                                string typeObj = getObjectType(createdObjectsTypes, concatObj);
                                string valueObj = getObjectValue(createdObjectsValues, concatObj);

                                cout<<endl;
                                cout<<"Object type is: " <<  typeObj  <<endl;
                                cout<<"Object value is: " <<  valueObj  <<endl;
                            }else{
                                *tempForSacrifice = *temp;
                                safeToCopy = false;
                            }


                        }else{
                            *tempForSacrifice = *temp;
                            safeToCopy = false;
                        }


                    }else{
                        *tempForSacrifice = *temp;
                        safeToCopy = false;
                    }
                }
                if(safeToCopy){
                    *temp = *tempForSacrifice;
                }
                else{
                    *tempForSacrifice = *temp;
                }


                if(temp->empty()){
                    repeat = false;
                    return true;
                }

                cout<<"Sacrifice: "<<endl;
                for (char c : *temp)
                {
                    cout << c;
                }
                cout<<endl;


                if(safeToCopy){
                    *temp = *tempForSacrifice;
                }
                else{
                    *tempForSacrifice = *temp;
                }

                if(!acceptableInput){
                    return false;
                }


            } while (repeat);
        }

    }
        //This is the condition where user doesnt want to write main and just wants to convert his unNested code
    else if (!allValuesZero && !allowedAutomats["main"]) {
        do {
            *tempForSacrifice = *temp;

            safeToCopy = false;

            cout<<"Printing output: "<<endl;
            for (char c : *temp)
            {
                cout << c;
            }
            cout<<endl;


            /*if (init_string (*tempForSacrifice) > -1) {
                init_string_sem (string_automat, tempForSacrifice);
                *temp = *tempForSacrifice;
                safeToCopy = true;
            }else{
                *tempForSacrifice = *temp;
                safeToCopy = false;
            }

            if(safeToCopy){
                *temp = *tempForSacrifice;
            }
            else{
                *tempForSacrifice = *temp;
            }*/

            if(allowedAutomats["double"]){
                if (init_double (*tempForSacrifice) > -1) {
                    acceptableInput = true;
                    init_double_sem (double_automat, tempForSacrifice);
                    cout << "Entered DOUBLE" << endl;

                    //Here its explode
                    int obj = init_object (*tempForSacrifice);
                    if (obj > 0) {
                        string concatObj;
                        for(int i = 0; i < init_object(*tempForSacrifice); i++){
                            concatObj += tempForSacrifice->at(i);
                        }
                        insertObjectType(createdObjectsTypes, concatObj, "double");

                        init_object_sem (object_automat, tempForSacrifice);

                        if (init_doubleNb (*tempForSacrifice) > -1) {
                            string concatValue;
                            for(int i = 0; i < init_doubleNb(*tempForSacrifice); i++){
                                concatValue += tempForSacrifice->at(i);
                            }
                            insertObjectValue(createdObjectsValues, concatObj, concatValue);

                            init_doubleNb_sem (double_automat, tempForSacrifice);
                            *temp = *tempForSacrifice;
                            safeToCopy = true;
                        }else{
                            *tempForSacrifice = *temp;
                            safeToCopy = false;
                        }


                    }else{
                        *tempForSacrifice = *temp;
                        safeToCopy = false;
                    }

                }else{
                    *tempForSacrifice = *temp;
                    safeToCopy = false;
                }
            }
            if(safeToCopy){
                *temp = *tempForSacrifice;
            }
            else{
                *tempForSacrifice = *temp;
            }

            if(allowedAutomats["float"]){
                if (init_float (*tempForSacrifice) > -1) {
                    acceptableInput = true;
                    init_float_sem (float_automat, tempForSacrifice);
                    cout << "Entered FLOAT" << endl;

                    //Here its explode
                    int obj = init_object (*tempForSacrifice);
                    if (obj > 0) {
                        string concatObj;
                        for(int i = 0; i < init_object(*tempForSacrifice); i++){
                            concatObj += tempForSacrifice->at(i);
                        }
                        insertObjectType(createdObjectsTypes, concatObj, "float");

                        init_object_sem (object_automat, tempForSacrifice);

                        if (init_floatNb (*tempForSacrifice) > -1) {
                            string concatValue;
                            for(int i = 0; i < init_floatNb(*tempForSacrifice); i++){
                                concatValue += tempForSacrifice->at(i);
                            }
                            insertObjectValue(createdObjectsValues, concatObj, concatValue);

                            init_floatNb_sem (float_automat, tempForSacrifice);
                            *temp = *tempForSacrifice;
                            safeToCopy = true;
                        }else{
                            *tempForSacrifice = *temp;
                            safeToCopy = false;
                        }

                    }else{
                        *tempForSacrifice = *temp;
                        safeToCopy = false;
                    }

                }else{
                    *tempForSacrifice = *temp;
                    safeToCopy = false;
                }


            }
            if(safeToCopy){
                *temp = *tempForSacrifice;
            }
            else{
                *tempForSacrifice = *temp;
            }

            if(allowedAutomats["char"]){
                if (init_char (*tempForSacrifice) > -1) {
                    acceptableInput = true;
                    init_char_sem (char_automat, tempForSacrifice);
                    cout << "Entered CHAR" << endl;

                    //Here its explode
                    int obj = init_object (*tempForSacrifice);
                    if (obj > 0) {
                        string concatObj;
                        for(int i = 0; i < init_object(*tempForSacrifice); i++){
                            concatObj += tempForSacrifice->at(i);
                        }
                        insertObjectType(createdObjectsTypes, concatObj, "char");

                        init_object_sem (object_automat, tempForSacrifice);

                        if (init_charNb (*tempForSacrifice, true) > -1) {
                            string concatValue;
                            for(int i = 0; i < init_charNb(*tempForSacrifice, true); i++){
                                concatValue += tempForSacrifice->at(i);
                            }
                            insertObjectValue(createdObjectsValues, concatObj, concatValue);

                            init_charNb_sem (char_automat, tempForSacrifice, true);
                            *temp = *tempForSacrifice;
                            safeToCopy = true;
                        }else{
                            *tempForSacrifice = *temp;
                            safeToCopy = false;

                        }

                    }else{
                        *tempForSacrifice = *temp;
                        safeToCopy = false;

                    }


                }
                else{
                    *tempForSacrifice = *temp;
                    safeToCopy = false;

                }
            }
            if(safeToCopy){
                *temp = *tempForSacrifice;
            }
            else{
                *tempForSacrifice = *temp;
            }


            /*if (init_object (*tempForSacrifice) > -1) {
                init_object_sem (object_automat, tempForSacrifice);
                *temp = *tempForSacrifice;
                safeToCopy = true;
            }
            else{
                *tempForSacrifice = *temp;
                safeToCopy = false;
            }

            if(safeToCopy){
                *temp = *tempForSacrifice;
            }
            else{
                *tempForSacrifice = *temp;
            }*/


            /*if (init_if (if_automat, *tempForSacrifice) > -1) {
                init_if_sem (if_automat, tempForSacrifice);

                //Here its explode
                int obj = init_object (*tempForSacrifice);
                if (obj > 0) {
                    init_object_sem (object_automat, tempForSacrifice);

                    if (init_charNb (*tempForSacrifice, true)) {

                        init_charNb_sem (char_automat, tempForSacrifice, true);
                        *temp = *tempForSacrifice;
                        safeToCopy = true;
                    }else{
                        *tempForSacrifice = *temp;
                        safeToCopy = false;
                    }

                }else{
                    *tempForSacrifice = *temp;
                    safeToCopy = false;
                }



            }
            else{
                *tempForSacrifice = *temp;
                safeToCopy = false;
            }

            if(safeToCopy){
                *temp = *tempForSacrifice;
            }
            else{
                *tempForSacrifice = *temp;
            }*/

            /*else if (init_for (*tempForSacrifice)) {
                init_for_sem (for_automat, tempForSacrifice);
            }*/
            if(allowedAutomats["array"]){
                if (init_array(array_automat, *tempForSacrifice) > -1) {
                    acceptableInput = true;
                    cout<<"Entered Array"<<endl;
                    init_array_sem (array_automat, tempForSacrifice);
                    *temp = *tempForSacrifice;
                    safeToCopy = true;
                }else{
                    *tempForSacrifice = *temp;
                    safeToCopy = false;
                }
            }
            if(safeToCopy){
                *temp = *tempForSacrifice;
            }
            else{
                *tempForSacrifice = *temp;
            }

            if(allowedAutomats["int"]){
                if(init_int(*tempForSacrifice) > -1){
                    acceptableInput = true;
                    init_int_sem(int_automat, tempForSacrifice);
                    cout<<"Enterer INT"<<endl;

                    if(init_object(*tempForSacrifice) > -1){
                        string concatObj;
                        for(int i = 0; i < init_object(*tempForSacrifice); i++){
                            concatObj += tempForSacrifice->at(i);
                        }
                        insertObjectType(createdObjectsTypes, concatObj, "int");
                        init_object_sem(object_automat, tempForSacrifice);

                        cout<<"Entered before symbol"<<endl;
                        cout<<"Entered after symbol"<<endl;

                        if(init_intNb(*tempForSacrifice) > -1){
                            string concatValue;
                            for(int i = 0; i < init_intNb(*tempForSacrifice); i++){
                                concatValue += tempForSacrifice->at(i);
                            }
                            insertObjectValue(createdObjectsValues, concatObj, concatValue);

                            init_intNb_sem(int_automat, tempForSacrifice);
                            *temp = *tempForSacrifice;
                            safeToCopy = true;

                            string typeObj = getObjectType(createdObjectsTypes, concatObj);
                            string valueObj = getObjectValue(createdObjectsValues, concatObj);

                            cout<<endl;
                            cout<<"Object type is: " <<  typeObj  <<endl;
                            cout<<"Object value is: " <<  valueObj  <<endl;
                        }else{
                            *tempForSacrifice = *temp;
                            safeToCopy = false;
                        }


                    }else{
                        *tempForSacrifice = *temp;
                        safeToCopy = false;
                    }


                }else{
                    *tempForSacrifice = *temp;
                    safeToCopy = false;
                }
            }
            if(safeToCopy){
                *temp = *tempForSacrifice;
            }
            else{
                *tempForSacrifice = *temp;
            }


            if(temp->empty()){
                repeat = false;
                return true;
            }

            cout<<"Sacrifice: "<<endl;
            for (char c : *temp)
            {
                cout << c;
            }
            cout<<endl;


            if(safeToCopy){
                *temp = *tempForSacrifice;
            }
            else{
                *tempForSacrifice = *temp;
            }

            if(!acceptableInput){
                return false;
            }


        } while (repeat);

    }
        //Program Exit because no selected Automats
    else if (allValuesZero) {
        return false;
    }


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

//function that sends data to json file
Automat* bigDaddy_automat (Automat* au){



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


    au->push_back(int_autom); // 1
    au->push_back(double_autom);// 2
    au->push_back(float_autom);// 3
    au->push_back(char_autom);// 4
    au->push_back(string_autom);// 5
    au->push_back(for_autom);// 6
    au->push_back(while_autom);// 7
    au->push_back(if_autom);// 8
    au->push_back(doWhile_autom);// 9
    au->push_back(array_autom);// 10
    au->push_back(public_autom);// 11
    au->push_back(static_autom);// 12
    au->push_back(void_autom);// 13
    au->push_back(main_autom);// 14
    au->push_back(private_autom);// 15
    au->push_back(object_autom);// 16
    au->push_back(else_autom);// 17
}


bool init_check_symbol(vector<char>* input){
    int state = 0;
    char c;

    c = (*input)[0];

    switch (c) {

        case '=': {
            input->erase (input->begin ());
            return true;

        }
            break;
        case '/': {
            input->erase (input->begin ());
            return true;
        }
            break;
        case '%': {
            input->erase (input->begin ());
            return true;

        }
            break;

        case '+': {
            input->erase (input->begin ());
            return true;

        }
            break;

        case '-': {
            input->erase (input->begin ());
            return true;

        }
            break;

        case '*': {
            input->erase (input->begin ());
            return true;
        }
            break;

        default:{
            return false;
        }

    }


    return false;
}
