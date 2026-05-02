#include <iostream>

using namespace std;

int main()
{
	char base[256];
	int bucket[256]{};
	cin >> base;

	int max = INT_MIN;
	int maxIdx = -1;
	for (int i = 0; base[i] != '\0'; ++i)
	{
		int idx = static_cast<int>(base[i]);
		++bucket[idx];

		if (max < bucket[idx])
		{
			max = bucket[idx];
			maxIdx = idx;
		}
	}

	cout << static_cast<char>(maxIdx);


	return 0;
}