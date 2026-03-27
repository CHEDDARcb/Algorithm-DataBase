#include <iostream>

using namespace std;

int main(void)
{
	int d = 0x6;		// 6 = 0110
	int result = 0;

	result = (d >> 1) & 0x1;	// 1번 비트를 0번 위치로 이동후 추출

	if (result > 0)
		cout << "Bit 1 is 1";

	return 0;
}
