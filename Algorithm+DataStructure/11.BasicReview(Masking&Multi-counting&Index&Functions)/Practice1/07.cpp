#include<iostream>

using namespace std;

int main()
{
	char base[6] = { 'B', 'T', 'K', 'I', 'G', 'Z' };
	char target[4];

	for (auto& data : target)
		cin >> data;

	int cnt = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int k = 0; k < 6; ++k)
		{
			if (target[i] == base[k])
				cnt++;
		}
	}

	cout << cnt;

	return 0;
}