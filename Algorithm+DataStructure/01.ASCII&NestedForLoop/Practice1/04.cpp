#include <iostream>

using namespace std;

int main(void)
{
	char arr[6] = { '$', '@', 'D', 'A', '9', '#' };

	for (int i = 0; i < sizeof(arr) / sizeof(char); ++i)
	{
		cout << arr[i] << ":" << static_cast<int>(arr[i]) << endl;
	}

	return 0;
}