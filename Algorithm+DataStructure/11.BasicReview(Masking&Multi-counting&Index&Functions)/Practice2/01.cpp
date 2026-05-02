#include<iostream>

using namespace std;


int main()
{
	int bit[7];
	int vect[7] = { 3, 5, 4, 2, 6, 6, 5 };

	for (auto& data : bit)
	{
		cin >> data;
	}

	for (int i = 0; i < 7; ++i)
	{
		if (!bit[i])
			vect[i] = 0;
	}

	for (const auto& data : vect)
	{
		if (data)
			cout << 7;
		else
			cout << data;

	}

	return 0;
}