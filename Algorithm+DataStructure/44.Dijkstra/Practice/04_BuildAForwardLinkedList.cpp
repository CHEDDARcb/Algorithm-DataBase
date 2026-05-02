#include <iostream>

using namespace std;

struct Node
{
	int d;
	Node* nxt;
};
Node* buf;
Node* head = nullptr;
Node* tail = nullptr;
int bufSize = 0;

Node* Alloc(int d)
{
	buf[bufSize].d = d;
	buf[bufSize].nxt = nullptr;
	return &buf[bufSize++];
}

void Insert(int d)
{
	Node* newNode = Alloc(d);

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->nxt = newNode;
		tail = newNode;
	}
}

int main(void)
{
	int n;
	cin >> n;

	buf = new Node[n];

	for (int i = 0; i < n; ++i)
	{
		int d;
		cin >> d;

		Insert(d);
	}

	Node* cur = head;
	while (cur)
	{
		cout << cur->d << " ";
		cur = cur->nxt;
	}

	return 0;
}