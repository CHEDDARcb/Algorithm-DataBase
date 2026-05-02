#include <iostream>

using namespace std;

int main(void)
{
	char arr[3];

	cin >> arr[0] >> arr[1] >> arr[2];

	int cnt = 0;
	for (const auto& data : arr)
	{
		if (data >= 'A' && data <= 'Z')
			++cnt;
	}

	if (cnt >= 3)
		cout << "풍족하다";
	else if (cnt >= 1 && cnt <= 2)
		cout << "적절하다";
	else
		cout << "부족하다";

	return 0;
}