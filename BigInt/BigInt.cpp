#include "BigInt.hpp"

using namespace std;

string BigInt::potega(string a, long long int pot)
{
	string cache = a;
	if (pot == 0) return "1";
	if (pot == 1) return a;
	for (long long int i = 1; i < pot; i++)
	{
		a = multipleDecimal(a, cache);
	}
	return a;

}

int BigInt::szybkaPotega(int a, int pot)
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
	while (this->binary[0] == 0)
	{
		this->binary.erase(this->binary.begin());
	}
}

void BigInt::cleanZero(string & int1)
{
	while (int1[0] == 0)
	{
		int1.erase(0);
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

string BigInt::multipleDecimal(string int1, string int2)
{
	string returnValue = "0";

	vector<string> rtInt;

	int rtIntiterator = 0;

	for (int i = int2.size() - 1; i >= 0; i--)
	{
		int przejscie = 0;
		rtInt.push_back("");
		for (int j = int1.size() - 1; j >= 0; j--)
		{
			int value = ( int2[i] - 48 ) * ( int1[j] - 48 );
			value += przejscie;
			przejscie = value / 10;
			rtInt[rtIntiterator].insert(0, to_string(value % 10));
		}
		if (przejscie > 0)
		{
			rtInt[rtIntiterator].insert(0, to_string(przejscie));
		}
		rtIntiterator++;
	}


	for (int i = 0; i < rtIntiterator; i++)
	{
		for (int j = 0; j < i; j++)
		{
			rtInt[i].insert(rtInt[i].size(), "0");
		}
		returnValue = this->addDecimal(returnValue, rtInt[i]);
		//cout << "RtInt[" << i << "]: " << rtInt[i] << endl;
	}

	//cout << "rtIterator size: " << rtIntiterator << endl;
	//cout << "int1 size: " << int1.size() << endl;
	//cout << "int2 size: " << int2.size() << endl;


	return returnValue;
}

string BigInt::addDecimal(string int1, string int2)
{
	string returnValue;


	while (int1.size() < int2.size())
	{
		bool value = 0;
		int1.insert(0, "0");
	}
	while (int1.size() > int2.size())
	{
		bool value = 0;
		int2.insert(0, "0");
	}

	short przejscie = 0;

	for (int i = int1.size() - 1; i >= 0; i--)
	{
		short suma = int1[i] - 48 + int2[i] - 48;
		if (przejscie > 0)
		{
			suma += przejscie;
			przejscie = 0;
		}
		przejscie = suma / 10;
		returnValue.insert(0, to_string( suma % 10));
	}

	if (przejscie > 0)
	{
		returnValue.insert(0, to_string(przejscie));
		przejscie = 0;
	}

	return returnValue;
}

string BigInt::toDecimal()
{
	string returnValue;


	int potegaS = 1024;
	//cout << "Test potegi." << " 2^" << potegaS << " = " << potega("2", potegaS) <<  endl;


	//cout << "Multiple decimal test, 6248762876427868473268742638746784326876342568423657832647586234765783246578623785623784567823657826347856237845672834657823657826387456289376587236478562347856237845678236457823645789236457896 * 672386457826345237856782364576243785689723657329848923975786432785623785678293645786234875627834657823645782647582634578264879562378456728346578234657826947859627834562783462786578264578236457263478596237845627893657823965782365782369457823657829643578926 = \"" << this->multipleDecimal("6248762876427868473268742638746784326876342568423657832647586234765783246578623785623784567823657826347856237845672834657823657826387456289376587236478562347856237845678236457823645789236457896", "672386457826345237856782364576243785689723657329848923975786432785623785678293645786234875627834657823645782647582634578264879562378456728346578234657826947859627834562783462786578264578236457263478596237845627893657823965782365782369457823657829643578926") << "\"" << endl;
	for (int i = 0; i < binary.size(); i++)
	{
		if (binary[i] == 1) returnValue = this->addDecimal(returnValue, potega("2", binary.size() - i - 1));
	}
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
	returnValue.cleanZero();

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
	if (int2 < 0) int2ToFunction.ujemna = true;
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

	if (this->ujemna && !int2.ujemna)
	{
		this->ujemna = false;
		return operator+(int2);
	}
	if (!this->ujemna && int2.ujemna)
	{
		int2.ujemna = false;
		return operator+(int2);
	}

	if (this->ujemna && int2.ujemna)
	{
		this->ujemna = false;
		int2.ujemna = false;
		return int2.operator-(*this);
	}

	bool inverted = 0;

	if (*this < int2)
	{
		returnValue.ujemna = true;
		inverted = true;
	}
	else
	{
		returnValue.ujemna = false;
	}

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

	for (int i = this->binary.size() - 1; i >= 0; i--)
	{
		if (inverted)
		{
			int value = 0;
			if (int2.binary[i] == 0 && this->binary[i] == 0)
			{
				value = 0;
			}
			if (int2.binary[i] == 0 && this->binary[i] == 1)
			{
				value = 1;
				for (int j = i-1; j >= 0; j--)
				{
					if (int2.binary[j] == 1)
					{
						int2.binary[j] = 0;
						break;
					}
					else
					{
						int2.binary[j] = 1;
					}
				}
			}
			if (int2.binary[i] == 1 && this->binary[i] == 0)
			{
				value = 1;
			}
			if (int2.binary[i] == 1 && this->binary[i] == 1)
			{
				value = 0;
			}
			returnValue.binary.insert(returnValue.binary.begin(), value);
		}
		else
		{
			int value = 0;
			if (this->binary[i] == 0 && int2.binary[i] == 0)
			{
				value = 0;
			}
			if (this->binary[i] == 0 && int2.binary[i] == 1)
			{
				value = 1;
				for (int j = i - 1; j >= 0; j--)
				{
					if (this->binary[j] == 1)
					{
						this->binary[j] = 0;
						break;
					}
					else
					{
						this->binary[j] = 1;
					}
				}
			}
			if (this->binary[i] == 1 && int2.binary[i] == 0)
			{
				value = 1;
			}
			if (this->binary[i] == 1 && int2.binary[i] == 1)
			{
				value = 0;
			}
			returnValue.binary.insert(returnValue.binary.begin(), value);
		}
	}
	
	int2.cleanZero();
	this->cleanZero();
	returnValue.cleanZero();

	return returnValue;
}

void BigInt::operator-=(BigInt int2)
{
	*this = *this - int2;
}

void BigInt::operator-=(long long int int2)
{
	BigInt int2ToFunction;
	int2ToFunction.binary = intToBinary(int2);
	if (int2 < 0) int2ToFunction.ujemna = true;
	this->operator-=(int2ToFunction);
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
