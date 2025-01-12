#include <iostream>
#include <cstdlib>
#include <Windows.h>
using namespace std;

enum enOpType { Add = 1, Sub, Mul, Div, Mix };
enum enLevel { Easy = 1, Mid, Hard, Mix2 };

struct stGameInfo {
	enOpType OpType;
	enLevel Level;
	short RoundsCount;
	short RightAns;
	short WrongAns;
};

struct stRoundInfo {
	enOpType OpType;
	enLevel Level;
	short FirstNum;
	short SecondNum;
	short Answer;
	short PlayerAns;
	bool RightOrWrong;
	short RoundCount;
};

int ReadPositiveNumber(string message) {
	int input;
	do {
		cout << message;
		cin >> input;
	} while (input < 0);
	return input;
}

int ReadNumberInRange(int From, int To, string Message) {
	int input;
	do {
		cout << Message;
		cin >> input;
	} while (input < From || input > To);
	return input;
}

int GenerateRandNum(int From, int To) { return (rand() % (To - From + 1) + From); }

void SetScreen(stRoundInfo& RoundInfo) {
	switch (RoundInfo.RightOrWrong) {
	case true:
		system("color AF");  // Green background, bright white text
		break;
	default:
		system("color CF");  // Red background, bright white text
		break;
	}
}

string GetOpTypeText(enOpType OpType) {
	string OpTypes[5] = { "+", "-", "*", "/", "Mix"};
	return OpTypes[(int)OpType - 1];
}

string GetLevelText(enLevel Level) {
	string Levels[4] = { "Easy", "Mid", "Hard", "Mix" };
	return Levels[(int)Level - 1];
}

void ResetConsoleToDefault() {
	system("cls");  // Clear the screen
	system("color 07"); // Set default colors (black text on white background)
}

enLevel GetRoundLevel(stGameInfo& GameInfo) { 
	return ((int)GameInfo.Level != 4) ? GameInfo.Level : (enLevel)GenerateRandNum(1, 3);
}

enOpType GetRoundOpType(stGameInfo& GameInfo) {
	return ((int)GameInfo.OpType != 5) ? GameInfo.OpType : (enOpType)GenerateRandNum(1, 4);
}

void PrintQuestion(stRoundInfo& RoundInfo, stGameInfo& GameInfo) {
	cout << "\n\n";
	cout << "Question [" << RoundInfo.RoundCount << "/" << GameInfo.RoundsCount << "]";
	cout << "\n\n";
	cout << RoundInfo.FirstNum << endl;
	cout << RoundInfo.SecondNum << " " << GetOpTypeText(RoundInfo.OpType) << endl;
	cout << "________" << endl;
}

stGameInfo ReadGameInfo() {
	stGameInfo GameInfo;

	GameInfo.RoundsCount = ReadPositiveNumber("How many questions do you want to answer ? ");
	GameInfo.Level = (enLevel)ReadNumberInRange(1, 4, "Enter Questions Level [1] Easy, [2] Mid, [3] Hard, [4] Mix ? ");
	GameInfo.OpType = (enOpType)ReadNumberInRange(1, 5, "Enter Questions Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ");
	GameInfo.RightAns = 0;
	GameInfo.WrongAns = 0;

	return GameInfo;
}

int GetRoundAnswer(stRoundInfo& RoundInfo) {
	switch (RoundInfo.OpType) {
	case enOpType::Add:
		return floor(RoundInfo.FirstNum + RoundInfo.SecondNum);
	case enOpType::Sub:
		return floor(RoundInfo.FirstNum - RoundInfo.SecondNum);
	case enOpType::Mul:
		return floor(RoundInfo.FirstNum * RoundInfo.SecondNum);
	case enOpType::Div:
		return floor(RoundInfo.FirstNum / RoundInfo.SecondNum);
	}
}

stRoundInfo GetRoundInfo(stGameInfo& GameInfo, int i) {
	stRoundInfo RoundInfo;

	RoundInfo.Level = GetRoundLevel(GameInfo);
	RoundInfo.OpType = GetRoundOpType(GameInfo);
	short x = (short)RoundInfo.Level;
	int minRange = (10 * (x - 1) * (x - 1) + 1);
	int maxRange = (10 * x * x) + (30 * x) - 30;
	RoundInfo.FirstNum = GenerateRandNum(minRange, maxRange);
	RoundInfo.SecondNum = GenerateRandNum(minRange, maxRange);
	RoundInfo.RoundCount = i;
	RoundInfo.Answer = GetRoundAnswer(RoundInfo);

	return RoundInfo;
}

void ValidateAnswer(stRoundInfo& RoundInfo, stGameInfo& GameInfo) {
	if (RoundInfo.Answer == RoundInfo.PlayerAns) {
		cout << "Right Answer :)" << endl;
		cout << "\n\n\n";
		RoundInfo.RightOrWrong = true;
		GameInfo.RightAns++;
		SetScreen(RoundInfo);
	}
	else {
		cout << "Wrong Answer :(" << endl;
		cout << "The right answer is: " << RoundInfo.Answer << endl;
		cout << "\n\n\n";
		RoundInfo.RightOrWrong = false;
		GameInfo.WrongAns++;
		SetScreen(RoundInfo);
	}
}

void PlayRound(stGameInfo& GameInfo, int i) {
	stRoundInfo RoundInfo = GetRoundInfo(GameInfo, i);

	PrintQuestion(RoundInfo, GameInfo);

	RoundInfo.PlayerAns = ReadPositiveNumber("");

	ValidateAnswer(RoundInfo, GameInfo);
}

void PrintGameOverScreen(stGameInfo& GameInfo) {
	cout << "_______________________________" << endl;
	cout << endl;
	cout << " Final Results is " << (GameInfo.RightAns > GameInfo.WrongAns) ? "Pass :)" : "Fail :(";
	cout << endl << endl;
	cout << "_______________________________" << endl;
	cout << endl;
	cout << "Number of Questions: " << GameInfo.RoundsCount << endl;
	cout << "Questions Level    : " << GetLevelText(GameInfo.Level) << endl;
	cout << "Op Type            : " << GetOpTypeText(GameInfo.OpType) << endl;
	cout << "Number of Right Answers: " << GameInfo.RightAns << endl;
	cout << "Number of Wrong Answers: " << GameInfo.WrongAns << endl;
	cout << endl;
	cout << "_______________________________" << endl;
	cout << endl;
}

void PlayGame() {
	short PlayAgain = 1;
	do {
		ResetConsoleToDefault();
		stGameInfo GameInfo = ReadGameInfo();

		for (int i = 1; i <= GameInfo.RoundsCount; i++)
			PlayRound(GameInfo, i);

		PrintGameOverScreen(GameInfo);

		cout << "Do you want to play again? [1] Yes, [0] No?";
		cin >> PlayAgain;

	} while (PlayAgain);
}

int main() {
	srand((unsigned)time(NULL));
	PlayGame();

	return 0;
}