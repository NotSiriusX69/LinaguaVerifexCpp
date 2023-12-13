//
// Created by james on 12/13/2023.
//

#include "../Declarations/Insersion.h"
#include "iostream"

using namespace std;


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

//returns false means object was updated instead of inserted and vice versa
bool insertObjectType(map<string, string>* map, string object, string type){
    auto testFind = map->find(object);

    //cannot update of same object with same name has different type
    if (testFind != map->end()) {
        return false;
    } else {
        // Element not found, insert a new one
        map->insert({object, type});
        return true;
    }

}

bool insertObjectValue(map<string, string>* map, string object, string value){
    auto testFind = map->find(object);

    if (testFind != map->end()) {
        // Element found, update its value
        testFind->second = value;
        return false;
    } else {
        // Element not found, insert a new one
        map->insert({object, value});
        return true;
    }

}

string getObjectType(map<string, string>* map, string object){
    auto testFind = map->find(object);

    if (testFind != map->end()) {
        return testFind->second;

    } else {
        // Element not found, insert a new one
        return "";
    }

}

string getObjectValue(map<string, string>* map, string object){
    auto testFind = map->find(object);

    if (testFind != map->end()) {
        return testFind->second;
    } else {
        // Element not found, insert a new one
        return "";
    }

}