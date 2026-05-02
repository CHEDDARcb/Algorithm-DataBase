#include <iostream>

using namespace std;

int arr[7][5] =
{
	{1, 0, 0, 0, 0},
	{1, 0, 1, 0, 0},
	{1, 1, 0, 1, 0},
	{1, 0, 1, 0, 0},
	{0, 1, 0, 0, 1},
	{0, 0, 0, 1, 0},
	{1, 1, 0, 0, 0},
};

int INPUT()
{
	int input;

	cin >> input;

	return input;
}

int PROCESS(int input)
{
	int cnt = 0;

	for (int i = 0; i < 7; ++i)
	{
		if (arr[i][input])
			++cnt;
	}

	return cnt;
}

void OUTPUT(int count)
{
	cout << count;
}

int main(void)
{
	OUTPUT(PROCESS(INPUT()));

	return 0;
}
