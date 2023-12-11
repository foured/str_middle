#ifndef MIDDLE_STR
#define MIDDLE_STR

#include <iostream>
#include <string>

long long len(std::string line);
bool containsNotLetter_v1(std::string line);
bool containsNotLetter_v2(std::string line);
std::string replaceAllNotLetterChars(std::string line);
bool containsChar(std::string line, char c);
int charToInt(char c);
std::string decToBin_str(std::string line);

bool itc_isDigit(unsigned char c);
unsigned char itc_toUpper(unsigned char c);
unsigned char itc_changeCase(unsigned char c);
bool itc_compare(std::string s1, std::string s2);
int itc_countWords(std::string str);
std::string itc_maxCharWord(std::string str);
char itc_sameChar(std::string str);
bool itc_isFirstInSecond(std::string s1, std::string s2);
std::string itc_Cezar(std::string str, int k);
std::string itc_rmFreeSpace(std::string str);
bool itc_isIp(std::string str);
std::string itc_DecToBin(std::string str);
std::string itc_decToBase(int num, int base);

#endif
