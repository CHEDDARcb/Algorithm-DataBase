#include <iostream>

using namespace std;

bool CheckBit(const int _a[], const int _b[])
{
	for (int i = 0; i < 4; ++i)
	{
		if (_a[i] == 1)
		{
			if (_a[i] == _b[i])
				return true;
		}
	}

	return false;
}

int main()
{
	int bitA[4][4];
	int bitB[4][4];

	for (auto& row : bitA)
		for (auto& data : row)
			cin >> data;

	for (auto& row : bitB)
		for (auto& data : row)
			cin >> data;

	bool check = false;
	for (int i = 0; i < 4; ++i)
	{
		if (CheckBit(bitA[i], bitB[i]))
		{
			check = true;
			break;
		}
	}

	if (check)
		cout << "걸리다";
	else
		cout << "걸리지않는다";
	return 0;
}