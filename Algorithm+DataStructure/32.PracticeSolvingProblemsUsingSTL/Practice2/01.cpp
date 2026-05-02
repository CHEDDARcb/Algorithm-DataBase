#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> strs =
{
	"ABCD",
	"ABCE",
	"AGEH",
	"EIEI",
	"FEQE",
	"ABAD"
};
string target;
vector<int> trgtIdx;

void Input()
{
	cin >> target;

	for (int i = 0; i < target.size(); ++i)
	{
		if (target[i] >= 'A' && target[i] <= 'Z')
			trgtIdx.push_back(i);
	}
}

int Searching()
{
	int result = 0;
	for (int i = 0; i < strs.size(); ++i)
	{
		int cnt = trgtIdx.size();
		for (int j = 0; j < trgtIdx.size(); ++j)
		{
			int idx = trgtIdx[j];
			if (strs[i][idx] == target[idx])
				--cnt;
		}
		if (cnt == 0)
			++result;
	}

	return result;
}

int main(void)
{
	Input();
	cout << Searching();
	return 0;
}