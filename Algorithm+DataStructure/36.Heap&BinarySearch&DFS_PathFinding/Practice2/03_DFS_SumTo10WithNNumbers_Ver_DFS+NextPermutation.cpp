#include <iostream>
#include <vector>

using namespace std;

const int target = 10;
vector<int> dt = { 1,2,3,4,5,6,7,8,9 };
int n;
int cnt = 0;
string path;
bool conditionLev[3];


bool NextPermutation(string& path)
{
	int i = path.size() - 1;
	while (i > 0 && path[i - 1] >= path[i])
		i -= 1;
	if (i <= 0)
		return false;

	int a = i - 1;

	int j = path.size() - 1;
	while (path[j] <= path[a])
		j -= 1;

	int b = j;

	int tmp = path[a];
	path[a] = path[b];
	path[b] = tmp;

	int f = a + 1;
	int l = path.size() - 1;
	while(f < l)
	{
		tmp = path[f];
		path[f] = path[l];
		path[l] = tmp;
		f += 1;
		l -= 1;
	}

	return true;
}

bool DFS(int curIdx, int curLev, int sum)
{
	if (curLev == n)
	{
		if (sum >= target)
		{
			if (sum == target)
			{
				string tmp = path;
				while(true)
				{
					++cnt;
					for (int i = 0; i < tmp.size(); ++i)
					{
						cout << tmp[i];
					}
					cout << endl;

					bool isNext = NextPermutation(tmp);
					if (!isNext)
						break;
				}
			}
			return false;
		}
		return true;
	}

	for (int i = curIdx; i < dt.size(); ++i)
	{
		if (target - (sum + dt[i]) < dt[i])
			break;

		path.push_back(dt[i] + '0');
		bool isContinue = DFS(i, curLev + 1, sum + dt[i]);
		path.pop_back();

		if (!isContinue)
			break;
	}

	return true;
}

int main(void)
{
	cin >> n;

	DFS(0, 0, 0);

	cout << cnt;
}
