#include <iostream>

using namespace std;

int main(void)
{
	char base[4][4];

	for (auto& row : base)
	{
		for (auto& data : row)
		{
			cin >> data;
		}
	}

	int charCnt = 0;
	for (int j = 0; j < 4; ++j)
	{
		charCnt = 0;
		for (int i = 0; i < 4; ++i)
		{
			if (base[i][j] >= 'A' && base[i][j] <= 'Z' ||
				base[i][j] >= 'a' && base[i][j] <= 'z')
				charCnt++;
		}
		cout << charCnt << " ";
	}

	return 0;
}