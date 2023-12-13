//
// Created by james on 12/13/2023.
//

#include "../Declarations/Protection.h"


int init_public(vector<char> input) {
    int state = 0;
    char c;

    for (int i = 0; i < input.size (); i++) {
        c = (input)[i];

        switch (state) {

            case 0: {
                if (c == 'p') {
                    state = 1;

                }
                else {
                    return -1;
                }

            }
                break;
            case 1: {
                if (c == 'u') {
                    state = 2;
                }
                else {
                    return -1;
                }

            }
                break;
            case 2: {
                if (c == 'b') {
                    state = 3;
                }
                else {
                    return -1;
                }

            }
                break;

            case 3: {
                if (c == 'l') {
                    state = 4;
                }
                else {
                    return -1;
                }

            }
                break;

            case 4: {
                if (c == 'i') {
                    state = 5;
                }
                else {
                    return -1;
                }

            }
                break;

            case 5: {
                if (c == 'c') {
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
bool init_public_sem (Automat* au, vector<char>* input){

    int state = 0;
    char c;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];

        switch (state) {

            case 0: {
                if (c == 'p') {
                    state = 1;
                    input->erase (input->begin ());
                    --i;

                }
                else {
                    return false;
                }

            }
                break;
            case 1: {
                if (c == 'u') {
                    state = 2;
                    input->erase (input->begin ());
                    --i;
                }
                else {
                    return false;
                }

            }
                break;
            case 2: {
                if (c == 'b') {
                    state = 3;
                    input->erase (input->begin ());
                    --i;
                }
                else {
                    return false;
                }

            }
                break;

            case 3: {
                if (c == 'l') {
                    state = 4;
                    input->erase (input->begin ());
                    --i;
                }
                else {
                    return false;
                }

            }
                break;

            case 4: {
                if (c == 'i') {
                    state = 5;
                    input->erase (input->begin ());
                    --i;
                }
                else {
                    return false;
                }

            }
                break;

            case 5: {
                if (c == 'c') {
                    state = 5;
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

}

int init_private(vector<char> input) {
    int state = 0;
    char c;

    for (int i = 0; i < input.size (); i++) {
        c = (input)[i];

        switch (state) {

            case 0: {
                if (c == 'p') {
                    state = 1;

                }
                else {
                    return -1;
                }

            }
                break;
            case 1: {
                if (c == 'r') {
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
                if (c == 'v') {
                    state = 4;
                }
                else {
                    return -1;
                }

            }
                break;

            case 4: {
                if (c == 'a') {
                    state = 5;
                }
                else {
                    return -1;
                }

            }
                break;

            case 5: {
                if (c == 't') {
                    state = 6;
                }
                else {
                    return -1;
                }

            }
                break;

            case 6: {
                if (c == 'e') {
                    state = 6;
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
bool init_private_sem (Automat* au, vector<char>* input){

    int state = 0;
    char c;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];

        switch (state) {

            case 0: {
                if (c == 'p') {
                    state = 1;

                }
                else {
                    return false;
                }

            }
                break;
            case 1: {
                if (c == 'r') {
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
                if (c == 'v') {
                    state = 4;
                }
                else {
                    return false;
                }

            }
                break;

            case 4: {
                if (c == 'a') {
                    state = 5;
                }
                else {
                    return false;
                }

            }
                break;

            case 5: {
                if (c == 't') {
                    state = 6;
                }
                else {
                    return false;
                }
            }
                break;

            case 6: {
                if (c == 'e') {
                    state = 6;
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

int init_static(vector<char> input) {
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
                if (c == 'a') {
                    state = 3;
                }
                else {
                    return -1;
                }

            }
                break;

            case 3: {
                if (c == 't') {
                    state = 4;
                }
                else {
                    return -1;
                }

            }
                break;

            case 4: {
                if (c == 'i') {
                    state = 5;
                }
                else {
                    return -1;
                }

            }
                break;

            case 5: {
                if (c == 'c') {
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
bool init_static_sem (Automat* au, vector<char>* input){

    int state = 0;
    char c;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];

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
                if (c == 'a') {
                    state = 3;
                }
                else {
                    return false;
                }

            }
                break;

            case 3: {
                if (c == 't') {
                    state = 4;
                }
                else {
                    return false;
                }

            }
                break;

            case 4: {
                if (c == 'i') {
                    state = 5;
                }
                else {
                    return false;
                }

            }
                break;

            case 5: {
                if (c == 'c') {
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

int init_void(vector<char> input) {
    int state = 0;
    char c;

    for (int i = 0; i < input.size (); i++) {
        c = (input)[i];

        switch (state) {

            case 0: {
                if (c == 'v') {
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
                if (c == 'i') {
                    state = 3;
                }
                else {
                    return -1;
                }

            }
                break;

            case 3: {
                if (c == 'd') {
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
bool init_void_sem (Automat* au, vector<char>* input){

    int state = 0;
    char c;

    for (int i = 0; i < input->size (); i++) {
        c = (*input)[i];

        switch (state) {

            case 0: {
                if (c == 'v') {
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
                if (c == 'i') {
                    state = 3;
                }
                else {
                    return false;
                }

            }
                break;

            case 3: {
                if (c == 'd') {
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
