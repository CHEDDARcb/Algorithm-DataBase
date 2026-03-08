#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<string> books;

void Input()
{
	int n;
	cin >> n;

	while (n--)
	{
		string str;
		cin >> str;

		books.push_back(str);
	}
}

void Sort()
{
	// Bubble
	for (int i = 0; i < books.size() - 1; ++i)
	{
		for (int j = 0; j < books.size() - 1 - i; ++j)
		{
			if (books[j] > books[j + 1])
			{
				string tmp = books[j];
				books[j] = books[j + 1];
				books[j + 1] = tmp;
			}
		}
	}
}

bool BinarySearch(int start, int end, string target, int timer)
{
	if (start > end || timer <= 0)
		return false;

	int mid = ceil((start + end) / 2.0);
	if (books[mid] == target)
		return true;
	else if (books[mid] > target)
		return BinarySearch(start, mid - 1, target, timer - 1);
	else
		return BinarySearch(mid + 1, end, target, timer - 1);
}

void Find()
{
	int m;
	cin >> m;

	while (m--)
	{
		string target;
		int timer;

		cin >> target;
		cin >> timer;

		bool result = BinarySearch(0, books.size() - 1, target, timer);

		cout << (result ? "pass" : "fail") << endl;
	}
}
int main(void)
{
	Input();

	Sort();

	Find();

	return 0;
}