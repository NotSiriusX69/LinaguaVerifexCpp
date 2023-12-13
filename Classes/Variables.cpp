//
// Created by james on 12/13/2023.
//

#include "../Declarations/Variables.h"
#include "../Declarations/utilities.h"
#include <iostream>

using namespace std;

int init_int (vector<char> input) {

    int state = 0;
    char c;

    for (int i = 0; i < input.size (); i++) {
        c = (input)[i];


        switch (state) {

            case 0: {
                if (c == 'i') {
                    state = 1;

                }
                else {
                    return -1;
                }

            }
                break;
            case 1: {
                if (c == 'n') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;
            case 2: {
                if (c == 't') {
                    state = 3;
                    return i;
                }
                else {
                    return -1;
                }

            }
                break;
        }
    }


}
bool init_int_sem (Automat* au, vector<char>* input) {

    int state = 0;
    char c;
    //starts with default first element

    for(int i = 0; i < *au->states; i++){
        c = (*input)[i];
        //gets next element to save in automat

        input->erase (input->begin ());

        if(!checkIfRegex(c, au->delta->at(i)->current)){
            return false;
        }

        i--;
    }
    return true;

}
int init_intNb (vector<char> input) {

    int state = 0;
    char d;

    for (int i = 0; i < input.size (); i++) {
        d = (input)[i];

        switch (state) {

            case 0: {
                if (isdigit (d)) {
                    state = 0;
                }
                else if (d == ';') {
                    return i;
                }
                else {
                    return -1;
                }

            }
                break;

        }
    }
    return -1;

}
bool init_intNb_sem (Automat* au, vector<char>* input) {

    int state = 0;
    char d;

    for (int i = 0; i < input->size (); i++) {
        d = (*input)[i];


        switch (state) {

            case 0: {
                if (isdigit (d)) {
                    input->erase (input->begin ());
                    --i;
                    state = 0;
                }
                else if (d == ';') {
                    input->erase (input->begin ());
                    --i;
                    return true;
                }
                else {
                    return false;
                }

            }
                break;

        }

    }
    return false;

}


int init_char (vector<char> input) {
    int state = 0;
    char c;

    for (int i = 0; i < input.size (); i++) {
        c = (input)[i];

        switch (state) {

            case 0: {
                if (c == 'c') {
                    state = 1;

                }
                else {
                    return -1;
                }

            }
                break;
            case 1: {
                if (c == 'h') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;
            case 2: {
                if (c == 'a') {
                    state = 3;
                }
                else {
                    return -1;
                }

            }
                break;

            case 3: {
                if (c == 'r') {
                    state = 3;
                    return i;
                }
                else {
                    return -1;
                }

            }
                break;
        }
    }

}
bool init_char_sem (Automat* au, vector<char>* input) {
    int state = 0;
    char c;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];
        input->erase (input->begin ());

        switch (state) {

            case 0: {
                if (c == 'c') {
                    state = 1;

                }
                else {
                    return false;
                }

            }
                break;
            case 1: {
                if (c == 'h') {
                    state = 2;
                }
                else {
                    return false;
                }

            }
                break;
            case 2: {
                if (c == 'a') {
                    state = 3;
                }
                else {
                    return false;
                }

            }
                break;

            case 3: {
                if (c == 'r') {
                    state = 3;
                    return true;
                }
                else {
                    return false;
                }

            }
                break;
        }
        --i;
    }

}
int init_charNb (vector<char> input, bool isDeclaration) {

    int state = 0;
    char c;

    for (int i = 0; i < input.size (); i++) {
        c = (input)[i];

        switch (state) {

            case 0: {
                if (c == '\'') {
                    state = 1;
                }
                else {
                    return -1;
                }
            }
                break;
            case 1: {
                if (isalpha (c) || isdigit (c) || c == ' ') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;

            case 2: {
                if (c == '\'') {
                    state = 2;
                    if (!isDeclaration) {
                        return i;
                    }
                }
                else if (c == ';') {
                    return i;
                }
                else {
                    return -1;
                }

            }
                break;
        }
    }

}
bool init_charNb_sem (Automat* au, vector<char>* input, bool isDeclaration) {

    int state = 0;
    char c;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];
        input->erase (input->begin ());

        switch (state) {

            case 0: {
                if (c == '\'') {
                    state = 1;
                }
                else {
                    return false;
                }
            }
                break;
            case 1: {
                if (isalpha (c) || isdigit (c) || c == ' ') {
                    state = 2;
                }
                else {
                    return false;
                }

            }
                break;

            case 2: {
                if (c == '\'') {
                    state = 2;
                    if (!isDeclaration) {
                        return true;
                    }
                }
                else if (c == ';') {
                    return true;
                }
                else {
                    return false;
                }

            }
                break;
        }
        --i;
    }

}


int init_float (vector<char> input) {

    int state = 0;
    char c;

    for (int i = 0; i < input.size (); i++) {
        c = (input)[i];
        cout<<c;

        switch (state) {

            case 0: {
                if (c == 'f') {
                    state = 1;

                }
                else {
                    return -1;
                }

            }
                break;
            case 1: {
                if (c == 'l') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;
            case 2: {
                if (c == 'o') {
                    state = 3;
                }
                else {
                    return -1;
                }

            }
                break;

            case 3: {
                if (c == 'a') {
                    state = 4;
                }
                else {
                    return -1;
                }

            }
                break;

            case 4: {
                if (c == 't') {
                    state = 4;
                    return i;
                }
                else {
                    return -1;
                }

            }
                break;

        }
    }

}
bool init_float_sem (Automat* au, vector<char>* input) {

    int state = 0;
    char c;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];
        input->erase (input->begin ());

        switch (state) {

            case 0: {
                if (c == 'f') {
                    state = 1;

                }
                else {
                    return false;
                }

            }
                break;
            case 1: {
                if (c == 'l') {
                    state = 2;
                }
                else {
                    return false;
                }

            }
                break;
            case 2: {
                if (c == 'o') {
                    state = 3;
                }
                else {
                    return false;
                }

            }
                break;

            case 3: {
                if (c == 'a') {
                    state = 4;
                }
                else {
                    return false;
                }

            }
                break;

            case 4: {
                if (c == 't') {
                    state = 4;
                    return true;
                }
                else {
                    return false;
                }

            }
                break;

        }
        --i;
    }

}
int init_floatNb (vector<char> input) {

    int state = 0;
    char c;
    int digits_counter = 0;

    for (int i = 0; i < input.size (); i++) {
        c = (input)[i];


        switch (state) {

            case 0: {
                if (isdigit (c)) {
                    state = 1;
                }
                else {
                    return -1;
                }

            }
                break;
            case 1: {
                if (isdigit (c)) {
                    state = 1;
                }
                else if (c == '.') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;
            case 2: {
                if (isdigit (c)) {
                    state = 2;
                }
                else if (c == ';') {
                    return i;
                }
                else if (digits_counter + 1 > 7) {
                    return -1;
                }
                else {
                    return -1;
                }
            }
                break;
        }

        digits_counter++;
    }

    return -1;
}
bool init_floatNb_sem (Automat* au, vector<char>* input) {

    int state = 0;
    char c;
    int digits_counter = 0;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];
        input->erase (input->begin ());

        switch (state) {

            case 0: {
                if (isdigit (c)) {
                    state = 1;
                }
                else {
                    return false;
                }

            }
                break;
            case 1: {
                if (isdigit (c)) {
                    state = 1;
                }
                else if (c == '.') {
                    state = 2;
                }
                else {
                    return false;
                }
            }
                break;
            case 2: {
                if (isdigit (c)) {
                    state = 2;
                }
                else if (c == ';') {
                    return true;
                }
                else if (digits_counter + 1 > 7) {
                    return false;
                }
                else {
                    return false;
                }
            }
                break;
        }
        --i;

        digits_counter++;
    }

    return false;


}


int init_double (vector<char> input) {
    int state = 0;
    char c;

    for (int i = 0; i < input.size (); i++) {
        c = (input)[i];

        switch (state) {

            case 0: {
                if (c == 'd') {
                    state = 1;

                }
                else {
                    return -1;
                }

            }
                break;
            case 1: {
                if (c == 'o') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;
            case 2: {
                if (c == 'u') {
                    state = 3;
                }
                else {
                    return -1;
                }

            }
                break;

            case 3: {
                if (c == 'b') {
                    state = 4;
                }
                else {
                    return -1;
                }

            }
                break;

            case 4: {
                if (c == 'l') {
                    state = 5;
                }
                else {
                    return -1;
                }

            }
                break;

            case 5: {
                if (c == 'e') {
                    state = 5;
                    return i;
                }
                else {
                    return -1;
                }

            }
                break;

        }
    }


}
bool init_double_sem (Automat* au, vector<char>* input) {

    int state = 0;
    char c;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];
        input->erase (input->begin ());

        switch (state) {

            case 0: {
                if (c == 'd') {
                    state = 1;

                }
                else {
                    return false;
                }

            }
                break;
            case 1: {
                if (c == 'o') {
                    state = 2;
                }
                else {
                    return false;
                }

            }
                break;
            case 2: {
                if (c == 'u') {
                    state = 3;
                }
                else {
                    return false;
                }

            }
                break;

            case 3: {
                if (c == 'b') {
                    state = 4;
                }
                else {
                    return false;
                }

            }
                break;

            case 4: {
                if (c == 'l') {
                    state = 5;
                }
                else {
                    return false;
                }

            }
                break;

            case 5: {
                if (c == 'e') {
                    state = 5;
                    return true;
                }
                else {
                    return false;
                }

            }
                break;

        }
        --i;
    }


}
int init_doubleNb (vector<char> input) {

    int state = 0;
    char c;
    int digits_counter = 0;

    for (int i = 0; i < input.size (); i++) {
        c = (input)[i];

        switch (state) {

            case 0: {
                if (isdigit (c)) {
                    state = 1;
                }
                else {
                    return -1;
                }

            }
                break;
            case 1: {
                if (isdigit (c)) {
                    state = 1;
                }
                else if (c == '.') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;
            case 2: {
                if (isdigit (c)) {
                    state = 2;
                }
                else if (c == ';') {
                    return i;
                }
                else if (digits_counter + 1 > 15) {
                    return -1;
                }
                else {
                    return -1;
                }
            }
                break;
        }

        digits_counter++;
    }

    return -1;


}
bool init_doubleNb_sem (Automat* au, vector<char>* input) {

    int state = 0;
    char c;
    int digits_counter = 0;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];
        input->erase (input->begin ());

        switch (state) {

            case 0: {
                if (isdigit (c)) {
                    state = 1;
                }
                else {
                    return false;
                }

            }
                break;
            case 1: {
                if (isdigit (c)) {
                    state = 1;
                }
                else if (c == '.') {
                    state = 2;
                }
                else {
                    return false;
                }

            }
                break;
            case 2: {
                if (isdigit (c)) {
                    state = 2;
                }
                else if (c == ';') {
                    return true;
                }
                else if (digits_counter + 1 > 15) {
                    return false;
                }
                else {
                    return false;
                }
            }
                break;
        }

        digits_counter++;
        --i;
    }

    return true;


}


bool init_if_sem (Automat* au, vector<char>* input) {
    int state = 0;
    char c;
    int parenthesis_counter = 0;
    int equal_counter = 0;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];
        input->erase (input->begin ());


        switch (state) {

            case 0: {
                if (c == 'i') {
                    state = 1;

                }
                else {
                    return false;
                }

            }
                break;
            case 1: {
                if (c == 'f') {
                    state = 2;
                }
                else {
                    return false;
                }

            }
                break;
            case 2: {
                if (c == '(') {
                    state = 3;
                    parenthesis_counter++;
                }
                else {
                    return false;
                }

            }
                break;

            case 3: {
                if (int temp = init_object (*input) > 0) {
                    for (int i = 0; i < temp; i++) {
                        input->erase (input->begin ());
                    }
                    state = 4;
                }
                else if (c == '=' && equal_counter == 1) {
                    state = 4;
                    equal_counter++;
                }
                else {
                    return false;
                }

            }
                break;

            case 4: {
                if (c == '=' && equal_counter < 2) {
                    state = 3;
                    equal_counter++;
                }
                else if (checkIfRegex (c, "-+/%*")) {
                    state = 3;
                }
                else if (equal_counter == 2 && init_object (*input)) {
                    state = 5;

                }
                else {
                    return false;
                }

            }
                break;

            case 5: {
                if (c == ')') {
                    state = 5;
                    parenthesis_counter--;
                    return true;
                }
                else {
                    return false;
                }

            }
                break;
        }
        --i;

    }
    return false;


}
int init_if (Automat* au, vector<char> input) {
    int state = 0;
    char c;
    int parenthesis_counter = 0;
    int equal_counter = 0;

    for (int i = 0; i < input.size (); i++) {
        c = (input)[i];


        switch (state) {

            case 0: {
                if (c == 'i') {
                    state = 1;

                }
                else {
                    return false;
                }

            }
                break;
            case 1: {
                if (c == 'f') {
                    state = 2;
                }
                else {
                    return false;
                }

            }
                break;
            case 2: {
                if (c == '(') {
                    state = 3;
                    parenthesis_counter++;
                }
                else {
                    return false;
                }

            }
                break;

            case 3: {
                if (int temp = init_object (input) > 0) {
                    for (int i = 0; i < temp; i++) {
                        input.erase (input.begin ());
                    }
                    state = 4;
                }
                else if (c == '=' && equal_counter == 1) {
                    state = 4;
                    equal_counter++;
                }
                else {
                    return false;
                }

            }
                break;

            case 4: {
                if (c == '=' && equal_counter < 2) {
                    state = 3;
                    equal_counter++;
                }
                else if (checkIfRegex (c, "-+/%*")) {
                    state = 3;
                }
                else if (equal_counter == 2 && init_object (input)) {
                    state = 5;

                }
                else {
                    return false;
                }

            }
                break;

            case 5: {
                if (c == ')') {
                    state = 5;
                    parenthesis_counter--;
                    return true;
                }
                else {
                    return false;
                }

            }
                break;
        }

    }
    return false;
}


int init_array (Automat* au, vector<char> input) {

    int state = 0;
    char c;
    int bracket_counter = 0;
    int curvedBracket_counter = 0;

    for (int i = 0; i < input.size (); i++) {
        c = (input)[i];
        cout << endl;
        cout << "Entered array" << endl;
        cout << c;
        switch (state) {

            case 0: {
                if (init_int (input)) {
                    state = 1;
                }
                else if (init_double (input)) {
                    state = 1;
                }
                else if (init_float (input)) {
                    state = 1;
                }
                else if (init_char (input)) {
                    state = 1;
                }
                else if (init_string (input)) {
                    state = 1;
                }
                else {
                    return -1;
                }
            }
                break;

            case 1: {
                if (init_object(input) > -1) {

                    cout<<endl;

                    for (char c : input) {
                        cout << c << endl;
                    }

                    state = 1;
                }
                else if (c == '[') {
                    state = 2;
                    bracket_counter++;
                }
                else {
                    return -1;
                }
            }
                break;

                //if its being declared
            case 2: {
                if (init_object (input)) {
                    state = 3;
                }
                else if (isdigit (c)) {
                    state = 2;
                }
                else if (c == ']') {
                    state = 4;
                    bracket_counter--;
                }
                else {
                    return -1;
                }

            }
                break;

                //if its not being declared
            case 3: {
                if (c == ']') {
                    state = 4;
                    bracket_counter--;
                }
                else {
                    return -1;
                }
            }
                break;

            case 4: {
                if (c == ';') {
                    return i;
                }
                else if (c == '=') {
                    state = 5;
                }
                else {
                    return -1;
                }

            }
                break;

            case 5: {
                if (c == '{') {
                    state = 6;
                    curvedBracket_counter++;
                }
                else if (curvedBracket_counter == 0) {
                    //if bracket open then check for object and get its value from map
                    init_object(input);
                }
                else if (c == '}') {
                    state = 6;
                }
                else {
                    return -1;
                }

            }
                break;

            case 6: {
                if (c == ';') {
                    return i;
                }
                else {
                    return -1;
                }
            }
        }
    }

    return -1;

}
bool init_array_sem (Automat* au, vector<char>* input) {

    int state = 0;
    char c;
    int bracket_counter = 0;
    int curvedBracket_counter = 0;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];
        cout << endl;
        cout << "Entered array" << endl;
        cout << c;
        switch (state) {

            case 0: {
                if (init_int (*input)) {
                    state = 1;
                }
                else if (init_double (*input)) {
                    state = 1;
                }
                else if (init_float (*input)) {
                    state = 1;
                }
                else if (init_char (*input)) {
                    state = 1;
                }
                else if (init_string (*input)) {
                    state = 1;
                }
                else {
                    return false;
                }
            }
                break;

            case 1: {
                if (init_object(*input) > -1) {

                    state = 1;
                }
                else if (c == '[') {
                    state = 2;
                    bracket_counter++;
                }
                else {
                    return false;
                }
            }
                break;

                //if its being declared
            case 2: {
                if (init_object (*input)) {
                    state = 3;
                }
                else if (isdigit (c)) {
                    state = 2;
                }
                else if (c == ']') {
                    state = 4;
                    bracket_counter--;
                }
                else {
                    return false;
                }

            }
                break;

                //if its not being declared
            case 3: {
                if (c == ']') {
                    state = 4;
                    bracket_counter--;
                }
                else {
                    return false;
                }
            }
                break;

            case 4: {
                if (c == ';') {
                    return i;
                }
                else if (c == '=') {
                    state = 5;
                }
                else {
                    return false;
                }

            }
                break;

            case 5: {
                if (c == '{') {
                    state = 6;
                    curvedBracket_counter++;
                }
                else if (curvedBracket_counter == 0) {
                    //if bracket open then check for object and get its value from map
                    init_object(*input);
                }
                else if (c == '}') {
                    state = 6;
                }
                else {
                    return false;
                }

            }
                break;

            case 6: {
                if (c == ';') {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }

    return -1;

}


int init_string (vector<char> input) {
    int state = 0;
    char c;

    for (int i = 0; i < input.size (); i++) {
        c = (input)[i];

        switch (state) {

            case 0: {
                if (c == 's') {
                    state = 1;

                }
                else {
                    return -1;
                }

            }
                break;
            case 1: {
                if (c == 't') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;
            case 2: {
                if (c == 'r') {
                    state = 3;
                }
                else {
                    return -1;
                }

            }
                break;

            case 3: {
                if (c == 'i') {
                    state = 4;
                }
                else {
                    return -1;
                }

            }
                break;

            case 4: {
                if (c == 'n') {
                    state = 5;
                }
                else {
                    return -1;
                }

            }
                break;

            case 5: {
                if (c == 'g') {
                    state = 5;
                    return i;
                }
                else {
                    return -1;
                }

            }
                break;

        }
    }

}
bool init_string_sem (Automat* au, vector<char>* input) {
    int state = 0;
    char c;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];
        input->erase (input->begin ());

        switch (state) {

            case 0: {
                if (c == 's') {
                    state = 1;

                }
                else {
                    return false;
                }

            }
                break;
            case 1: {
                if (c == 't') {
                    state = 2;
                }
                else {
                    return false;
                }

            }
                break;
            case 2: {
                if (c == 'r') {
                    state = 3;
                }
                else {
                    return false;
                }

            }
                break;

            case 3: {
                if (c == 'i') {
                    state = 4;
                }
                else {
                    return false;
                }

            }
                break;

            case 4: {
                if (c == 'n') {
                    state = 5;
                }
                else {
                    return false;
                }

            }
                break;

            case 5: {
                if (c == 'g') {
                    state = 5;
                    return true;
                }
                else {
                    return false;
                }

            }
                break;

        }
        --i;
    }

}


int init_object (vector<char> input) {

    int state = 0;
    char c;

    for (int i = 0; i < input.size (); i++) {
        c = (input)[i];

        switch (state) {

            case 0: {
                if (isalpha (c)) {
                    state = 1;
                }
                else {
                    return -1;
                }
            }
                break;
            case 1: {
                if (isalpha (c) || isdigit (c)) {
                    state = 1;
                }
                else if (checkIfRegex(c, "[];=")) {
                    return i - 1;
                }
                else if (c == ' ') {
                    return -1;
                }
                else{
                    return -1;
                }
            }
                break;
        }
    }
    return -1;

}
bool init_object_sem (Automat* au, vector<char>* input) {

    int state = 0;
    char c;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];

        switch (state) {

            case 0: {
                if (isalpha (c)) {
                    input->erase (input->begin ());
                    --i;
                    state = 1;
                }
                else {
                    return false;
                }
            }
                break;
            case 1: {
                if (isalpha (c) || isdigit (c)) {
                    input->erase (input->begin ());
                    --i;
                    state = 1;
                }
                else if (checkIfRegex(c, "[];=")) {
                    input->erase (input->begin ());
                    --i;
                    return true;
                }
                else if (c == ' ') {
                    return false;
                }

            }
                break;
        }

    }
    return false;

}


int init_main (vector<char> input) {

    int state = 0;
    char c;

    for (int i = 0; i < input.size (); i++) {
        c = (input)[i];

        switch (state) {

            case 0: {
                if (c == 'm') {
                    state = 1;
                }
                else {
                    return -1;
                }

            }
                break;

            case 1: {
                if (c == 'a') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;

            case 2: {
                if (c == 'i') {
                    state = 3;
                }
                else {
                    return -1;
                }

            }
                break;


            case 3: {
                if (c == 'n') {
                    state = 4;
                }
                else {
                    return -1;
                }

            }
                break;


            case 4: {
                if (c == '(') {
                    state = 5;
                }
                else {
                    return -1;
                }

            }
                break;



            case 5: {
                if (c == ')') {
                    state = 5;
                    return i;
                }
                else {
                    return -1;
                }

            }
                break;

        }
    }

    return false;

}
bool init_main_sem (Automat* au, vector<char>* input) {

    int state = 0;
    char c;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];
        input->erase (input->begin ());

        switch (state) {

            case 0: {
                if (c == 'm') {
                    state = 1;
                }
                else {
                    return false;
                }

            }
                break;

            case 1: {
                if (c == 'a') {
                    state = 2;
                }
                else {
                    return false;
                }

            }
                break;

            case 2: {
                if (c == 'i') {
                    state = 3;
                }
                else {
                    return false;
                }

            }
                break;


            case 3: {
                if (c == 'n') {
                    state = 4;
                }
                else {
                    return false;
                }

            }
                break;


            case 4: {
                if (c == '(') {
                    state = 5;
                }
                else {
                    return false;
                }

            }
                break;



            case 5: {
                if (c == ')') {
                    state = 5;
                    return true;
                }
                else {
                    return false;
                }

            }
                break;

        }
        i--;
    }

    return false;

}
