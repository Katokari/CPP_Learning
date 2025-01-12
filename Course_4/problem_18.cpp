/*
#include <iostream>
using namespace std;

string getStringFromUser(string message) {
	string input;
	cin >> input;
	cin.ignore();
	return input;
}

string encryptText(string text, int key) {
	string encrypted = "";
	for (int i = 0; i < text.length(); i++) {
		encrypted += text[i] + key;
	}
	return encrypted;
}

string decryptText(string text, int key) {
	string decrypted = "";
	for (int i = 0; i < text.length(); i++) {
		decrypted += text[i] - key;
	}
	return decrypted;
}

void printOutput() {
	string text = getStringFromUser("");

	cout << "Text Before Encryption : " << text << endl;
	
	string decrypted = encryptText(text, 5);
	cout << "Text After Encryption  : " << decrypted << endl;

	cout << "Text After Decryption  : " << decryptText(decrypted, 5) << endl;
}

int main() {
	printOutput();

	return 0;
}
*/