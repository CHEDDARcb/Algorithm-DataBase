#include <iostream>

using namespace std;

int main(void)
{
	char arr[6] = { 'A', 'F', 'G', 'A', 'B', 'C' };
	char input1, input2;

	cin >> input1 >> input2;

	bool flg1 = false;
	bool flg2 = false;
	for (const auto& data : arr)
	{
		if (data == input1)
			flg1 = true;
		if (data == input2)
			flg2 = true;
	}

	if (flg1 && flg2)
		cout << "와2개" << endl;
	else if (flg1 || flg2)
		cout << "오1개" << endl;
	else
		cout << "우0개" << endl;

	return 0;
}
