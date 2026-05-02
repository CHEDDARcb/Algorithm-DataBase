#include<iostream>

using namespace std;


bool isSame(const int _passward[], const int _input[], const size_t _size)
{
	for (size_t i = 0; i < _size; ++i)
	{
		if (_passward[i] != _input[i])
			return false;
	}

	return true;
}

int main()
{
	int passward[4] = { 3, 7, 4, 9 };
	int input[4];

	for (auto& data : input)
		cin >> data;

	if (isSame(passward, input, 4))
		cout << "pass";
	else
		cout << "fail";

	return 0;
}