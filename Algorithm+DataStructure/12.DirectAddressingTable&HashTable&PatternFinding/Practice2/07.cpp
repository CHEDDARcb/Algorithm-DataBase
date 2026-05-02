#include <iostream>

using namespace std;

bool FindTarget(const char _base[], const size_t _bSize, const char _target)
{
	for (int i = 0; i < _bSize; ++i)
	{
		if (_base[i] == _target)
			return true;
	}

	return false;
}

int main()
{
	const char* vect = "CODING";
	int n;

	cin >> n;

	char* targets = new char[n];
	bool bucket[256]{};
	for (int i = 0; i < n; ++i)
	{
		cin >> targets[i];

		if (FindTarget(vect, strlen(vect) + 1, targets[i]))
		{
			int idx = static_cast<int>(targets[i]);
			bucket[idx] = true;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		int idx = static_cast<int>(targets[i]);
		if (bucket[idx])
		{
			cout << "O";
		}
		else
			cout << "X";
	}

	delete[] targets;

	return 0;
}