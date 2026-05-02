#include <iostream>

using namespace std;

struct Node
{
	char data;
	Node* nxt;

	Node(char _data, Node* _nxt = nullptr)
		: data(_data)
		, nxt(_nxt)
	{
	}
};

void Destroy(Node* delNode)
{
	if (delNode == nullptr) return;

	Destroy(delNode->nxt);

	delete delNode;
}

int main(void)
{
	Node* head =
		new Node('Q',
			new Node('T',
				new Node('P',
					new Node('k',
						new Node('Q')))));

	Node* cur = head;
	while (cur->nxt)
	{
		cur = cur->nxt;
	}

	cout << cur->data;

	Destroy(head);

	return 0;
}