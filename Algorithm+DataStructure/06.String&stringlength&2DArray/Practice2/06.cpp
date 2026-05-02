#include <iostream>

using namespace std;

int main(void)
{
	char vect[100];

	cin >> vect;

	int strSize = 0;
	while (vect[strSize] != '\0')
	{
		strSize++;
	}

	cout << strSize << endl;

	char target = vect[size_t(strSize - 1)];
	int count = 0;
	for (int i = 0; i < strSize; ++i)
	{
		if (vect[i] == target)
			++count;
	}

	cout << count;

	return 0;
}