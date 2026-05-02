#include <iostream>

using namespace std;

int HurtCount(const bool _up[], const bool _down[], const size_t _len)
{
	int cnt = 0;
	for (size_t i = 0; i < _len; ++i)
	{
		if (_up[i] && _down[i])
			++cnt;
	}

	return cnt;
}
int main()
{
	bool up[5];
	bool down[5];

	for (auto& data : up)
		cin >> data;
	for (auto& data : down)
		cin >> data;

	int result = HurtCount(up, down, 5);

	cout << result << "°³";

	return 0;
}