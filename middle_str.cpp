#include "middle_str.h"

long long len(std::string line) {
	int t = 0;
	for (int i = 0; line[i] != '\0'; i++) { t++; }
	return t;
}
bool containsNotLetter_v1(std::string line) {
	bool hasSymbol = false;
	for (int j = 0; line[j] != '\0'; j++) {
		char c = line[j];
		if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я'))) {
			hasSymbol = true;
			break;
		}
	}
	return hasSymbol;
}
bool containsNotLetter_v2(std::string line) {
	bool hasSymbol = false;
	for (int j = 0; line[j] != '\0'; j++) {
		char c = line[j];
		if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) && (c != ',') && (c != ',') || (c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я')) {
			hasSymbol = true;
			break;
		}
	}
	return hasSymbol;
}
std::string replaceAllNotLetterChars(std::string line) {
	std::string res;
	for (int i = 0; line[i] != '\0'; i++) {
		char c = line[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я')) {
			res += c;
		}
	}
	return res;
}
bool containsChar(std::string line, char c) {
	for (char cc : line)
		if (cc == c) return true;
	return false;
}
int charToInt(char c) {
	if (c == '0') return 0;
	if (c == '1') return 1;
	if (c == '2') return 2;
	if (c == '3') return 3;
	if (c == '4') return 4;
	if (c == '5') return 5;
	if (c == '6') return 6;
	if (c == '7') return 7;
	if (c == '8') return 8;
	if (c == '9') return 9;
	return 0;
}

std::string decToBin_str(std::string line) {
	std::string res;
	long long num = 0;
	for (int i = 0; line[i] != '\0'; i++) {
		num = num * 10 + charToInt(line[i]);
	}
	while (num) {
		int d = num % 2;
		if (d == 1) res = '1' + res;
		else res = '0' + res;
		num /= 2;
	}
	return res == "" ? "0" : res;
}

// main part

bool itc_isDigit(unsigned char c) {
	return c >= '0' && c <= '9';
}
unsigned char itc_toUpper(unsigned char c) {
	if (c >= 'a' && c <= 'z')
		return c - 32;
	return c;
}
unsigned char itc_changeCase(unsigned char c) {
	if (c >= 'A' && c <= 'Z')
		return c + 32;
	if (c >= 'a' && c <= 'z')
		return c - 32;

	return c;
}
bool itc_сompare(std::string s1, std::string s2) {
	return s1 == s2;
}
int itc_countWords(std::string str) {
	int res = 0;
	std::string currentWord;
	str += " ";
	for (int i = 0; str[i] != '\0'; i++) {
		char cc = str[i];
		if (cc == ' ') {
			res += !containsNotLetter_v1(currentWord);
			currentWord = "";
		}
		else {
			currentWord += cc;
		}
	}
	return res;
}
std::string itc_maxCharWord(std::string str) {
	int lastSize = 0;
	std::string currentWord, res = "";
	str += ' ';
	for (int i = 0; str[i] != '\0'; i++) {
		char cc = str[i];
		if (cc == ' ') {
			if (!containsNotLetter_v2(currentWord) && len(currentWord) > lastSize) {
				lastSize = len(currentWord);
				res = replaceAllNotLetterChars(currentWord);
			}
			currentWord = "";
		}
		else {
			currentWord += cc;
		}
	}

	return res == "" ? "error" : res;
}
char itc_sameChar(std::string str) {
	std::string chars;
	for (char c : str) {
		if (c != ' ') {
			if (!containsChar(str, c))
				chars += c;
			else
				return c;
		}
	}
}
bool itc_isFirstInSecond(std::string s1, std::string s2) {
	for (int i = 0; s2[i] != '\0'; i++) {
		bool is = true;
		for (int j = 0; s1[j] != '\0'; j++) {
			if (s2[i + j] != s1[j]) {
				is = false;
				break;
			}
		}
		if (is) return true;
	}
	return false;
}
std::string itc_Cezar(std::string str, int k) {
	std::string res;
	for (char c : str) {
		if (c + k < 'a')
			res += c + 26 + k;
		else
			res += c + k;
	}
	return res;
}
std::string itc_rmFreeSpace(std::string str) {
	while (str[0] == ' ') {
		std::string t;
		for (int i = 1; str[i] != '\0'; i++)
			t += str[i];
		str = t;
	}
	while (str[len(str) - 1] == ' ') {
		std::string t;
		for (int i = 0, l = len(str); i < l - 1; i++)
			t += str[i];
		str = t;
	}

	char lc = 'a';
	std::string t;
	for (int i = 0; str[i] != '\0'; i++) {
		char cc = str[i];
		if (!(lc == ' ' && cc == ' '))
			t += cc;
		lc = cc;
	}

	return t;
}
bool itc_isIp(std::string str) {
	bool canBe = true;
	int dots = 0;
	std::string currentNum;
	str += '.';
	for (int i = 0; str[i] != '\0'; i++) {
		char c = str[i];
		if (c == '.') {
			dots++;
			int num = 0;
			for (int j = 0; currentNum[j] != '\0'; j++) {
				char cc = currentNum[j];
				if (itc_isDigit(cc)) {
					int d = charToInt(cc);
					num = num * 10 + d;
				}
				else {
					canBe = false;
					break;
				}
			}
			if (num > 255) {
				canBe = false;
				break;
			}
			currentNum = "";
		}
		else {
			currentNum += c;
		}
	}
	if (canBe && dots == 4)
		return true;
	return false;
}
std::string itc_DecToBin(std::string str) {
	std::string lastNum, res;
	for (int i = 0; str[i] != '\0'; i++) {
		char c = str[i];
		if (itc_isDigit(c)) {
			lastNum += c;
		}
		else {
			if (lastNum != "") {
				res += decToBin_str(lastNum);
				lastNum = "";
			}
			res += c;
		}
	}
	if (lastNum != "") {
		res += decToBin_str(lastNum);
	}
	return res;
}
std::string itc_decToBase(int num, int base) {
	std::string res;
	while (num)
	{
		int d = num % base;
		if (d > 9)
			res = (char)('A' - 10 + d) + res;
		else
			res = (char)('0' + d) + res;
		num /= base;
	}
	return res;
}
