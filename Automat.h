#pragma once

#include <string>
#include <vector>

// Declare Automaton Variables
//Initialize for now in header file ~ to be taken from json file on cpp startup
const int nbSymbols = 100;
const int nbStates = 100;
const int nbTransitions = 20;
const int nbStatesTerminal = 10;

// Path of current file
const std::string path = "data/automat.json";

// Transition structure 
struct Transition {
    //origin state, target state, and current regex block
    std::string origin;
    std::string current;
    std::string target;


    //user can choose to write it or not, and if he writes it, then he can infinitely continue
    bool starRepetition = false;

    //user has to write it, and when he writes it, then he can infinitely continue
    bool plusRepetition = false;

    //user can write it once or not at all
    bool emptyRepetition = false;

};

//This struct is the main one that holds everything (check project notes UI logic)

// Automat structure
struct Automat {
    std::string* identifier;
    int* states;
    std::string* q0; //Initial state
    std::vector<Transition*>* delta;
    std::vector<std::string*>* statesTerminal;
};