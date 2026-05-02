#include <iostream>

using namespace std;

string input[5];

int main(void)
{
	for (int i = 0; i < 5; ++i)
		cin >> input[i];
	
	int cnt = 0;
	for (auto& str : input)
	{
		int start = 0;
		while (start < str.size())
		{
			int idx = str.find("MCD", start);

			if (idx == -1)
				break;

			++cnt;
			start = idx + 3;
		}
	}

	cout << cnt;

	return 0;
}