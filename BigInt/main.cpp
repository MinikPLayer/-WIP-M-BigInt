#include <iostream>
#include <time.h>
#include <math.h>

#include "BigInt.hpp"

using namespace std;

int main()
{
	BigInt bignumber[3];

	bignumber[0] = 132478923748;
	bignumber[1] = 12312312;

	bignumber[1] *= 1237891273;
	bignumber[1] *= 1238901283;

	cout << "BigNumber[1]: " <<  bignumber[1] << endl;

	//bignumber[2] = 5;
	//bignumber[4] = 125;

	//bignumber[0] = bignumber[0] * bignumber[1];

	cout << bignumber[1] << " / " << bignumber[0] << " = " << bignumber[1] / bignumber[0] << endl;

	cout << "DONE" << endl;

	system("PAUSE");

	//cout << "0: " << bignumber[0] <<  endl;

	//bignumber[0] += bignumber[1] + 15 + 5;

	//bignumber[0] += 15;
	//bignumber[0] = bignumber[0] - bignumber[1];
	//bignumber[3] = bignumber[0] + bignumber[1];
	//cout << bignumber[0] + bignumber[1] << endl;
	//cout << "5 * 5 = " << bignumber[0] * 1238712637826 << endl;

	if (bignumber[0] < bignumber[1]) cout << "0 is smaller" << endl;
	if (bignumber[1] < bignumber[0]) cout << "1 is smaller" << endl;
	if (bignumber[0] > bignumber[1]) cout << "0 is bigger" << endl;
	if (bignumber[1] > bignumber[0]) cout << "1 is bigger" << endl;
	if (bignumber[0] >= bignumber[0]) cout << "0 is bigger or equal 0" << endl;
	if (bignumber[0] > bignumber[0]) cout << "0 is bigger than 0" << endl;

	cout << "Binary: ";
	
	for (int i = 0; i < bignumber[0].binary.size(); i++)
	{
		cout << bignumber[0].binary[i];
	}

	cout << "\nDecimal: " << bignumber[0] <<  endl;
	system("PAUSE");
}