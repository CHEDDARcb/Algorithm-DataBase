#include <iostream>

using namespace std;

void BBQ(int depthCnt, const int maxDepth = 3)
{
	if (depthCnt == 3) return;
	BBQ(depthCnt + 1, maxDepth);
}

int main()
{
	BBQ(1, 3);

	return 0;
}