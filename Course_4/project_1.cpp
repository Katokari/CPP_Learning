/*
#include <iostream>
#include <cstdlib>
#include <Windows.h>
using namespace std;

enum enChoices { Rock = 1, Paper = 2, Scissors = 3 };
enum enWinner { Tie = 0, Player = 1, Computer = 2 };

int ReadPositiveNumber(string message) {
	int input;
	do {
		cout << message;
		cin >> input;
	} while (input <= 0);
	return input;
}

int GenerateRandNum(int From, int To) { return (rand() % (To - From + 1) + From);}

void SetScreen(enWinner winner) {
	switch (winner) {
	case enWinner::Tie:
		system("color 6F");  // Yellow background, bright white text
		break;
	case enWinner::Player:
		system("color AF");  // Green background, bright white text
		break;
	default:
		system("color CF");  // Red background, bright white text
		break;
	}
}

void ResetConsoleToDefault() {
	system("cls");  // Clear the screen
	system("color 07"); // Set default colors (black text on white background)
}

string GetChoicesString(enChoices Choice) { return Choice == enChoices::Paper ? "Paper" : Choice == enChoices::Rock ? "Rock" : "Scissors"; }

string GetWinnerString(enWinner Winner) { return Winner == enWinner::Tie ? "Tie" : Winner == enWinner::Player ? "Player" : "Computer"; }

enChoices ReadPlayerChoice() { return (enChoices)ReadPositiveNumber("Your Choice : [1] : Rock, [2] : Paper, [3] : Scissors ? "); }

enChoices GetComputerChoice() { return (enChoices)GenerateRandNum(1, 3); }

enWinner CheckWinner(enChoices playerChoice, enChoices computerChoice) {
	return (enWinner)((((int)playerChoice - (int)computerChoice + 3) % 3 == 0) ? 0 : (((int)playerChoice - (int)computerChoice + 3) % 3 == 1) ? 1 : 2);
}
void PrintRoundResults(int roundNum, enWinner winner, enChoices playerChoice, enChoices computerChoice) {
	SetScreen(winner);

	cout << "\n\n";
	cout << "___________Round [" << roundNum + 1 << "]___________" << endl;
	cout << "\n\n";
	cout << "Player1  Choice: " << GetChoicesString(playerChoice) << endl;
	cout << "Computer Choice: " << GetChoicesString(computerChoice) << endl;
	cout << "Round Winner   : [" << GetWinnerString(winner) << "]" << endl;
	cout << "\n\n";
	cout << "______________________________" << endl;
	cout << "\n\n";
}

void PrintGameResults(int userWinCount, int computerWinCount, int tieCount, enWinner Winner, int roundsCount) {

	cout << "\t\t\t\t______________________________________________" << endl;
	cout << "\n";
	cout << "\t\t\t\t           +++ G a m e  O v e r +++           " << endl;
	cout << "\n";
	cout << "\t\t\t\t______________________________________________" << endl;
	cout << "\n\n";
	cout << "\t\t\t\t_______________[ Game Results ]_______________" << endl;
	cout << "\n\n";
	cout << "\t\t\t\tGame rounds        : " << roundsCount << endl;
	cout << "\t\t\t\tPlayer1 win times  : " << userWinCount << endl;
	cout << "\t\t\t\tComputer win times : " << computerWinCount << endl;
	cout << "\t\t\t\tDraw times         : " << tieCount << endl;
	cout << "\t\t\t\tFinal winner       : " << GetWinnerString(Winner) << endl;
	cout << "\n\n";
	cout << "\t\t\t\t_______________[ Game Results ]_______________" << endl;
	cout << "\n\n\n";
}

void PlayRound(int roundNum, int& userWinCount, int& computerWinCount, int& tieCount) {
	cout << "Round [" << roundNum + 1 << "] begins:\n\n";

	enChoices playerChoice = ReadPlayerChoice();
	enChoices computerChoice = GetComputerChoice();

	enWinner winner = CheckWinner(playerChoice, computerChoice);
	
	PrintRoundResults(roundNum, winner, playerChoice, computerChoice);

	winner == enWinner::Computer ? computerWinCount++ : winner == enWinner::Player ? userWinCount++ : tieCount++;
}

void PlayGame() {
	int playAgain, userWinCount, computerWinCount, tieCount, roundsCount;
	enWinner Winner;

	do {
		ResetConsoleToDefault();

		roundsCount = ReadPositiveNumber("How Many Rounds 1 to 10 ?\n");
		userWinCount = 0, computerWinCount = 0, tieCount = 0;

		for (int i = 0; i < roundsCount; i++) {
			PlayRound(i, userWinCount, computerWinCount, tieCount);
		}

		Winner = userWinCount > computerWinCount ? enWinner::Player : computerWinCount > userWinCount ? enWinner::Computer : enWinner::Tie;

		PrintGameResults(userWinCount, computerWinCount, tieCount, Winner, roundsCount);

		playAgain = ReadPositiveNumber("Do you want to play again? [0]:No, [1]:Yes ");

		if (!playAgain)
			break;

	} while (playAgain);
}

int main() {
	srand((unsigned)time(NULL));
	PlayGame();

	return 0;
}
*/