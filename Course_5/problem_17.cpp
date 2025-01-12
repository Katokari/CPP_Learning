/*
#include <iostream>
using namespace std;

string getStringFromUser(string message) {
	string input;
	cin >> input;
	cin.ignore();
	return input;
}

bool findPassword(string pass) {
	string word = "";
	int trial = 0;
	for (char i = 65; i <= 90; i++) {
		for (char j = 65; j <= 90; j++) {
			for (char k = 65; k <= 90; k++) {
				word = "";
				word += i;
				word += j;
				word += k;
				trial++;
				
				if (pass != word)
					cout << "Trial [" << trial << "] : " << word << endl;
				else
				{
					cout << "Password is " << word << "\nFound after " << trial << " Trial(s)";
					return true;
				}
					
			}
		}
	}

	return false;
}

int main() {
	findPassword(getStringFromUser(""));

	return 0;
}
*/