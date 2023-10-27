#include <string>
#include <vector>

//function that checks if the input is equal to one of the specified regex elements
bool checkIfSymbol (char, std::string);

//function that converts a transition vector to array
template <typename T>
T* convert_vectorToArr (const std::vector<T>& transVect);

//function that converts a transition array to vector
template <typename T, size_t N>
std::vector<T> convert_arrToVector (T (&transArr)[N]);