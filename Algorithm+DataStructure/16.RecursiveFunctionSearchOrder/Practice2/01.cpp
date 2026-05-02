#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	const char base[2][2][3] =
	{
		{'A', 'T', 'B',
		'C', 'C', 'B'},
		{'A', 'A', 'A',
		'B', 'B', 'C'}
	};
	char input;

	cin >> input;

	bool isFound = false;
	for (const auto& arr : base)
	{
		for (const auto& row : arr)
		{
			for (const auto& data : row)
				if (data == input)
					isFound = true;
		}
	}

	if (isFound)
		cout << "발견";
	else
		cout << "미발견";

	return 0;
}