#include <iostream>
#include <vector>

using namespace std;

vector<char> input;
int n;

int BinarySearch(int start, int end)
{
	if (start > end)
		return -1;

	int mid = (start + end) / 2;

	if (input[mid] == '#' &&
		((input[mid + 1] == '0') ||
			(mid == input.size() - 1)))
		return mid;
	else if (input[mid] == '#')
		return BinarySearch(mid + 1, end);
	else if (input[mid] == '0')
		return BinarySearch(start, mid - 1);
}

int main(void)
{
	cin >> n;
	input.resize(n * n);

	for (int i = 0; i < n * n; ++i)
	{
		cin >> input[i];
	}

	int lIdx = BinarySearch(0, input.size() - 1);

	int y = lIdx / n;
	int x = lIdx % n;

	cout << y << " " << x;
}