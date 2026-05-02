#include <iostream>

using namespace std;

void KFC(int* bigC, int* smallC)
{
	char input[100];

	cin >> input;

	for (int i = 0; input[i] != '\0'; ++i)
	{
		if (input[i] >= 'A' && input[i] < 'Z')
			++*bigC;
		else if (input[i] >= 'a' && input[i] <= 'z')
			++*smallC;
	}
}

int main(void)
{
	int bc = 0, sc = 0;

	KFC(&bc, &sc);

	cout << "대문자" << bc << "개" << endl;
	cout << "소문자" << sc << "개" << endl;

	return 0;
}