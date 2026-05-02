#include <iostream>

using namespace std;

int main(void)
{
	int arr1[6] = { 10, 50, 40, 20, 30 ,40 };
	int arr2[6];

	for (auto& data : arr2)
		cin >> data;

	for (const auto& data2 : arr2)
	{
		int cnt = 0;
		for (const auto& data1 : arr1)
		{
			if (data2 < data1)
				++cnt;
		}

		cout << data2 << "=" << cnt << "°³" << endl;
	}

	return 0;
}