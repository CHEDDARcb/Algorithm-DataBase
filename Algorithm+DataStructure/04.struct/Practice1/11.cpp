#include <iostream>

using namespace std;

struct Person
{
	int age;
	int height;
};

Person a, b;

void input()
{
	cin >> a.age >> a.height >> b.age >> b.height;
}

int main(void)
{
	input();

	cout << (a.age + b.age) / 2 << " ";
	cout << (a.height + b.height) / 2;

	return 0;
}