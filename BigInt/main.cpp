#include <iostream>
#include <time.h>
#include <math.h>

#include "BigInt.hpp"

using namespace std;

int main()
{
	BigInt bignumber[4];

	bignumber[0] = 232478923748;
	bignumber[1] = 232478923755;
	bignumber[2] = 12389123;

	string divValue = "31846781263478126347861254612346123578";
	BigInt moduloNumber;
	moduloNumber = 126;

	//cout << "Na stringach: " << bignumber[0].multipleDecimal(bignumber[0].divideStringByTwo(divValue), "2") << endl;
	

	//cout << "Dividing string by 2, " << divValue << " / 2 = " << bignumber[0].divideStringByTwo(divValue) << endl;
	
	bignumber[0] = divValue;

	//cout << "DivValue: " << divValue << " bignumber: " << bignumber[0] << endl;

	//cout << divValue << " % " << moduloNumber << " = " << bignumber[0] % moduloNumber << endl;
	//cout << divValue << " / " << moduloNumber << " = " << bignumber[0] / moduloNumber * moduloNumber << endl;

	//cout << "Binary: " << bignumber[0].toBinary() << endl;
	
	cout << "Before: " << bignumber[0]++ << endl;
	cout << "After : " << ++bignumber[0] << endl;

	system("PAUSE");

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