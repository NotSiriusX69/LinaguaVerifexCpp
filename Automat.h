#include <string>

// Declare Automaton Variables
//Initialize for now in header file ~ to be taken from json file on cpp startup
const int nbSymbols = 10;
const int nbStates = 10;
const int nbTransitions = 20;
const int nbStatesTerminal = 10;

// Path of current file
const std::string path = "data/automat.json";

// Transition structure 
struct Transition {
    char origin;
    char label;
    char target;
};

// Automat structure
struct Automat {
    char alphabet[nbSymbols];
    char states[nbStates];
    char q0; //Initial state
    Transition delta[nbTransitions];
    char statesTerminal[nbStatesTerminal];
};