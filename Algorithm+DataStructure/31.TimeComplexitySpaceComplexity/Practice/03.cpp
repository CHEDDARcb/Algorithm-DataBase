#include <iostream> 

using namespace std;

int data[10];

int main()
{
	return 0;
}

// 4 * 10
// 40 bytes

#include <iostream> 

using namespace std;

double data[3];
char vect[10];
int dt[10];

int main()
{
	return 0;
}

// 8 * 3 + 1 * 10 + 4 * 10
// 74 bytes

#include <iostream> 

using namespace std;

struct Node
{
	int x;
	char t;
};
Node vect[100];

int main()
{
	return 0;
}

// 8 * 100 = 800bytes

#include <iostream> 

using namespace std;

struct Node { int x; char* next; };
Node vect;
int main() { return 0; }

// 8 + 8 = 16bytes