#include <iostream>

using namespace std;

struct RESULT
{
	char r1;
	char r2;
};

char arr[3][3] =
{
	{'D', 'A', 'S'},
	{'Q', 'W', 'V'},
	{'R', 'T', 'Y'}
};

const RESULT Find(char x1, char y1, char x2, char y2)
{
	RESULT r;

	r.r1 = arr[y1][x1];
	r.r2 = arr[y2][x2];

	return r;
}
int main(void)
{
	int x1, y1;
	int x2, y2;

	cin >> y1 >> x1;
	cin >> y2 >> x2;

	RESULT result = Find(x1, y1, x2, y2);

	cout << result.r1 << " " << result.r2;

	return 0;
}