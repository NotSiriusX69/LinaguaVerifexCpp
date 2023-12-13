//
// Created by james on 12/13/2023.
//
#ifndef LINGUA_VERIFEX_INSERSION_H
#define LINGUA_VERIFEX_INSERSION_H

#include "Automat.h"
#include "map"

using namespace std;

//Insertion
void insertIdentifier(string *, string);
void insertQ0(string*, string);
void insertTransition(vector<Transition*>*, Transition*);
void insertTerminalState(vector<string*>*, string*);
void insertState(int*, int);

bool insertObjectType(map<string, string>*, string, string);
bool insertObjectValue(map<string, string>*, string, string);
string getObjectType(map<string, string>*, string);
string getObjectValue(map<string, string>*, string);


#endif //LINGUA_VERIFEX_INSERSION_H
