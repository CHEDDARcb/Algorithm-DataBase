#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	const char pass[5][10] =
	{
		"Jason",
		"Dr.tom",
		"EXEXI",
		"GK12P",
		"POW"
	};
	char input[10];

	cin >> input;

	bool isLock = true;
	for (const auto& p : pass)
	{
		if (strcmp(input, p) == 0)
			isLock = false;
	}

	if (isLock) cout << "암호틀림";
	else cout << "암호해제";

	return 0;
}