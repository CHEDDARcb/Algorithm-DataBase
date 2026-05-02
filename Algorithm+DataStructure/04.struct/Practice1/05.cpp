#include <iostream>

using namespace std;

struct ABC
{
	int x;
	int y;
};

int main(void)
{
	ABC t;
	int inputX, inputY;

	cin >> t.x >> t.y;

	cout << t.x + t.y << endl;

	return 0;
}