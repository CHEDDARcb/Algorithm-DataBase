#include <iostream>

using namespace std;

int main(void)
{
	int n1, n2;

	cin >> n1 >> n2;

	int sub;
	if (n1 > n2)
		sub = n1 - n2;
	else
		sub = n2 - n1;

	if (sub % 2)
		cout << "°í¹éÇÑ´Ù" << endl;
	else
		cout << "Â¦»ç¶û¸¸" << endl;

	return 0;
}