#include <iostream>
#include <vector>

using namespace std;

vector<int> name = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
vector<int> path;
int n;
int cnt = 0;

bool DFS(int sum, int curLev)
{
	if (curLev == n)
	{
		if (sum >= 10)
		{
			if (sum == 10)
			{
				cnt++;
				for (int i = 0; i < path.size(); ++i)
				{
					cout << path[i] << " ";
				}
				cout << endl;
			}
			return false;
		}
		else
			return true;
	}

	for (int i = 0; i < name.size(); ++i)
	{
		path.push_back(name[i]);
		bool isContinue = DFS(sum + name[i], curLev + 1);
		path.pop_back();
		if (!isContinue)
			break;
	}

	return true;
}

int main(void)
{
	cin >> n;

	DFS(0, 0);

	cout << cnt;
}