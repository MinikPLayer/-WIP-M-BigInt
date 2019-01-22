#pragma once
#ifndef BigInt_hpp
#define BigInt_hpp

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class BigInt
{
public:
	bool ujemna = false;
	int potega(int a, int pot);
	int charToInt(char c);
	void cleanZero();
	short isBigger(BigInt int2);
	vector<bool> intToBinary(long long int c);
public:
	vector<bool> binary;

	string toDecimal();

	BigInt operator+(BigInt int2);
	BigInt operator+(long long int int2);
	void operator+=(BigInt int2);
	void operator+=(long long int int2);
	void operator=(BigInt int2);
	void operator= (long long int int2);
	BigInt operator-(BigInt int2);
	bool operator<(BigInt int2);
	bool operator<=(BigInt int2);
	bool operator>(BigInt int2);
	bool operator>=(BigInt int2);

	friend ostream& operator<< (ostream& stream, BigInt bigint);
};


#endif // !BigInt_hpp
