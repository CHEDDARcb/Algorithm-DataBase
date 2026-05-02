#include <iostream>

using namespace std;

int main(void)
{
	char sNames[7] = { 'A', 'B', 'C', 'Z', 'E', 'T', 'Q' };
	char bLst[5];

	for (auto& b : bLst)
		cin >> b;

	for (const auto& b : bLst)
	{
		cout << b << "=";

		bool isIn = false;
		for (const auto& sName : sNames)
		{
			if (sName == b)
			{
				cout << "마을사람" << endl;
				isIn = true;
				break;
			}
		}
		if (!isIn)
			cout << "외부사람" << endl;
	}

	return 0;
}