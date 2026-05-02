#include <iostream>

using namespace std;

int CalTargetDistance(const char _base[], const size_t _bSize,
	const char _t1, const char _t2)
{
	int t1Idx = 0;
	int t2Idx = _bSize - 1;

	bool isFindT1 = false;
	bool isFindT2 = false;
	while (t1Idx <= _bSize && t2Idx >= 0)
	{
		if (!isFindT1)
		{
			if (_base[t1Idx] == _t1)
				isFindT1 = true;
			else
				++t1Idx;
		}

		if (!isFindT2)
		{
			if (_base[t2Idx] == _t2)
				isFindT2 = true;
			else
				--t2Idx;
		}

		if (isFindT1 && isFindT2)
			break;
	}

	if (isFindT1 && isFindT2)
	{
		if (t1Idx > t2Idx)
			return t1Idx - t2Idx;
		else
			return t2Idx - t1Idx;
	}
	else
	{
		return -1;
	}
}

int main()
{
	const char base[10] = "ATKPTCABC";
	char input1, input2;

	cin >> input1 >> input2;

	int result = CalTargetDistance(base, strlen(base), input1, input2);

	cout << result;

	return 0;
}