#include <iostream>
#include <vector>

using namespace std;

int vect[5] = { 6, 1, 3, 8, 5 };
int result[5];

void run(int start, int end)
{
	int mid = (start + end) / 2;

	if (start >= end) return;

	run(start, mid);
	run(mid + 1, end);

	int a = start;
	int b = mid + 1;

	int t = 0;

	while (1)
	{
		if (a > mid && b > end) break;

		if (a > mid)
			result[t++] = vect[b++];
		else if (b > end)
			result[t++] = vect[a++];
		else if (vect[a] <= vect[b])
			result[t++] = vect[a++];
		else
			result[t++] = vect[b++];
	}

	for (int i = 0; i < t; ++i)
	{
		vect[start + i] = result[i];
	}
}

int main(void)
{
	run(0, 4);

	for (int num : vect)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}