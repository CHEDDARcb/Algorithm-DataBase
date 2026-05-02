#include <iostream>

using namespace std;

char arr[2][3];

void findUpper()
{
	int cnt = 0;
	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			if (data >= 'A' && data <= 'Z')
				++cnt;
		}
	}

	cout << "대문자" << cnt << "개" << endl;
}

void findLower()
{
	int cnt = 0;
	for (const auto& row : arr)
	{
		for (const auto& data : row)
		{
			if (data >= 'a' && data <= 'z')
				++cnt;
		}
	}

	cout << "소문자" << cnt << "개" << endl;
}

int main(void)
{

	for (auto& row : arr)
	{
		for (auto& data : row)
		{
			cin >> data;
		}
	}

	findUpper();
	findLower();

	return 0;
}