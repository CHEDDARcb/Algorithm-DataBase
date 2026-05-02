#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> dat;
	string str;

	dat.resize(130, 0);
	cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		dat[size_t(str[i])]++;
	}

	for (int i = 'A'; i <= 'z'; ++i)
	{
		if (dat[i] >= 2)
			cout << char(i);
	}

	return 0;
}