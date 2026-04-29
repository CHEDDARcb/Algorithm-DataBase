#include <iostream>

using namespace std;

struct Node
{
	char ch;
	Node* next;
};

Node buf[100];
int bufCnt = 0;
Node* head = nullptr;

Node* myAlloc(int ch, Node* next)
{
	buf[bufCnt].ch = ch;
	buf[bufCnt].next = next;
	return &buf[bufCnt++];
}

void addNode(char ch)
{
	head = myAlloc(ch, head);
}

int main()
{
	addNode('E');
	addNode('D');
	addNode('C');
	addNode('B');
	addNode('A');

	Node* cur = head;
	while (cur)
	{
		cout << cur->ch << " ";
		cur = cur->next;
	}

	return 0;
}