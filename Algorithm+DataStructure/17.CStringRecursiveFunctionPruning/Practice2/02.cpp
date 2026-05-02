#include <iostream>
#include <cmath>

using namespace std;

int killerPos[3][2];

bool CheckRange(int kilIdx)
{
	for (int i = kilIdx + 1; i < 3; ++i)
	{
		if (killerPos[kilIdx][0] == killerPos[i][0] ||
			killerPos[kilIdx][1] == killerPos[i][1])
			return true;
	}

	return false;
}

int main(void)
{
	for (auto& kPos : killerPos)
		cin >> kPos[0] >> kPos[1];

	bool isSafe = true;;
	for (int i = 0; i < 2; ++i)
	{
		if (CheckRange(i))
		{
			isSafe = false;
			break;
		}
	}

	if (isSafe)
		cout << "안전";
	else
		cout << "위험";

	return 0;
}