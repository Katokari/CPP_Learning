#pragma once
#include <iostream>
#include <vector>

class clsString {
private:
    std::string _value;

public:
    clsString() {
        _value = "";
    }

    clsString(std::string value) {
        _value = value;
    }

    void SetValue(std::string value) {
        _value = value;
    }

    std::string GetValue() {
        return _value;
    }

    static int CountWords(std::string Str) {
        std::string Delim = " ";
        short pos = 0;
        std::string Word;
        int Counter = 0;

        while ((pos = Str.find(Delim)) != std::string::npos) {
            Word = Str.substr(0, pos);
            if (Word != "") {
                Counter++;
            }
            Str.erase(0, pos + Delim.length());
        } 

        if (Str != "") {
            Counter++;
        }
        
        return Counter;
    }

    int CountWords() {
        return CountWords(_value);
    }

    static int Length(std::string Str) {
        return Str.length();
    }

    int Length() {
        return Length(_value);
    }

    static std::string UpperFirstLetterOfEachWord(std::string Str) {
        bool IsFirstLetter = true;
        for (int i = 0; i < Str.length(); i++) {
            if (IsFirstLetter && Str[i] != ' ')
                Str[i] = toupper(Str[i]);
            IsFirstLetter = (Str[i] == ' ') ? true : false;
        }
        return Str;
    }

    void UpperFirstLetterOfEachWord() {
        _value = UpperFirstLetterOfEachWord(_value);
    }

    static std::string LowerFirstLetterOfEachWord(std::string Str) {
        bool IsFirstLetter = true;
        for (int i = 0; i < Str.length(); i++) {
            if (IsFirstLetter && Str[i] != ' ')
                Str[i] = tolower(Str[i]);
            IsFirstLetter = (Str[i] == ' ') ? true : false;
        }
        return Str;
    }

    void LowerFirstLetterOfEachWord() {
        _value = LowerFirstLetterOfEachWord(_value);
    }

	static std::string ToUpper(std::string Str) {
		for (int i = 0; i < Str.size(); i++)
			Str[i] = toupper(Str[i]);
		return Str;
	}

    void ToUpper() {
        _value = ToUpper(_value);
    }

	static std::string ToLower(std::string Str) {
		for (int i = 0; i < Str.size(); i++)
			Str[i] = tolower(Str[i]);
		return Str;
	}

    void ToLower() {
        _value = ToLower(_value);
    }

    static char InvertLetterCase(char Char) { return isupper(Char) ? tolower(Char) : toupper(Char); }

    static std::string InvertAllLettersCase(std::string Str) {
        for (int i = 0; i < Str.length(); i++)
            Str[i] = InvertLetterCase(Str[i]);
        return Str;
    }

    void InvertAllLettersCase() {
        _value = InvertAllLettersCase(_value);
    }

    enum enWhatToCount { Small = 0, Capital, All };

    static int CountLetters(std::string Str, enWhatToCount WhatToCount = enWhatToCount::All) {
        if (WhatToCount == enWhatToCount::All) {
            return Str.length();
        }

        int Count = 0;
        for (int i = 0; i < Str.length(); i++)
        {
            if (WhatToCount == enWhatToCount::Small && islower(Str[i]))
                Count++;

            if (WhatToCount == enWhatToCount::Capital && isupper(Str[i]))
                Count++;
        }

        return Count;
    }

    static int CountCapitalLetters(std::string Str) {
        return CountLetters(Str, enWhatToCount::Capital);
    }

    int CountCapitalLetters() {
        return CountLetters(_value, enWhatToCount::Capital);
    }

    static int CountSmallLetters(std::string Str) {
        return CountLetters(Str, enWhatToCount::Small);
    }

    int CountSmallLetters() {
        return CountLetters(_value, enWhatToCount::Small);
    }

    static bool IsVowel(char Char) {
        Char = tolower(Char);
        return (Char == 'a' || Char == 'o' || Char == 'i' || Char == 'u' || Char == 'e');

    }

    static int CountVowels(std::string Str) {
        int Count = 0;
        for (int i = 0; i < Str.length(); i++) {
            if (IsVowel(Str[i]))
                Count++;
        }
        return Count;
    }

    int CountVowels() {
        return CountVowels(_value);
    }

    static int CountLetter(std::string Str, char LetterToCount, bool MatchCase = true) {
        int Count = 0;
        for (int i = 0; i < Str.length(); i++) {
            if (MatchCase == true)
            {
                if (Str[i] == LetterToCount)
                    Count++;
            }
            else
            {
                if (tolower(Str[i]) == tolower(LetterToCount))
                    Count++;
            }
        }
        return Count;
    }

    int CountLetter(char LetterToCount, bool MatchCase = true) {
        return CountLetter(_value, MatchCase);
    }

    static std::vector<std::string> Split(std::string Str, std::string Delim) {
        std::vector<std::string> vWords;
        short pos = 0;
        std::string Word;

        while ((pos = Str.find(Delim)) != std::string::npos) {
            Word = Str.substr(0, pos);
            if (Word != "") {
                vWords.push_back(Word);
            }
            Str.erase(0, pos + Delim.length());
        } 

        if (Str != "") {
            vWords.push_back(Str);
        }
        
        return vWords;
    }

    std::vector<std::string> Split(std::string Delim = " ") {
        return Split(_value, Delim);
    }

    static std::string TrimLeft(std::string Str) {
        for (int i = 0; i < Str.length(); i++) {
            if (Str[i] != ' ') {
                return Str.substr(i);
            }
        }
        return "";
    }

    void TrimLeft() {
        _value = TrimLeft(_value);
    }

    static std::string TrimRight(std::string Str) {
        for (int i = Str.length() - 1; i > 0; i--) {
            if (Str[i] != ' ') {
                return Str.substr(0, i + 1);
            }
        }
        return "";
    }

    void TrimRight() {
        _value = TrimRight(_value);
    }

    static std::string Trim(std::string Str) { return TrimLeft(TrimRight(Str)); }

    void Trim() {
        _value = Trim(_value); 
    }

    static std::string JoinString(std::vector<std::string> vWords, std::string Delim = " ") {
        std::string Str = "";
        std::vector<std::string>::iterator Iter;
        for (Iter = vWords.begin(); Iter != vWords.end(); Iter++) {
            Str += *Iter + Delim;
        }
        return Str.substr(0, Str.length() - Delim.length());
    }

    static std::string JoinString(std::string vWords[], int size, std::string Delim = " ") {
        std::string Str = "";
        for (int i = 0; i < size; i++) {
            Str += *(vWords + i) + Delim;
        }
        return Str.substr(0, Str.length() - Delim.length());
    }

    static std::string ReverseWords(std::string Str) {
        std::string NewStr = "";
        std::string Delim = "#";
        std::vector<std::string> vWords = Split(Str, Delim);
        std::vector<std::string>::reverse_iterator Iter;
        for (Iter = vWords.rbegin(); Iter != vWords.rend(); Iter++) {
            NewStr += *Iter;
            if (Iter+1 != vWords.rend())
                NewStr += Delim;
        }
        return NewStr;
    }

    void ReverseWords() {
        _value = ReverseWords(_value);
    }

    static std::string ReplaceWords(std::string Str, std::string ReplaceFrom, std::string ReplaceTo, bool MatchCase = true) {
        std::vector<std::string> vWords = Split(Str, " ");

        for (std::vector<std::string>::iterator i = vWords.begin(); i < vWords.end(); i++) {
            if (MatchCase) {
                if (ToLower(*i) == ToLower(ReplaceFrom)) {
                    *i = ReplaceTo;
                }
            } else {
                if (*i == ReplaceFrom) {
                    *i = ReplaceTo;
                }
            }
        }

        return JoinString(vWords);
    }

    void ReplaceWords(std::string ReplaceFrom, std::string ReplaceTo, bool MatchCase = true) {
        _value = ReplaceWords(_value, ReplaceFrom, ReplaceTo, MatchCase);
    }

    static bool IsPunctuation(char Char) {
        if (Char >= 33 && Char <= 47) {
            return true;
        }
        return false;
    }

    static std::string RemovePunctuations(std::string Str) {
        std::string S1 = "";
        for (std::string::iterator i = Str.begin(); i != Str.end(); i++) {
            if (!IsPunctuation(*i)) {
                S1 += *i;
            }
        }
        return S1;
    }

    void RemovePunctuations() {
        _value = RemovePunctuations(_value);
    }
};