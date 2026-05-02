#include <iostream>
#include <map>
using namespace std;

string input;
map<char, int> romanNum;

void Init()
{
	romanNum.insert({ 'I', 1 });
	romanNum.insert({ 'V', 5 });
	romanNum.insert({ 'X', 10 });
	romanNum.insert({ 'L', 50 });
	romanNum.insert({ 'C', 100 });
	romanNum.insert({ 'D', 500 });
	romanNum.insert({ 'M', 1000 });
}


int main(void)
{
	Init();

	cin >> input;

	int result = 0;
	for (int i = 0; i < input.length(); ++i)
	{
		int cur = romanNum[input[i]];
		if (i + 1 < input.length())
		{
			int nxt = romanNum[input[i + 1]];
			if (cur < nxt)
			{
				cur = nxt - cur;
				++i;
			}
		}

		result += cur;
	}

	cout << result;
}