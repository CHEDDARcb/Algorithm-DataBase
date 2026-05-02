#include <iostream>

using namespace std;

int main()
{
	char input[11];
	cin >> input;

	int bucket[256]{};
	int max = INT_MIN;
	int mIdx = -1;
	for (int i = 0; input[i] != '\0'; ++i)
	{
		int idx = static_cast<int>(input[i]);
		++bucket[idx];
		if (max < bucket[idx])
		{
			max = bucket[idx];
			mIdx = idx;
		}
	}

	cout << static_cast<char>(mIdx);
	return 0;
}