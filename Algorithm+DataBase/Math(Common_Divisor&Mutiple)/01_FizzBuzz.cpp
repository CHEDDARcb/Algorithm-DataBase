#include <iostream>
#include <vector>

using namespace std;

vector<string> result;

int main(void)
{
	int n;
	char a = 1 + '0';
	cin >> n;

	result.resize(n + 1);

	for (int i = 1; i < result.size(); ++i)
	{
		if (i % 15 == 0)
			result[i] = "FizzBuzz";
		else if (i % 3 == 0)
			result[i] = "Fizz";
		else if (i % 5 == 0)
			result[i] = "Buzz";
		else
		{
			int n = i;
			while (n > 0)
			{
				int digit = n % 10;
				result[i].push_back(digit + '0');
				n /= 10;
			}
			reverse(result[i].begin(), result[i].end());
		}
	}

	for (int i = 1; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}

	return 0;
}