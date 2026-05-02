#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<char, int, greater<char>> m;
string cards;

void Input()
{
	cin >> cards;

	for (int i = 0; i < cards.size(); ++i)
	{
		char c = cards[i];

		map<char, int>::iterator result = m.find(c);
		if (result == m.end())
			m.insert({ c, 1 });
		else
			(*result).second += 1;
	}
}

char Solution()
{
	int max = INT_MIN;
	char result;
	int n;
	cin >> n;

	for (auto& data : m)
	{
		int choose;
		if (n < data.second)
		{
			choose = n;
		}
		else
		{
			choose = data.second;
		}

		if (max <= choose)
		{
			max = choose;
			result = data.first;
		}
		n -= choose;

		if (n <= 0) break;
	}

	return result;
}

int main(void)
{
	Input();
	char result = Solution();

	cout << result;
	return 0;
}