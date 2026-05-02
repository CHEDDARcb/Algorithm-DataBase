#include <iostream>

using namespace std;

bool IsPass(const int _base[], const size_t _bSize, const int target)
{
	for (size_t i = 0; i < _bSize; ++i)
	{
		if (_base[i] == target)
			return true;
	}

	return false;
}

int main()
{
	const int win[2][3] =
	{
		{3, 5, 1},
		{4, 2, 6}
	};
	int people[4];

	for (auto& data : people)
		cin >> data;

	for (int i = 0; i < 4; ++i)
	{
		cout << people[i] << "번";
		bool isPass = false;
		for (int j = 0; j < 2; ++j)
		{
			if (IsPass(win[j], sizeof(win[j]) / sizeof(int), people[i]))
			{
				isPass = true;
				break;
			}
		}

		if (isPass)
			cout << "합격" << endl;
		else
			cout << "불합격" << endl;
	}

	return 0;
}