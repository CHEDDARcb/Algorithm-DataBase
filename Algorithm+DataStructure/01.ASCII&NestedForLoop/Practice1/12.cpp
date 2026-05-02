#include <iostream>

using namespace std;

char flag;
char a, b, c;

void input()
{
	cin >> a >> b >> c;
}

void process()
{
	a != 'A' ? flag = 0 :
		b != 'B' ? flag = 0 :
		c != 'C' ? flag = 0 : flag = 1;
}

void output()
{
	if (flag)
	{
		cout << "ABC를찾았다";
	}
}
int main(void)
{
	input();
	process();
	output();

	return 0;
}