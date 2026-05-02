#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> bottles(5);
int st1, st2;

void Input()
{
	for (int i = 0; i < 5; ++i)
	{
		string tmp;
		cin >> tmp;

		for (int j = 0; j < tmp.size(); ++j)
		{
			bottles[i].push_back(int(tmp[j] - '0'));
		}
	}

	cin >> st1 >> st2;
}

void InsertSort(int idx)
{
	for (int i = 1; i < bottles[idx].size(); ++i)
	{
		int min = bottles[idx][i];
		int j = i - 1;
		for (; j >= 0 && bottles[idx][j] > min; --j)
		{
			bottles[idx][j + 1] = bottles[idx][j];
		}
		bottles[idx][j + 1] = min;
	}
}

void Sort()
{
	InsertSort(st1);
	InsertSort(st2);
}

int main(void)
{
	Input();

	Sort();

	for (int i = 0; i < bottles.size(); ++i)
	{
		cout << bottles[i][0] << " ";
	}
	return 0;
}