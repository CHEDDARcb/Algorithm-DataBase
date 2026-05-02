#include <iostream>
#include <cmath>

using namespace std;

char aToZ()
{
	char input;

	cin >> input;

	int aDst = abs(static_cast<int>(input - 'A'));
	int bDst = abs(static_cast<int>(input - 'Z'));

	return aDst < bDst ? 'A' : 'Z';

}

int main(void)
{
	cout << aToZ() << endl;

	return 0;
}