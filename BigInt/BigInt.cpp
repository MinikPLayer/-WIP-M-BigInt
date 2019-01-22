#include "BigInt.hpp"

using namespace std;

int BigInt::potega(int a, int pot)
{
	int cache = a;
	if (pot == 0) return 1;
	if (pot == 1) return a;
	for (int i = 1; i < pot; i++)
	{
		a *= cache;
	}
	return a;
}

int BigInt::charToInt(char c)
{
	return ((int)c + 255) % 255;
}

void BigInt::cleanZero()
{
	for (int i = 0; i < this->binary.size(); i++)
	{
		if (binary[i] == 1) return;
		this->binary.erase(this->binary.begin(), this->binary.begin() + 1);
	}
}

short BigInt::isBigger(BigInt int2)
{
	bool invert = 0;
	if (this->ujemna && !int2.ujemna)
	{
		return true;
	}
	if (!this->ujemna && int2.ujemna)
	{
		return false;
	}
	if (this->ujemna && int2.ujemna)
	{
		invert = true;
	}

	if (this->binary.size() < int2.binary.size())
	{
		if (invert) return false;
		return true;
	}
	if (this->binary.size() > int2.binary.size())
	{
		if (invert) return true;
		return false;
	}
	for (int i = 0; i < this->binary.size(); i++)
	{
		if (this->binary[i] != int2.binary[i])
		{
			if (this->binary[i] > int2.binary[i])
			{
				if (invert) return true;
				return false;
			}
			else
			{
				if (invert) return false;
				return true;
			}
		}
	}
	return 2;
}

vector<bool> BigInt::intToBinary(long long int c)
{
	vector<bool> returnValue;
	while (c != 0)
	{
		returnValue.insert(returnValue.begin(), c % 2);
		c /= 2;
	}
	return returnValue;
}

string BigInt::toDecimal()
{
	string returnValue;

	int returnValueInt = 0;
	for (int i = 0; i < binary.size(); i++)
	{
		if (binary[i] == 1) returnValueInt += potega(2, binary.size() - i - 1);
	}

	returnValue = to_string(returnValueInt);

	return returnValue;
}

BigInt BigInt::operator+(BigInt int2)
{
	if (int2.ujemna && !this->ujemna)
	{
		int2.ujemna = false;
		return this->operator-(int2);
		//return BigInt();
	}
	if (this->ujemna && !int2.ujemna)
	{
		this->ujemna = false;
		return int2.operator-(*this);
		//return BigInt();
	}
	BigInt returnValue;
	while (int2.binary.size() < this->binary.size())
	{
		bool value = 0;
		int2.binary.insert(int2.binary.begin(), false);
	}
	while (int2.binary.size() > this->binary.size())
	{
		bool value = 0;
		this->binary.insert(this->binary.begin(), false);
	}

	short przejscie = 0;

	for (int i = this->binary.size() - 1; i >= 0; i--)
	{
		short suma = this->binary[i] + int2.binary[i];
		if (przejscie > 0)
		{
			suma += przejscie;
			przejscie = 0;
		}
		przejscie = suma / 2;
		returnValue.binary.insert(returnValue.binary.begin(), suma % 2);
	}

	if (przejscie > 0)
	{
		returnValue.binary.insert(returnValue.binary.begin(), true);
		przejscie = 0;
	}

	this->cleanZero();

	return returnValue;
}

BigInt BigInt::operator+(long long int int2)
{
	BigInt int2ToFunction;
	int2ToFunction.binary = intToBinary(int2);

	return this->operator+(int2ToFunction);
}

void BigInt::operator+=(BigInt int2)
{
	*this = *this + int2;
}

void BigInt::operator+=(long long int int2)
{
	BigInt int2ToFunction;
	int2ToFunction.binary = intToBinary(int2);
	this->operator+=(int2ToFunction);
}

void BigInt::operator=(BigInt int2)
{
	//*this = int2;
	this->binary = int2.binary;
	this->ujemna = int2.ujemna;
}

void BigInt::operator=(long long int int2)
{
	this->binary = intToBinary(int2);
	if (int2 < 0) this->ujemna = true;
}

BigInt BigInt::operator-(BigInt int2)
{
	//return BigInt();
	BigInt returnValue;



	return returnValue;
}

bool BigInt::operator<(BigInt int2)
{
	int bgValue = this->isBigger(int2);
	switch (bgValue)
	{
	default:
		return 0;
		break;
	case 0:
		return 0;
		break;
	case 1:
		return 1;
		break;
	case 2:
		return 0;
		break;
	}
}

bool BigInt::operator<=(BigInt int2)
{
	int bgValue = this->isBigger(int2);
	switch (bgValue)
	{
	default:
		return 0;
		break;
	case 0:
		return 0;
		break;
	case 1:
		return 1;
		break;
	case 2:
		return 1;
		break;
	}
}

bool BigInt::operator>(BigInt int2)
{
	int bgValue = this->isBigger(int2);
	switch (bgValue)
	{
	default:
		return 1;
		break;
	case 0:
		return 1;
		break;
	case 1:
		return 0;
		break;
	case 2:
		return 0;
		break;
	}
}

bool BigInt::operator>=(BigInt int2)
{
	int bgValue = this->isBigger(int2);
	switch (bgValue)
	{
	default:
		return 1;
		break;
	case 0:
		return 1;
		break;
	case 1:
		return 0;
		break;
	case 2:
		return 1;
		break;
	}
}

ostream & operator<<(ostream & stream, BigInt bigint)
{
	if (bigint.ujemna) cout << "-";
	cout << bigint.toDecimal();
	return stream;
}
