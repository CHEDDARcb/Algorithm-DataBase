#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> pt;
vector<bool> pushed;
struct Data
{
	int idx;
	int data;
	int lp;
	int rp;
	int lev;
};
queue<Data> que;
int n;

void PrintSpace(int n)
{
	for (int i = 0; i < n; ++i)
		cout << " ";
}

void Print()
{
	pt[1] = 1;
	que.push({ 1, 1, 1, 2, 0 });
	pushed[1] = true;
	int prevLev = -1;
	int spaceCnt = n - 1;

	cout << "[";

	Data cur = que.front();
	que.pop();

	int left = cur.idx + cur.lp;
	int right = cur.idx + cur.rp;
	pt[left] += pt[cur.idx];
	pt[right] += pt[cur.idx];

	PrintSpace(spaceCnt-1);
	spaceCnt--;
	cout << "[" << pt[1];
	que.push({ cur.idx + cur.lp, 1, cur.lp + 1, cur.rp + 1, cur.lev + 1 });
	que.push({ cur.idx + cur.rp, 1, cur.lp + 1, cur.rp + 1, cur.lev + 1 });
	while (!que.empty())
	{
		cur = que.front();
		que.pop();
		if (cur.lev != prevLev)
		{
			cout << "]," << endl;
			PrintSpace(spaceCnt--);
			cout << "[" << pt[cur.idx];
			prevLev = cur.lev;
		}
		else
		{
			cout << "," << pt[cur.idx];
		}
		left = cur.idx + cur.lp;
		right = cur.idx + cur.rp;

		if (left < pt.size())
		{
			pt[left] += pt[cur.idx];

			if (!pushed[left])
			{
				que.push({ left, pt[left], cur.lp + 1, cur.rp + 1, cur.lev + 1 });
				pushed[left] = true;
			}
		}
		if (right < pt.size())
		{
			pt[right] += pt[cur.idx];

			if (!pushed[right])
			{
				que.push({ right, pt[right], cur.lp + 1, cur.rp + 1, cur.lev + 1 });
				pushed[right] = true;
			}
		}
	}
	cout << "]]";
}

int main()
{
	cin >> n;

	pt.resize(((1 + n) * n / 2) + 1, 0);
	pushed.resize(pt.size(), false);

	Print();

}