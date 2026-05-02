
#include <iostream>

using namespace std;

int main(void)
{
	char arr[8];

	for (auto& data : arr)
	{
		cin >> data;
	}

	char big[8];
	char small[8];
	int bIDX = 0;
	int sIDX = 0;

	for (const auto& data : arr)
	{
		if (data >= 'A' && data <= 'Z')
			big[bIDX++] = data;
		else if (data >= 'a' && data <= 'z')
			small[sIDX++] = data;
	}

	cout << "big=";
	for (int i = 0; i < bIDX; ++i)
	{
		cout << big[i];
	}
	cout << endl;

	cout << "small=";
	for (int i = 0; i < sIDX; ++i)
	{
		cout << small[i];
	}

	return 0;
}