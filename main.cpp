// SimpleXPalindrome
// Copyright SimpleXBelief56

#include <iostream>

using namespace std;

// We need three functions:
// [1] getStringLength: Get the length of the character array passed through the parameter
//
// [2] getReversedCString: Reverses the character array (C-Style String) passed through the parameter
//
// [3] Palindromes: Checks and Compares two arrays, the first one which is the one the user inputed and
// second one is the reversed one. The characters are checked side-by-sde

// Example of the Palindromes check
//
// Word: Noon
//
//	n == n
//	o == o		*NOTE: '\0' is not checked inside the function
//	o == o
//	n == n
// 
//

int getStringLength(char* word);
char* getReversedCString(char* currentWordPosition);
int Palindromes(char* initialInput, char* reversed, int length);

int main() {
	while (1) {
		char characterArray[20];
		int characterLength;
		cout << "Enter Char Please: "; cin >> characterArray; // Input
		characterLength = getStringLength(characterArray); // Get Length Of Character Array
		char* reversed = getReversedCString(characterArray);
	}

}

int Palindromes(char* initialInput, char* reversed, int length) {
	cout << "---------------------------" << endl;
	// To make sure that all characters inside the array was checked and match
	// we want to keep track of how many times the characters match. If the value
	// is less than the length, that means not all characters match
	int charPassed = 0;

	for (int x = 0; x <= length; x++) {
		// Make characterArray from Main() all lowercase
		initialInput[x] = tolower(initialInput[x]);
	}

	for (int i = 0; i < length; i++) {
		// Compare both char arrays, side by side, while avoiding '\0' at the end
		// which threw a false flag
		if (initialInput[i] == reversed[i]) {
			charPassed++;
		}
	}
	if (charPassed == length) {
		// If the value is equal to length, all characters match;
		return true;
	}
	else {
		// Else if value is not equal to length, all characters DO not match;
		return false;
	}
}

char* getReversedCString(char* currentWordPosition) {
	// Init. Variables
	char reversedString[20];
	char tempVariable;
	int currentWordPosition_Length = getStringLength(currentWordPosition);

	for (int i = 0; i <= currentWordPosition_Length + 1; i++) {
		tempVariable = currentWordPosition[currentWordPosition_Length - i];
		if (tempVariable == 0) {
			// Avoid inserting the '\0' at the start of the reversed array
			continue;
		}
		else {
			// To make sure the word is a Palindromes, make all letters lowercase
			reversedString[i] = tolower(tempVariable);
		}

		if (i == currentWordPosition_Length + 1) {
			// At the end of the array, insert the '\0'
			reversedString[i] = '\0';
		}
	}

	for (int y = 0; y < currentWordPosition_Length + 2; y++) {
		// Fix positioning of '\0' inside array
		// Shift Elements to the left one
		reversedString[y - 1] = reversedString[y];
	}

	// Use a boolean variabe, to only accept returned boolean statements
	if (currentWordPosition_Length <= 3) {
		cout << "---------------------------" << endl;
		cout << "The word " << currentWordPosition << " is not a Palindromes" << endl;
		cout << "---------------------------" << endl;
		return 0;
	}

	if (currentWordPosition_Length > 20) {
		cout << "Exiting....." << endl;
		exit;
	}

	bool PalindromesBool = Palindromes(currentWordPosition, reversedString, currentWordPosition_Length);
	if (PalindromesBool == true) {
		cout << "The word " << currentWordPosition << " is a Palindromes" << endl;
	}
	else {
		cout << "The word " << currentWordPosition << " is not a Palindromes" << endl;
	}

	cout << "---------------------------" << endl;

}



int getStringLength(char* word) {
	// return character array length
	int stringLength = strlen(word);
	return stringLength;
}
