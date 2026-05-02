#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int base[3][2][3];
	int a, b;

	cin >> a >> b;

	bool rowflag = false;
	for (auto& arr : base)
	{
		for (auto& row : arr)
		{
			for (auto& data : row)
			{
				if (!rowflag) data = a;
				else data = b;
			}
			rowflag = true;
		}
		rowflag = false;
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