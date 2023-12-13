//
// Created by james on 12/13/2023.
//
#ifndef LINGUA_VERIFEX_GRAMMARCHECK_H
#define LINGUA_VERIFEX_GRAMMARCHECK_H

#include "Automat.h"

using namespace std;

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

//object
int init_object (vector<char>);
bool init_object_sem (Automat*, vector<char>*);//


// ##### //

// ##### Arrays
int init_array (Automat*, vector<char>);
bool init_array_sem (Automat*, vector<char>*);

// ##### //

#endif //LINGUA_VERIFEX_GRAMMARCHECK_H
