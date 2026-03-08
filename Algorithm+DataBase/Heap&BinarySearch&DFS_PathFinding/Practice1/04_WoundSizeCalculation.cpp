#include <iostream>
#include <vector>

using namespace std;

vector<string> wound;

void Input()
{
	bool push = true;
	while (push)
	{
		string input;
		cin >> input;

		string tmp;
		if (input[input.size() - 1] != ',')
		{
			push = false;
			for (int i = 1; i < input.size() - 1; ++i)
			{
				tmp.push_back(input[i]);
			}
		}
		else
		{
			for (int i = 1; i < input.size() - 2; ++i)
			{
				tmp.push_back(input[i]);
			}
		}
		wound.push_back(tmp);

	}
}

int GetWoundStartIdx(int start, int end, const string& wound)
{
	int s = start;
	int e = end;
	while (s < e)
	{
		int m = (s + e) / 2;
		if (wound[m] == '*')
			e = m;
		else
			s = m + 1;
	}

	return s;
}

int GetWoundEndIdx(int start, int end, const string& wound)
{
	int s = start;
	int e = end;
	while (s < e)
	{
		int m = (s + e + 1) / 2;
		if (wound[m] == '*')
			s = m;
		else
			e = m - 1;
	}

	return e;
}

void CalCulWoundSize()
{
	for (int i = 0; i < wound.size(); ++i)
	{
		const string& curWound = wound[i];

		int start = 0;
		int end = wound[i].size() - 1;
		int mid = (start + end) / 2;

		int woundStart = GetWoundStartIdx(start, mid, wound[i]);
		int woundEnd = GetWoundEndIdx(mid, end, wound[i]);
		int woundSize = woundEnd - woundStart + 1;

		cout << woundSize << endl;
	}
}

int main(void)
{
	Input();

	CalCulWoundSize();

	return 0;
}