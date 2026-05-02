#include <iostream>

using namespace std;

int main(void)
{
	char arr[3];

	for (int i = 0; i < 3; ++i)
	{
		cin >> arr[i];
	}

	bool flag = true;
	for (int i = 1; i < 3; ++i)
	{
		if (arr[0] < arr[i])
			flag = false;
	}

	if (flag)
	{
		cout << "¿Ç´Ù" << arr[0] << endl;
	}
	else
	{
		cout << "¿ÇÁö¾ÊÀ½" << endl;
	}

	return 0;
}