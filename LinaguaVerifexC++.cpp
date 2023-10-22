//general include
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

//async include
#include <future>

//headers include
#include "JsonManip.h"

using namespace std;


int main ()
{
	call c;
	string file_path = "data/trigger.json";

	ifstream f (file_path);
	json data = json::parse (f);

	future<void> asyncTrigger = async (&readFileOnInit, &c, file_path);

	//testing response
	string response;
	int keep = 0;
	do
	{
		cout << " do you want to send response: ";
		cin >> response;
		cout << endl;
		if (response == "yes") {
			sendResponse (file_path, data);
		}
		else {
			cout << "no response" << endl;
		}

		cout << "keep going: (0 to keep going)";
		cin >> keep;
		if (keep != 1 || keep != 0) {
			keep = 1;
		}

	} while (keep == 0);
}
