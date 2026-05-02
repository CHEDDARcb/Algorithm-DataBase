#include<iostream>

using namespace std;

int Counting(const int _level[], const size_t _levSize, const int _fruitCal[], const size_t _fCsize)
{
	int result = 0;
	for (int i = 0; i < _fCsize; ++i)
	{
		int levCount = 0;
		for (int j = 0; j < _levSize; ++j)
		{
			if (j)
			{
				if (_fruitCal[i] <= _level[j])
					++levCount;
			}
			else
			{
				if (_fruitCal[i] >= _level[j])
					++levCount;
			}
		}
		if (levCount == _levSize)
			++result;
	}

	return result;
}

int main()
{
	int levelTable[4][2] =
	{
		{10, 20},
		{30, 60},
		{100, 150},
		{200, 300}
	};
	int fruitCal[6];

	for (auto& data : fruitCal)
		cin >> data;

	for (int i = 0; i < 4; ++i)
	{
		cout << "lev" << i << ":" <<
			Counting(levelTable[i], sizeof(levelTable[i]) / sizeof(int),
				fruitCal, sizeof(fruitCal) / sizeof(int)) << endl;
	}

	return 0;
}