#include <iostream>

using namespace std;

int main(void)
{
	int arr[7] = { 4, 2, 5, 1, 6, 7, 3 };
	char s, e;

	cin >> s >> e;

	if (s > e)
	{
		char tmp = s;
		s = e;
		e = tmp;
	}

	int dist = 0;
	for (int i = s - 'A' + 1; i < e - 'A'; ++i)
		dist += arr[i];

	cout << dist;

	return 0;
}