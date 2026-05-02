#include <iostream>

using namespace std;

bool base[5][5]{};

int main(void)
{
	bool isDup = false;
	for (int i = 0; i < 6; ++i)
	{
		int y, x;
		cin >> y >> x;

		if (base[y][x])
		{
			isDup = true;
			break;
		}
		else
		{
			base[y][x] = true;
		}
	}

	if (isDup)
		cout << "중복된좌표발견" << endl;
	else
		cout << "중복없음" << endl;
	return 0;
}