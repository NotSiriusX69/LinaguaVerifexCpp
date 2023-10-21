
//general include
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

//async include
#include <future>

//headers include
#include "JsonManip.h"


int main()
{
    call c;
    string file_path = "data/trigger.json";

    std::ifstream f(file_path);
    json data = json::parse(f);

    std::future<void> asyncTrigger = std::async(&readFileOnInit, &c , file_path);

    //testing response
    string response;
    bool keep = true;
    do
    {
        cout << " do you want to send response: ";
        cin >> response;
        cout << endl;
        if (response == "yes") {
            sendResponse(file_path, data);
        }
        else {
            cout << "no response" << endl;
        }

        cout << "keep going: ";
            cin >> keep;
        if (keep == true) {
            keep = true;
        }
        else {
            keep = false;
        }
    } while (keep);

}