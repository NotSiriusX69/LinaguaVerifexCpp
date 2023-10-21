#include <iostream>
#include <string> 
#include <cstring> 

using namespace std;

string regularExpression;
string inputText;

//convert to charArray for "just in case purposes"
void convertToChar(string text) {

	const int length = text.length();

	//declare character arrary (+1 for null terminator)	
	char* text_array = new char[length + 1];

	//copy into the char array
	strcpy(text_array, text.c_str());

}






