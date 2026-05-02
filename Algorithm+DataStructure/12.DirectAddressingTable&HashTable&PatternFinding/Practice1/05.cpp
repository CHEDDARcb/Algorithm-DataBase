#include <iostream>

using namespace std;

int FindBlackList(const char _town[], const size_t _townSize,
	const char _blackList[], const size_t _listSize)
{
	int count = 0;
	for (int i = 0; i < _listSize; ++i)
	{
		for (size_t j = 0; j < _townSize; ++j)
		{
			if (_town[j] == _blackList[i])
				++count;
		}
	}

	return count;
}

int main()
{
	char town[3][3] =
	{
		{'C','D', 'A'},
		{'B','M', 'Z'},
		{'Q','P', 'O'}
	};
	char blackList[4];

	for (auto& data : blackList)
		cin >> data;

	int listCount[256]{};
	int townHeight = sizeof(town) / sizeof(town[0]);
	int listSize = sizeof(blackList) / sizeof(char);
	int result = 0;
	for (int i = 0; i < townHeight; ++i)
	{
		int townWidth = sizeof(town[i]) / sizeof(char);
		result += FindBlackList(town[i], townWidth, blackList, listSize);
	}

	cout << result;

	return 0;
}