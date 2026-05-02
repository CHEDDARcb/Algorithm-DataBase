#include <iostream>

using namespace std;

void FindABC(const char str[], int* aCnt, int* bCnt, int* cCnt)
{
	int stridx = 0;
	while (str[stridx] != '\0')
	{
		if (str[stridx] == 'A')
		{
			++*aCnt;
		}
		else if (str[stridx] == 'B')
		{
			++*bCnt;
		}
		else if (str[stridx] == 'C')
		{
			++*cCnt;
		}

		stridx++;
	}
}

int main(void)
{
	char strs[2][100];

	cin >> strs[0] >> strs[1];

	int aN = 0, bN = 0, cN = 0;
	FindABC(strs[0], &aN, &bN, &cN);
	FindABC(strs[1], &aN, &bN, &cN);

	cout << "A: " << aN << endl;
	cout << "B: " << bN << endl;
	cout << "C: " << cN << endl;

	return 0;
}