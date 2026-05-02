#include <iostream> 
#include <vector>

using namespace std;

int n;
vector<string> strs;

void Input()
{
	cin >> n;
	strs.resize(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> strs[i];
	}
}

int main()
{
	Input();

	int cnt = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			string tmp = strs[i] + strs[j];
			if (tmp == "HITSMUSIC")
				cnt++;
		}
	}

	cout << cnt;

	return 0;
}