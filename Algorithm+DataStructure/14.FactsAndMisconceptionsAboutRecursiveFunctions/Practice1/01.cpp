#include <iostream>

using namespace std;

void bbq(int callCnt)
{
	if (callCnt <= 1) return;

	bbq(callCnt - 1);
}

int main()
{
	int callCnt = 4;

	bbq(callCnt);

	return 0;
}