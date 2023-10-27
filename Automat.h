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
	//origin state, target state, and current regex block (ex: [0-9]^+  snf its regexToken would be: NUM)
	char origin;
	std::string regexBlock;
	char target;


	std::string regexToken;

	//user can choose to write it or not, and if he writes it, then he can infinitely continue
	bool starRepetition = false;

	//user has to write it, and when he writes it, then he can infinitely continue
	bool plusRepetition = false;

	//user can write it once or not at all
	bool emptyRepetition = false;

};

// Automat structure
struct Automat {
	char alphabet[nbSymbols];
	int states[nbStates];
	char q0; //Initial state
	std::vector<Transition> delta;
	char statesTerminal[nbStatesTerminal];
};