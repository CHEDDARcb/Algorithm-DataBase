#include <iostream>
#include <string>

using namespace std;

const string MIN = "-2147483648";
const string MAX = "2147483647";
const int MINLEN = 11;
const int MAXLEN = 10;

int main(void)
{
	string input;

	cin >> input;

	if (input[0] == '-')
	{
		if (input.length() > MINLEN)
		{
			cout << 0;
			return 0;
		}
		else if (input.length() == MINLEN)
		{
			for (int i = 1; i < MINLEN; ++i)
			{
				if (input[i] > MIN[i])
				{
					cout << 0;
					return 0;
				}
			}
		}
	}
	else
	{
		if (input.length() > MAXLEN)
		{
			cout << 0;
			return 0;
		}
		else if (input.length() == MAXLEN)
		{
			for (int i = 0; i < MAXLEN; ++i)
			{
				if (input[i] > MAX[i])
				{
					cout << 0;
					return 0;
				}
			}
		}
	}

	int target = stoi(input);

	if (target < 0)
	{
		if (target <= INT_MIN)
		{
			cout << 0;
			return 0;
		}
		else
		{
			target *= -1;
		}
	}

	bool isOk = true;
	int result = 0;
	while (target > 0)
	{
		int digit = target % 10;
		target /= 10;

		if (result > INT_MAX / 10 ||
			(result == INT_MAX / 10 && digit > 7))
		{
			isOk = false;
			break;
		}

		result = result * 10 + digit;

		if (result < INT_MIN || result > INT_MAX)
		{
			isOk = false;
			break;
		}
	}

	if (isOk) cout << result;
	else cout << 0;

	return 0;
}