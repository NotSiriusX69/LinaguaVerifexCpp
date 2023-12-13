//
// Created by james on 12/13/2023.
//

#include "../Declarations/utilities.h"


//function that checks if the input is equal to one of the specified regex elements
bool checkIfRegex (char input, string regex) {

    for (char c : regex) {
        if (c == input) {
            return true;
        }
    }

    return false;
}

//function to remove spaces in RE
string remove_reSpaces (string input) {
    string result;

    for (char c : input) {
        if (c != ' ') {
            result += c;
        }
    }

    return result;
}

std::vector<char> convert_stringToVector (string input) {
    std::vector<char> arr;

    for (char c : input) {
        if (c != ' ') {
            arr.push_back (c);
        }

    }

    return arr;
}

//function that converts a transition vector to array
template <typename T>
T* convert_vectorToArr (const std::vector<T>& transVect) {
    T* newArr = new T[transVect.size ()];

    for (size_t i = 0; i < transVect.size (); i++) {
        newArr[i] = transVect[i];
    }

    return newArr;
}

//function that converts a transition array to vector
template <typename T, size_t N>
std::vector<T> convert_arrToVector (T (&transArr)[N]) {
    std::vector<T> newArr;

    for (size_t i = 0; i < N; i++) {
        newArr.push_back (transArr[i]);
    }

    return newArr;
}