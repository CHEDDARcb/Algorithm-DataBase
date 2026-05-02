#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string input;
	int stack = 0;

	cin >> input;

	for (int i = 0; i < input.size(); ++i)
	{
		if (stack == 0 && input[i] == '>')
		{
			stack -= 1;
			break;
		}

		if (input[i] == '<') stack++;
		else if (input[i] == '>') stack--;
	}

	cout << (stack ? "비정상" : "정상");

	return 0;
}