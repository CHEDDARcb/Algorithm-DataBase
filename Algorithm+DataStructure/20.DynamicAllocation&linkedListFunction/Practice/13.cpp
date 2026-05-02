#include <iostream>

using namespace std;

void Sort(int* base, int len)
{
	int max;
	int mIDX = -1;
	for (int p = 0; p < len - 1; ++p)
	{
		max = base[p];
		mIDX = p;
		for (int i = p + 1; i < len; ++i)
		{
			if (max < base[i])
			{
				max = base[i];
				mIDX = i;
			}
		}

		int tmp = base[p];
		base[p] = base[mIDX];
		base[mIDX] = tmp;
	}
}

int main(void)
{
	int number[6];
	char command[6];

	for (auto& data : number)
		cin >> data;
	for (auto& data : command)
		cin >> data;

	Sort(number, 6);

	int m = 5;
	int x = 0;

	int i = 0;
	while (x <= m)
	{
		if (command[i] == 'm')
		{
			cout << number[m];
			--m;
		}
		else if (command[i] == 'x')
		{
			cout << number[x];
			++x;
		}
		++i;
	}

	return 0;
}