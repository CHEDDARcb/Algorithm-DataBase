#include <iostream>

using namespace std;

int GOP()
{
	int a, b;

	cin >> a >> b;

	return a * b;
}

int SUM()
{
	int a, b;

	cin >> a >> b;

	return a + b;
}

int main(void)
{
	int g = GOP();
	int s = SUM();

	if (g > s)
		cout << "GOP > SUM";
	else if (g < s)
		cout << "GOP < SUM";
	else
		cout << "GOP == SUM";

	return 0;
}