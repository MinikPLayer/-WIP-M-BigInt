#include <iostream>

#include "BigInt.hpp"

using namespace std;

int main()
{
	BigInt bignumber[3];

	bignumber[0] = 125;
	bignumber[1] = 95;
	bignumber[2] = 5;
	//bignumber[4] = 125;

	cout << "0: " << bignumber[0] <<  endl;

	//bignumber[0] += bignumber[1] + 15 + 5;

	bignumber[0] += 15;
	//bignumber[3] = bignumber[0] + bignumber[1];
	cout << bignumber[0] + bignumber[1] << endl;

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