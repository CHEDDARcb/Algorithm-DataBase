#include <iostream>
#include <vector>

using namespace std;

vector<int> input(5);
vector<bool> visited(5, false);
int mx = INT_MIN;
int mn = INT_MAX;
void DFS(int curLev, int comb)
{
	if (curLev == 3)
	{
		if (mx < comb)
			mx = comb;
		if (mn > comb)
			mn = comb;

		return;
	}

	comb *= 10;
	for (int i = 0; i < input.size(); ++i)
	{
		if (visited[i])
			continue;
		
		comb += input[i];
		visited[i] = true;

		DFS(curLev + 1, comb);

		visited[i] = false;
		comb -= input[i];
	}
}

int main(void)
{
	for (int i = 0; i < input.size(); ++i)
	{
		cin >> input[i];
	}

	DFS(0, 0);

	cout << "MAX:" << mx << endl;
	cout << "MIN:" << mn << endl;

	return 0;
}