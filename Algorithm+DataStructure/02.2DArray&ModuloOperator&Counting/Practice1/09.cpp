#include <iostream>

using namespace std;

int main(void)
{
	int arr[5];

	for (int i = 0; i < 5; ++i)
		cin >> arr[i];

	int idx = 1;
	for (const auto& data : arr)
	{
		cout << idx << "번사람은" << data << "점";
		if (data >= 70)
			cout << "PASS";
		else if (data >= 50)
			cout << "RETEST";
		else
			cout << "FAIL";

		cout << endl;
		++idx;
	}

	return 0;
}