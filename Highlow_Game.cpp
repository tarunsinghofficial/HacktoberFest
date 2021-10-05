#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int guess;
	int compNum;
	int counter;
	srand(time(0));//seed
	char choice;
	bool game = true;

	do{
		compNum = (rand() % 1000) + 1;
		counter = 1;
		do {
			cout << "Enter a number between 1 - 1000" << endl;
			cin >> guess;

			if (guess > compNum) {
				counter++;
				cout << "Too High." << endl;
			}
			else if (guess < compNum) {

				counter++;
				cout << "Too Low." << endl;
			}
			if (guess == compNum) {
				cout << "You won! The computer number is " << compNum << "."
					<< " You did it in " << counter << " tries." << endl;
				cout << "Press 'q' or 'Q' to quit" << endl;
				cin >> choice;
			}

		} while (guess != compNum);
		if (choice == 'Q' || choice == 'q') {
			game = false;
			break;
		}
	} while (game !=false);

	return 0;
} 