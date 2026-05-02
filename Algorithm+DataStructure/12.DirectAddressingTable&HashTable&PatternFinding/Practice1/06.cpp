#include <iostream>

using namespace std;

void Counting(const char _base[], const size_t _baseSize, int _bucket[])
{
	for (size_t i = 0; i < _baseSize; ++i)
	{
		int bucketIdx = static_cast<int>(_base[i]);
		++_bucket[bucketIdx];
	}
}

int main()
{
	const char base[5][3] =
	{
		{'A', 'B', 'C'},
		{'A', 'G', 'H'},
		{'H', 'I', 'J'},
		{'K', 'A', 'B'},
		{'A', 'B', 'C'},
	};
	int bucket[256]{};

	for (int i = 0; i < 5; ++i)
	{
		Counting(base[i], sizeof(base[i]) / sizeof(char), bucket);
	}

	for (int i = 'A'; i <= 'Z'; ++i)
	{
		for (int j = 0; j < bucket[i]; ++j)
		{
			cout << static_cast<char>(i);
		}
	}

	return 0;
}