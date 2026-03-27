#include <iostream>

using namespace std;

int main(void)
{
	int d = 0x6;		// 6 = 0110
	int result = 0;

	result = d & 0x1;	// 0번 비트만 추출

	if (result > 0)
		cout << "Bit 0 is 1";

	return 0;
}
