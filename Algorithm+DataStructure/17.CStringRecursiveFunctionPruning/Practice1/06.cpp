#include <iostream>
#include <cmath>

using namespace std;

int cards[5];
int path[4]{ -1, -1, -1, -1 };
int result = 0;

bool Condition(int idx, int level)
{
	if (level >= 1)
	{
		int curNum = cards[idx];
		int prevNum = path[level - 1];

		int diff = abs(curNum - prevNum);

		return diff > 3 ? true : false;
	}

	return false;
}

void CardPermutation(int level)
{
	if (level == 4)
	{
		for (const auto& data : path) cout << data;
		cout << endl;
		result++;
		return;
	}

	for (int i = 0; i < 5; ++i)
	{
		if (Condition(i, level))
			continue;

		path[level] = cards[i];

		CardPermutation(level + 1);

		path[level] = -1;
	}
}

int main(void)
{
	for (auto& data : cards)
		cin >> data;

	CardPermutation(0);

	cout << result;

	return 0;
}