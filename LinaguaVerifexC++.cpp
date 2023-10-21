
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std;


int main()
{
    int numbers[5];

    string file_path = "C:/Users/user/Desktop/all/Semester_5/Theory_of_computation/code/LinguaVerifex/LinguaVerifexC++/data";

    std::ifstream f(file_path);

    json data = json::parse(f);

    if (data.is_object() && data.find("number") != data.end()) {
        // Check if "number" exists and is an array
        if (data["number"].is_array()) {
            std::vector<int> numberArray = data["number"].get<std::vector<int>>();

            // Now, you have the array of integers in numberArray
            for (const int& element : numberArray) {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }
        else {
            std::cerr << "\"number\" in the JSON is not an array of integers." << std::endl;
        }
    }
    else {
        std::cerr << "Invalid JSON format or \"number\" key not found." << std::endl;
    }

    //std::ofstream o(file_path);
    //o << setw(4) << data;

}