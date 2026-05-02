#include <iostream>
#include <vector>
using namespace std;

vector<int> map(5);

void InitMap()
{
	int idx;
	int life;

	cin >> idx >> life;

	map[idx] = life;
}

void PrintMap()
{
	for (const auto& data : map)
	{
		if (data)
			cout << data;
		else
			cout << "_";
	}
	cout << endl;
}

bool Cycle()
{
	int zeroCount = 0;

	PrintMap();

	for (int i = map.size() - 1; i >= 0; --i)
	{
		if (map[i])
		{
			if (i == map.size() - 1)
			{
				map[i] = 0;
				++zeroCount;
			}
			else
			{
				if (map[i] == 1)
				{
					map[i] = 0;
					++zeroCount;
				}
				else
				{
					map[i + 1] = map[i] - 1;
					map[i] = 0;
				}
			}
		}
		else
			++zeroCount;
	}

	if (zeroCount == map.size())
	{
		PrintMap();
		return false;
	}
	else
		return true;

}

int main()
{
	InitMap();

	while (Cycle());

	return 0;
}