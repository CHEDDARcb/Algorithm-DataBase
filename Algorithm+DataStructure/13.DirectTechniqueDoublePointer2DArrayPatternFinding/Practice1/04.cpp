#include <iostream>

using namespace std;

int main()
{
	int g;
	cin >> g;

	int* p = &g;
	int* k = &g;
	int** t = &p;
	int** q = &k;

	cout << **t << " " << *k << endl;

	return 0;
}