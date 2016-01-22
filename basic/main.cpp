using namespace std;
#include <iostream>
#include "math.h"

int main()
{
	// Guess the number
	cout << "I'm thinking of a number between 0 and 1000...\n";
	int number = floor(rand() % 1000);

	int guess;
	int guesses = 0;
	do {
		cout << "Guess my number...\n";
		cin >> guess;
		if (guess < number) {
			cout << "Higher...";
		} else if (guess > number) {
			cout << "Lower...";
		}
		guesses++;
	} while (guess != number);
	cout << "You guessed my number, " << number << ", in " << guesses << " guesses." << endl;
}