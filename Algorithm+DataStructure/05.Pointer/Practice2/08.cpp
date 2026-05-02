#include <iostream>

using namespace std;

int main(void)
{
	const char arr[14] = "StructPointer";
	char input;

	cin >> input;

	bool flg = false;
	for (const auto& data : arr)
	{
		if (data == input)
		{
			flg = true;
			break;
		}
	}

	if (flg)
		cout << "발견";
	else
		cout << "미발견";

	return 0;
}
