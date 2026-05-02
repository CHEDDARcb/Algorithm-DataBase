#include <iostream>

using namespace std;

int main(void)
{
	char str[11];
	char c[3];

	cin >> str;
	cin >> c[0] >> c[1] >> c[2];

	for (int i = 0; i < 3; ++i)
	{
		int cnt = 0;

		int idx = 0;
		while (str[idx] != '\0')
		{
			if (str[idx] == c[i])
				++cnt;

			++idx;
		}

		cout << c[i] << "=" << cnt << endl;
	}

	return 0;
}
