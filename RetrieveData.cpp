/*
//
// Created by james on 12/13/2023.
//

#include "RetrieveData.h"

#include <iostream>
#include <thread>
#include <fstream>
#include "nlohmann/json.hpp"
#include "classes/automat.cpp"




using namespace std;
using json = nlohmann::json;

void print(char c){
    cout << "char is " << c <<endl;
}

struct selectedAutomats {
    bool isIntSelected = false;
    bool isDoubleSelected = false;
    bool isFloatSelected = false;
    bool isCharSelected = false;
    bool isStringSelected = false;

    bool isVariableSelected = false;

    bool isIfSelected = false;
    bool isDoWhileSelected = false;
    bool isWhileSelected = false;
    bool isForSelected = false;

    bool isMainSelected = false;
    bool isArraySelected = false;
};

void fillMap(map<string, string> mapo, selectedAutomats obj){


}

string file = "C:/Users/user/Desktop/all/Semester_5/Theory_of_computation/project/LinaguaVerifexC++/data/selected_automats.json";

void readFromFile(selectedAutomats *t) {

    while(true){

        std::ifstream f(file);
        if (!f.is_open()) {
            std::cerr << "Error opening file: " << file << std::endl;
            return;
        }

        try {

            json data = json::parse(f);
            t->isIntSelected = data["int"];
            t->isDoubleSelected = data["double"];
            t->isFloatSelected = data["float"];
            t->isCharSelected = data["char"];
            t->isStringSelected = data["string"];
            t->isVariableSelected = data["variable"];
            t->isIfSelected = data["if"];
            t->isDoWhileSelected = data["do_while"];
            t->isWhileSelected = data["while"];
            t->isForSelected = data["for"];
            t->isMainSelected = data["main"];
            t->isArraySelected = data["array"];

        } catch (const json::exception& e) {
            std::cerr << "Error parsing JSON: " << e.what() << std::endl;
        }

        this_thread::sleep_for(std::chrono::seconds(1));
    }

}
void printResult(selectedAutomats *t){

    while(true){

        ifstream f(file);
        json data = json::parse(f);

        cout << t->isIntSelected  << endl;
        cout << t->isDoubleSelected << endl;
        cout << t->isFloatSelected  << endl;
        cout << t->isCharSelected  << endl;
        cout << t->isStringSelected  << endl;
        cout << t->isVariableSelected << endl;
        cout << t->isIfSelected  << endl;
        cout << t->isDoWhileSelected << endl;
        cout << t->isWhileSelected << endl;
        cout << t->isForSelected  << endl;
        cout << t->isMainSelected << endl;
        cout << t->isArraySelected  << endl;

        this_thread::sleep_for(std::chrono::seconds(3));
    }
}


int main() {

    */
/* selectedAutomats test;

     thread t1(readFromFile, &test);
     thread t2(printResult, &test);

     t1.join();
     t2.join();*//*

    testMyFunc("str", 12);

    return 0;
}

*/
