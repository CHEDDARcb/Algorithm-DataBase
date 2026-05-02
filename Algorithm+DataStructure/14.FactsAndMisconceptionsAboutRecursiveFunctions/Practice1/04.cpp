#include <iostream>

using namespace std;

void abc(int data, int _depthCount)
{

	if (_depthCount <= 0)
	{
		cout << data << " ";
		return;
	}
	abc(data + 2, _depthCount - 1);
	cout << data << " ";
}

int main()
{
	int input;

	cin >> input;
	abc(input, 3);

	return 0;
}