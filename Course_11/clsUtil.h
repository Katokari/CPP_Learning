#pragma once
#include <iostream>
#include <vector>
#include "clsDate.h"

class clsUtil {
public:
    static void Srand() {
        srand((unsigned)time(NULL));
    }

    static int GenerateRandNum(int From, int To) { return (rand() % (To - From + 1) + From); }

    enum enCharacterType { SmallLetter = 1, CapitalLetter = 2, SpecalCharacter = 3, Digit = 4, Mix = 5};

    static char GetRandomCharacter(enCharacterType CharacterType) {
        if (CharacterType == enCharacterType::Mix)
            CharacterType = (enCharacterType)GenerateRandNum(1, 4);

        switch (CharacterType) {
        case enCharacterType::SmallLetter:
        {
            return char(GenerateRandNum(97, 122));
            break;
        }
        case enCharacterType::CapitalLetter:
        {
            return char(GenerateRandNum(65, 90));
            break;
        }
        case enCharacterType::SpecalCharacter:
        {
            return char(GenerateRandNum(33, 47));
            break;
        }
        case enCharacterType::Digit:
        {
            return char(GenerateRandNum(48, 57));
            break;
        }
        }
    }

    static std::string GenerateWord(enCharacterType CharacterType, int length) {
        std::string word = "";

        for (int i = 0; i < length; i++) {
            word += GetRandomCharacter(CharacterType);
        }

        return word;
    }

    static std::string GenerateKey(enCharacterType CharacterType) {
        std::string key = "";
        key += GenerateWord(CharacterType, 4) + "-";
        key += GenerateWord(CharacterType, 4) + "-";
        key += GenerateWord(CharacterType, 4) + "-";
        key += GenerateWord(CharacterType, 4);
        return key;
    }

    static void GenerateKeys(int num, enCharacterType CharacterType) {
        for (int i = 1; i <= num; i++) {
            std::cout << "Key [" << i << "] : " << GenerateKey(CharacterType) << std::endl;
        }
    }

    static void Swap(int& Num1, int& Num2) {
        int Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;
    }

    static void Swap(double& Num1, double& Num2) {
        double Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;
    }

    static void Swap(std::string& S1, std::string& S2) {
        std::string Temp = S1;
        S1 = S2;
        S2 = Temp;
    }

    static void Swap(clsDate& Date1, clsDate& Date2) {
        clsDate Temp = Date1;
        Date1 = Date2;
        Date2 = Temp;    
    }

    static void ShuffleArray(int arr[], int arrLength)
    {
        int j;
        for (int i = arrLength - 1; i > 0; i--) {
            j = GenerateRandNum(0, i);
            Swap(arr[i], arr[j]);
        }
    }

    static void FillArrRandNums(int arr[], int Length, int From, int To) {
        for (int i = 0; i < Length; i++) {
            arr[i] = GenerateRandNum(From, To);
        }
    }

    static void FillArrRandWords(std::string arr[], int Length, enCharacterType CharacterType, int WordLength) {
        for (int i = 0; i < Length; i++) {
            arr[i] = GenerateWord(CharacterType, WordLength);
        }       
    }

    static void FillArrRandKeys(std::string arr[], int Length, enCharacterType CharacterType) {
        for (int i = 0; i < Length; i++) {
            arr[i] = GenerateKey(CharacterType);
        }
    }

    static std::string Tab(int Num) {
        std::string Str = "";
        for (int i = 0; i < Num; i++) {
            Str += "\t";
        }
        return Str;
    }

    static std::string WhiteSpace(int Num) {
        std::string Str = "";
        for (int i = 0; i < Num; i++) {
            Str += " ";
        }
        return Str;
    }

    static std::string encryptText(std::string text, int key) {
        std::string encrypted = "";
        for (int i = 0; i < text.length(); i++) {
            encrypted += text[i] + key;
        }
        return encrypted;
    }

    static std::string decryptText(std::string text, int key) {
        std::string decrypted = "";
        for (int i = 0; i < text.length(); i++) {
            decrypted += text[i] - key;
        }
        return decrypted;
    }
};