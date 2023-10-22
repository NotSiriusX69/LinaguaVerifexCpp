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
    char origin;
    char label;
    char target;
};

// Automat structure
struct Automat {
    char alphabet[nbSymbols];
    char states[nbStates];
    char q0; //Initial state
    std::vector<Transition> delta;
    char statesTerminal[nbStatesTerminal];
};