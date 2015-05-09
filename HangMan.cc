#include <iostream>
#include <string>

using namespace std;

int hangMan(string word) {
	int misses = 0;
	int numberGuessed = 0;
	string output = word;
	for (int i = 0; i < output.length(); i++) {
		output[i] = '_';
	}
	// setting # of tries
	while (numberGuessed < word.length()) {
		cout << "Guess a letter in the word ";
		cout << output << " : ";
		char guess;
		// user's input guess
		cin >> guess;

		bool correctGuess = false;
		bool duplicate = false;
		for (int i = 0; i < word.length(); i++) 
			if (guess == word[i]) {
			   if (output[i] == word[i]) {
			      cout << guess << " has already been guessed. \n" << endl;
			      duplicate = true;
			      break;
			   } else {
				output[i] = word[i];
				numberGuessed++;
				correctGuess = true;
				}
			}
			if (duplicate)
			   continue;

			if (correctGuess == false) {
				misses++;
				cout << guess << " is not in the word! Try again. \n" << endl;;
				}
		}
	
	cout << "Correct! Word is " << word << "!" << endl; 
	return misses;
	
}

int main() {
	hangMan("compsci");
}
