#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_CH = 100000;
vector<int> pushed(MAX_CH, false);
int minClick = INT_MAX;
queue<pair<int, int>> que;

int s, e;

void Pushing(int chan, int click)
{
	if (chan < 0 || chan >= MAX_CH)
		return;
	
	if (pushed[chan])
		return;

	pushed[chan] = true;
	que.push({ chan, click + 1 });
}

int Switching(int start, int end)
{
	que.push({ start, 0 });
	pushed[start - start] = true;

	while (!que.empty())
	{
		pair<int, int> cur = que.front();
		que.pop();

		if (cur.first == end)
			return cur.second;

		int nxtChan;
		// /2
		nxtChan = cur.first / 2;
		Pushing(nxtChan, cur.second);

		nxtChan = cur.first * 2;
		Pushing(nxtChan, cur.second);

		nxtChan = cur.first + 1;
		Pushing(nxtChan, cur.second);

		nxtChan = cur.first - 1;
		Pushing(nxtChan, cur.second);	
	}

	return -1;
}

int main(void)
{
	cin >> s >> e;

	minClick = Switching(s, e);

	cout << minClick;

	return 0;
}