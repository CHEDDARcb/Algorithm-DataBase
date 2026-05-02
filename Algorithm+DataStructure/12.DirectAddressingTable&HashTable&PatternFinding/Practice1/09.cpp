#include <iostream>

using namespace std;

void Counting(const int _base[], const size_t _bSize, int _bucket[])
{
	for (size_t i = 0; i < _bSize; ++i)
	{
		++_bucket[_base[i]];
	}
}

int main()
{
	const int base[3][5] =
	{
		{1, 3, 3, 5, 1},
		{3, 6, 2, 4, 2},
		{1, 9, 2, 6, 5}
	};
	int n;

	cin >> n;

	const int baseHeight = sizeof(base) / sizeof(base[0]);
	const int baseWidth = sizeof(base[0]) / sizeof(int);
	int bucket[baseHeight * baseWidth + 1]{};

	for (int i = 0; i < baseHeight; ++i)
	{
		Counting(base[i], baseWidth, bucket);
	}

	for (int i = 1; i <= baseHeight * baseWidth; ++i)
	{
		if (bucket[i] == n)
			cout << i << " ";
	}

	return 0;
}