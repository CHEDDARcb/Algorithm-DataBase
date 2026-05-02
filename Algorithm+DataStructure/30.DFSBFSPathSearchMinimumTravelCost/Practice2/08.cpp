#include <iostream>
#include <vector>

using namespace std;

vector<char> heroes = { 'B', 'I', 'A', 'H' };
vector<bool> visited(heroes.size(), false);
int th;

void Input()
{
	cin >> th;
}

int Sortie(int start)
{
	int idx = start;
	for (int k = 1; k <= th; ++k)
	{
		if (visited[idx])
			k--;
		++idx;
		if (idx >= heroes.size() && k != th)
		{
			idx = 0;
			while (visited[idx])
				++idx;
		}
	}

	--idx;
	while (visited[idx])
		++idx;

	visited[idx] = true;
	return idx;
}

int main()
{
	Input();
	int sotieH = 0;
	for (int i = 0; i < heroes.size(); ++i)
	{
		sotieH = Sortie(sotieH);
		cout << heroes[sotieH] << " ";
		while (visited[sotieH] && i != heroes.size() - 1)
		{
			sotieH++;
			if (sotieH >= heroes.size())
				sotieH = 0;
		}
	}

	return 0;
}