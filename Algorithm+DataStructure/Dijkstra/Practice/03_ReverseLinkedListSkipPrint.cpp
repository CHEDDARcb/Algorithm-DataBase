#include <iostream>

using namespace std;

const int LEN = 9;

struct Node
{
	char c;
	Node* nxt;
};
Node buf[LEN];
Node* head = nullptr;
int bufSize = 0;

Node* Alloc(char c, Node* nxt)
{
	buf[bufSize].c = c;
	buf[bufSize].nxt = nxt;

	return &buf[bufSize++];
}

void Insert(char c)
{
	head = Alloc(c, head);
}

int main(void)
{
	for (int i = 0; i < LEN; ++i)
	{
		char c;
		cin >> c;

		Insert(c);
	}

	Node* cur = head;
	while (cur)
	{
		cout << cur->c;
		
		if (cur->nxt == nullptr)
			break;
		cur = cur->nxt->nxt;
	}

	return 0;
}