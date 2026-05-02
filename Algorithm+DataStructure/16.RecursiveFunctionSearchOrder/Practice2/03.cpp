#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char base[3][3][3];
	char input;

	cin >> input;

	for (auto& arr : base)
	{
		for (auto& row : arr)
		{
			for (auto& data : row)
			{
				data = input;
			}
		}
		++input;
	}

	for (const auto& arr : base)
	{
		for (const auto& row : arr)
		{
			for (const auto& data : row)
			{
				cout << data;
			}
			cout << endl;
		}
	}

	return 0;
}
