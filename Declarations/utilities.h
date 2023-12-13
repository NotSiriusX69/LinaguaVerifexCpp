#ifndef LINGUA_VERIFEX_UTILITIES_H
#define LINGUA_VERIFEX_UTILITIES_H

#include <string>
#include <vector>
using namespace std;


//function that checks if the input is equal to one of the specified regex elements
bool checkIfRegex (char, string);

//function to remove spaces in RE
string remove_reSpaces (string);

std::vector<char> convert_stringToVector (string);

//function that converts a transition vector to array
template <typename T>
T* convert_vectorToArr (const std::vector<T>&);

//function that converts a transition array to vector
template <typename T, size_t N>
std::vector<T> convert_arrToVector (T (&transArr)[N]);

#endif //LINGUA_VERIFEX_UTILITIES_H