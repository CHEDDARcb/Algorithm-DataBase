#include <iostream>

using namespace std;

int main(void)
{
	char c1, c2;

	cin >> c1 >> c2;

	char* pc1 = &c1;
	char* pc2 = &c2;

	//XOR½º¿Ò
	// *pc1 = *pc1 ^ *pc2;
	// *pc2 = *pc1 ^ *pc2;
	// *pc1 = *pc1 ^ *pc2;

	int tmp = *pc1;
	*pc1 = *pc2;
	*pc2 = tmp;

	cout << *pc1 << " " << *pc2;

	return 0;
}
