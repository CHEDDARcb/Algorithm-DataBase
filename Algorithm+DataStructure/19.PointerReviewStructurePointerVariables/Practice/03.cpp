#include <iostream>

using namespace std;

struct Robot
{
	int a;
	int b;
	char str[6];
};

int main(void)
{
	Robot rb;

	cin >> rb.a >> rb.b >> rb.str;

	Robot* prb = &rb;

	cout << prb->a + prb->b << " " << prb->str << endl;

	return 0;
}