#include <iostream>
#include <vector>
using namespace std;

const vector<int> base = { 3, 1, 2, 1, 3, 2, 1, 2, 1 };

void Move(int move, int cur = 0)
{
	if (cur + move >= base.size() - 1)
	{
		cout << "도착 ";
		return;
	}

	cur += move;
	cout << base[cur] << " ";
	Move(base[cur], cur);
	cout << base[cur] << " ";
}
int main()
{
	int input;
	cin >> input;

	cout << "시작 ";
	Move(input - 1);
	cout << "시작 ";

	return 0;
}