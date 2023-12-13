//
// Created by james on 12/13/2023.
//
#ifndef LINGUA_VERIFEX_PROTECTION_H
#define LINGUA_VERIFEX_PROTECTION_H

#include "Automat.h"

using namespace std;


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



#endif //LINGUA_VERIFEX_PROTECTION_H
