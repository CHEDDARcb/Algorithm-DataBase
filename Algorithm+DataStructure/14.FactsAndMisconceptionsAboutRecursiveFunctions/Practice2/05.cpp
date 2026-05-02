#include <iostream>

using namespace std;

void PrintAlpha(int alpha, int end)
{
	if (alpha > 'Z')
		alpha = 'A';

	cout << static_cast<char>(alpha);

	if (alpha == end)
		return;

	PrintAlpha(alpha + 1, end);
}

int main()
{
	char ch;

	cin >> ch;

	int end = static_cast<int>(ch) + 3;
	int start = static_cast<int>(ch) - 3;

	if (start < 65)
		start = 'Z' - ('A' - start - 1);
	if (end > 90)
		end = 'A' + (end - 'Z' - 1);

	PrintAlpha(start, end);


	return 0;
}