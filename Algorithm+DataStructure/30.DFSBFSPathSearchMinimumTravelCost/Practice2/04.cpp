#include <iostream>
#include <vector>

using namespace std;

vector<string> binas;

void Input()
{
	for (int i = 0; i < 3; ++i)
	{
		cin >> binas[i];
	}
}

int CalcuBinary(const string& str)
{
	int result = 0;
	int pow = 1;
	for (int i = str.size() - 1; i >= 0; --i)
	{
		result += pow * str[i];
		pow *= 2;
	}

	return result;
}

int SelectMax()
{
	int max = INT_MIN;
	int maxIdx = -1;
	for (int i = 0; i < binas.size(); ++i)
	{
		int tmp = CalcuBinary(binas[i]);
		if (max < tmp)
		{
			max = tmp;
			maxIdx = i;
		}
	}

	return maxIdx;
}

int main()
{
	binas.resize(3);

	Input();

	int result = SelectMax();

	cout << binas[result];

	return 0;
}