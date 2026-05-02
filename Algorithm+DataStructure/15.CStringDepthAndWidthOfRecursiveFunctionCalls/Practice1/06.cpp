#include <iostream>

using namespace std;

int RecurCount(const int _curLev, const int _branch, const int _maxLevel)
{
	int count = 1;

	if (_curLev == _maxLevel)
		return count;

	for (int i = 0; i < _branch; ++i)
	{
		count += RecurCount(_curLev + 1, _branch, _maxLevel);
	}

	return count;

}

int main()
{
	int branch, level;

	cin >> branch >> level;

	int count = RecurCount(0, branch, level);

	cout << count;

	return 0;
}