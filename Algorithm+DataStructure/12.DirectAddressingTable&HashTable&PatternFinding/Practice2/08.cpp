#include <iostream>

using namespace std;

int main()
{
	char strs[3][256]{};

	for (int i = 0; i < 3; ++i)
	{
		cin >> strs[i];
	}

	bool isPerfect = true;
	for (int i = 0; i < 3; ++i)
	{
		int bucket[256]{};
		for (int j = 0; strs[i][j] != '\0'; ++j)
		{
			int idx = static_cast<int>(strs[i][j]);
			if (bucket[idx])
			{
				isPerfect = false;
				break;
			}
			else
				++bucket[idx];
		}

		if (!isPerfect)
			break;
	}

	if (isPerfect)
		cout << "Perfect";
	else
		cout << "No";

	return 0;
}