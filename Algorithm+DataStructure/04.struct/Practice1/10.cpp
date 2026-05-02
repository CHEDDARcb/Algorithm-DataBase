#include <iostream>

using namespace std;

void checkArr(char _target)
{
	if (_target >= 'A' && _target <= 'Z')
		cout << "´ë";
	else if (_target >= 'a' && _target <= 'z')
		cout << "¼Ò";
}

int main(void)
{
	char arr[5];

	for (auto& data : arr)
	{
		cin >> data;
	}

	for (const auto& data : arr)\
	{
		checkArr(data);
	}

	return 0;
}