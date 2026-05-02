#include <iostream>

using namespace std;


int main(void)
{
	char arr[6] = { '#', '-', '#', '-' , '#', '#' };

	for (const auto& data : arr)
	{
		if (data == '#')
			cout << "¼¥";
		else if (data == '-')
			cout << "¹«";
	}

	return 0;
}