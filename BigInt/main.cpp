#include <iostream>
#include <time.h>
#include <math.h>

#include "BigInt.hpp"

using namespace std;

int main()
{

	

	BigInt bignumber[3];

	bignumber[0] = 232478923748;
	bignumber[1] = 232478923755;

	cout << "Binary: ";
	
	for (int i = 0; i < bignumber[0].binary.size(); i++)
	{
		cout << bignumber[0].binary[i];
	}

	cout << "\nBinary: ";
	bignumber[0] = ~bignumber[0];	

	cout << bignumber[0].toBinary() << endl;

	//cout << "Binary: ";
	bignumber[0] = ~bignumber[0];
	

	cout << "0: " << bignumber[0].toBinary() << endl;
	cout << "1: " << bignumber[1].toBinary() << endl;

	bignumber[0] = bignumber[0] | bignumber[1];
	cout << "|: " << bignumber[0].toBinary() << endl;

	bignumber[0] = 232478923748;

	cout << endl;

	cout << "0: " << bignumber[0].toBinary() << endl;
	cout << "1: " << bignumber[1].toBinary() << endl;

	bignumber[0] &= bignumber[1];
	cout << "&: " << bignumber[0].toBinary() << endl;


	bignumber[0] = 232478923748;
	cout << endl;


	cout << "0: " << bignumber[0].toBinary() << endl;
	cout << "1: " << bignumber[1].toBinary() << endl;

	bignumber[0] ^= bignumber[1];
	cout << "^: " << bignumber[0].toBinary() << endl;

	bignumber[0] = 232478923748;
	cout << endl;

	cout << "0: " << bignumber[0].toBinary() << endl;
	cout << "1: " << bignumber[1].toBinary() << endl;

	bignumber[0] >>= 5;
	cout << ">> " << bignumber[0].toBinary() << endl;

	cout << "\nDecimal: " << bignumber[0] << endl;
	system("PAUSE");
}