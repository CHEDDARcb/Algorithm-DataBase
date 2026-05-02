#include <iostream>

using namespace std;

int main(void)
{
	char strs[4][6];

	for (int i = 0; i < 4; ++i)
		cin >> strs[i];

	bool aCheck = false;
	bool bCheck = false;

	for (int i = 0; i < 4; ++i)
	{
		if (aCheck && bCheck) break;

		int j = 0;
		while (strs[i][j] != '\0')
		{
			if (strs[i][j] == 'A')
				aCheck = true;
			else if (strs[i][j] == 'B')
				bCheck = true;

			j++;
		}
	}

	if (aCheck && bCheck)
		cout << "대발견";
	else if (aCheck || bCheck)
		cout << "중발견";
	else
		cout << "미발견";

	return 0;
}