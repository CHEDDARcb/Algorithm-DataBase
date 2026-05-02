#include <iostream>

using namespace std;

char str[8];
int dat[4];
char* ptrs[4];

int main(void)
{
	cin >> str;

	for (auto& d : dat)
		cin >> d;

	for (int i = 0; i < 4; ++i)
	{
		ptrs[i] = &str[dat[i]];
	}

	for (int i = 0; i < 4; ++i)
	{
		cout << *ptrs[i];
	}

	return 0;
}