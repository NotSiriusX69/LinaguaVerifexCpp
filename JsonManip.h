/*
//general include
#include <iostream>
#include <fstream>

//async include
#include <future>
#include <thread>
#include <chrono>

//library include
#include "nlohmann/json.hpp"

struct call {
	int trigger = 0;
	int response = 0;
};

using json = nlohmann::json;
using namespace std;

//read from file when program is executed
void readFileOnInit (struct call* c, string file) {
	while (true) {
		//repeat every 1 second
		std::this_thread::sleep_for (std::chrono::seconds (5));

		std::ifstream f (file);
		json data = json::parse (f);

		c->trigger = data["trigger"];
		cout << "Trigger: " << c->trigger << std::endl;
		cout << "Response: " << c->response << std::endl;
		c->response = data["response"];
	}
}

//print call struct in console
void printCallStruct (struct call c) {
	cout << "Trigger: " << c.trigger << std::endl;
	cout << "Response: " << c.response << std::endl;
}

//read from file when called 
bool readFromFile (string file) {
	std::ifstream f (file);
	json data = json::parse (f);

	if (data["trigger"] == 1) {
		//writeToFile();
		return true;
	}
	else {
		//writeToFile();
		return false;
	}
}

void resetValues (string file, json data) {
	std::ofstream o (file);

	//reset values
	data["response"] = 0;
	data["trigger"] = 0;

	o << setw (4) << data;
	o.close ();
}

void sendResponse (string file, json data) {
	std::ofstream o (file);
	if (data["trigger"] == 1) {
		data["response"] = 1;
	}
	else {
		data["response"] = 0;
	}
	o << setw (4) << data;
	o.close ();

	//reset values after sending response
	resetValues (file, data);
}
*/
