#include <iostream>
#include <vector>

using namespace std;

vector<int> bt =
{ 0, 15, 7, 19, 0, 8, 17, 25, 0, 0, 0, 0, 16, 18 };

bool Find(int idx, int target, int* cnt)
{
	++(*cnt);
	if (idx >= bt.size())
		return false;

	if (bt[idx] == target)
		return true;
	else if (bt[idx] > target)
		return Find(idx * 2, target, cnt);
	else
		return Find(idx * 2 + 1, target, cnt);
}

int main(void)
{
	vector<int> targets(5, 0);

	for (int i = 0; i < targets.size(); ++i)
	{
		cin >> targets[i];
	}

	for (int i = 0; i < targets.size(); ++i)
	{
		int cnt = 0;

		cout << targets[i] << ": ";
		if (Find(1, targets[i], &cnt))
		{
			cout << cnt << "회만에 찾음" << endl;
		}
		else
			cout << "없음" << endl;
	}

	return 0;
}
