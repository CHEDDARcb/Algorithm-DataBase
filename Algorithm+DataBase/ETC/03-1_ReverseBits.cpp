#include <iostream>

using namespace std;

string input;

int main(void)
{
	cin >> input;

	int result = 0;
	int b = 2;
	for (int i = 1; i < input.size(); ++i)
	{
		result += (input[i] - '0') * b;
		b *= 2;
	}

	if (input[0] - '0' == 1)
		result += 1;

	cout << result;

	return 0;
}
