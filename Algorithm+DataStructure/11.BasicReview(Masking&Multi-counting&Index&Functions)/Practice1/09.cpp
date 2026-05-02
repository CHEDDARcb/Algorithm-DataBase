#include<iostream>

using namespace std;

bool isExist(const int base[], const int target)
{
	for (int i = 0; i < 6; ++i)
		if (base[i] == target)
			return true;
	return false;
}

int main()
{
	int arr[6] = { 3, 7, 4, 1, 2, 6 };
	int univer[2][2];

	for (auto& row : univer)
	{
		for (auto& data : row)
			cin >> data;
	}

	for (const auto& row : univer)
	{
		for (const auto& data : row)
		{
			if (isExist(arr, data))
				cout << "OK ";
			else
				cout << "NO ";
		}
		cout << endl;
	}

	return 0;
}