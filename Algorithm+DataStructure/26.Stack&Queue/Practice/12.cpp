#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<char> q;

	q.push('B');
	q.push('I');
	q.push('A');
	q.push('H');

	int count = q.size();
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
	}

	return 0;
}