#include <iostream>

using namespace std;

int main(void)
{
	int input;
	int cnt = 0;

	while (cnt < 4)
	{
		cin >> input;

		if (input == 20)
			cout << "정답입니다" << endl;
		else if (input < 20)
			cout << "더 큰수를 입력하세요" << endl;
		else if (input > 20)
			cout << "더 작은수를 입력하세요" << endl;

		++cnt;
	}

	return 0;
}