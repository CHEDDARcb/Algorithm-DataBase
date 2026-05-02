#include <iostream>

using namespace std;

int main()
{
	char base[2][3]
	{
		{'G', 'K', 'G'}
	};

	for (int i = 0; i < 3; ++i)
		cin >> base[1][i];

	int bucket[256]{};
	bool isOverThree = false;
	for (const auto& row : base)
	{
		for (const auto& data : row)
		{
			int idx = static_cast<int>(data);
			++bucket[idx];

			if (bucket[idx] >= 3)
			{
				isOverThree = true;
			}
		}
	}

	if (isOverThree)
		cout << "있음";
	else
		cout << "없음";
	return 0;
}