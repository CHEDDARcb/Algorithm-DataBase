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

void Sort()
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i; j < n - 1 - i; ++j)
		{
			if (strs[j].length() > strs[j + 1].length())
			{
				string tmp = strs[j];
				strs[j] = strs[j + 1];
				strs[j + 1] = tmp;
			}
			else if (strs[j].length() == strs[j + 1].length())
			{
				if (strs[j] > strs[j + 1])
				{
					string tmp = strs[j];
					strs[j] = strs[j + 1];
					strs[j + 1] = tmp;
				}
			}
		}
	}
}


int main()
{
	Input();

	Sort();

	for (auto& data : strs)
		cout << data << endl;

	return 0;
}