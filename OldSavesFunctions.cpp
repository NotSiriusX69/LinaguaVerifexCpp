//void oldAutomatStateFinder () {
//	//counters that count for any brackets / paranthesis that are open, example: a(  / a[
//	int opened_brackets = 0;
//	int opened_paranthesis = 0;
//
//	char q0 = autom->q0;
//
//	//calculating initial state value (for the state values and what they represent, reffer to whiteboard drawing)
//	if (isalpha (q0)) { //(a*b)ab  [0-9] [a-z]
//		autom->states[0] = 1;
//	}
//	else if (q0 == '(') {
//		autom->states[0] = 2;
//	}
//	else if (q0 == '[') {
//		autom->states[0] = 3;
//	}
//	else {
//		//state -1 indicates error
//		//autom->states[0] = -1;
//	}
//
//
//	for (int i = 0; i < autom->delta.size (); i++) {
//		//filling on each iteration the values or each delta
//		char origin = autom->delta[i].origin;
//		char label = 'k';
//		char target = autom->delta[i].target;
//
//		switch (autom->states[states_counter]) {
//			//alphabet char entered: [a-z]
//		case 1: {
//			if (isalpha (target)) {
//				autom->states[states_counter + 1] = 1;
//			}
//			else if (target == '(') {
//				autom->states[states_counter + 1] = 2;
//			}
//			else if (target == '[') {
//				autom->states[states_counter + 1] = 3;
//			}
//			else if (target == ')' && (isalpha (label) || checkIfSymbol (label, "*+")) && opened_paranthesis > 0) {
//				autom->states[states_counter + 1] = 5;
//			}
//			else if (target == ']' && isdigit (label) && opened_brackets > 0) {
//				autom->states[states_counter + 1] = 6;
//			}
//			else if (checkIfSymbol (target, "*+")) {
//				autom->states[states_counter + 1] = 7;
//			}
//
//		}
//			  break;
//			  //paranthesis entered: (
//		case 2: {
//			opened_paranthesis++;
//			if (isalpha (target)) {
//				autom->states[states_counter + 1] = 1;
//			}
//			else if (target == '(') {
//				autom->states[states_counter + 1] = 2;
//			}
//			else if (target == '[') {
//				autom->states[states_counter + 1] = 3;
//			}
//
//		}
//			  break;
//			  //brackets entered: [
//		case 3: {
//			opened_brackets++;
//			if (isdigit (target)) {
//				autom->states[states_counter + 1] = 4;
//			}
//		}
//			  break;
//
//			  //digit entered or - entered (for letters, do same but with isalpha)
//		case 4: {
//			if ((target == '-' && isdigit (label)) && opened_brackets > 0) {
//				autom->states[states_counter + 1] = 4;
//			}
//			else if (label == '-' && opened_brackets > 0 && isdigit (target)) {
//				autom->states[states_counter + 1] = 4;
//			}
//			else if (isdigit (label) && opened_brackets > 0 && target != ']') {
//				autom->states[states_counter + 1] = 4;
//			}
//			else if (target == ']' && isdigit (label) && opened_brackets > 0) {
//				autom->states[states_counter + 1] = 6;
//			}
//		}
//			  break;
//
//			  //paranthesis closed
//		case 5: {
//			opened_paranthesis--;
//			if (isalpha (target)) {
//				autom->states[states_counter + 1] = 1;
//			}
//			else if (target == '(') {
//				autom->states[states_counter + 1] = 2;
//			}
//			else if (target == '[') {
//				autom->states[states_counter + 1] = 3;
//			}
//			else if (checkIfSymbol (target, "*+")) {
//				autom->states[states_counter + 1] = 7;
//			}
//
//		}
//			  break;
//			  //brackets closed
//		case 6: {
//			opened_brackets--;
//			opened_paranthesis--;
//			if (isalpha (target)) {
//				autom->states[states_counter + 1] = 1;
//			}
//			else if (target == '(') {
//				autom->states[states_counter + 1] = 2;
//			}
//			else if (target == '[') {
//				autom->states[states_counter + 1] = 3;
//			}
//			else if (checkIfSymbol (target, "*+")) {
//				autom->states[states_counter + 1] = 7;
//			}
//		}
//			  break;
//
//			  //number repetitions specifier entered (* or +)
//		case 7: {
//			if (isalpha (target)) {
//				autom->states[states_counter + 1] = 1;
//			}
//			else if (target == ')' && (isalpha (label) || checkIfSymbol (label, "*+")) && opened_paranthesis > 0) {
//				autom->states[states_counter + 1] = 5;
//			}
//			else if (target == '(') {
//				autom->states[states_counter + 1] = 2;
//			}
//			else if (target == '[') {
//				autom->states[states_counter + 1] = 3;
//			}
//
//		}
//			  break;
//
//
//		default: {
//			cout << "Error" << endl;
//		}
//			   break;
//
//
//		}
//
//
//		states_counter++;
//	}
//}