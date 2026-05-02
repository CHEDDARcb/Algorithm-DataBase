#include <iostream>

using namespace std;

int main()
{
	char str[256];
	cin >> str;

	bool bucket[256]{};
	for (int i = 0; str[i] != '\0'; ++i)
	{
		int idx = static_cast<int>(str[i]);
		if (!bucket[idx])
			bucket[idx] = true;
	}

	for (int i = 'A'; i <= 'Z'; ++i)
	{
		if (bucket[i])
			cout << static_cast<char>(i);
	}
	return 0;
}