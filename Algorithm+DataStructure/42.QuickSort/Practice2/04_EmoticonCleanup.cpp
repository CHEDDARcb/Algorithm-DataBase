#include <iostream>

using namespace std;

int main(void)
{
	string result;

	string input;
	cin >> input;

	int ridx = -1;
	int i = 0;
	int cnt = 0;
	while (i < input.size())
	{
		char cur = input[i];

		if (cur == '^')
			++cnt;
		else
			cnt = 0;

		result.push_back(cur);
		++i;
		++ridx;

		if (result[ridx] == '(')
		{
			while (i < input.size() && input[i] == '(')
				++i;
		}
		else if (result[ridx] == ')')
		{
			while (i < input.size() && input[i] == ')')
				++i;
		}
		else if (result[ridx] == '^')
		{
			int prev = ridx - 2;
			if (prev >= 0 && result[prev] == '^')
				result[prev + 1] = '_';

			if(cnt == 2)
			{
				while (i < input.size() && input[i] == '^')
					++i;
			}
		}
	}

	cout << result;

	return 0;
}