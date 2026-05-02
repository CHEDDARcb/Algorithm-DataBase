#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> names;

int main(void)
{
	cin >> n;

	names.resize(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> names[i];
	}

	for (int i = 0; i < names.size() - 1; ++i)
	{
		for (int j = 0; j < names.size() - i - 1; ++j)
		{
			if (names[j].size() == names[j + 1].size())
			{
				if (names[j] > names[j + 1])
				{
					string tmp = names[j];
					names[j] = names[j + 1];
					names[j + 1] = tmp;
				}
			}
			else
			{
				if (names[j].size() > names[j + 1].size())
				{
					string tmp = names[j];
					names[j] = names[j + 1];
					names[j + 1] = tmp;
				}
			}
		}
	}

	for (auto& name : names)
		cout << name << endl;
}