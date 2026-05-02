#include <iostream>

using namespace std;

struct BBQ
{
	int a;
	int b;
};

int main(void)
{
	BBQ* bbq = new BBQ;

	cin >> bbq->a >> bbq->b;

	cout << bbq->a + 5 << " " << bbq->b + 5;

	delete bbq;

	return 0;
}