#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* nxt;

	Node(int _data, Node* _nxt = nullptr)
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
		new Node(3,
			new Node(5,
				new Node(4,
					new Node(2))));

	Node* cur = head;

	while (cur)
	{
		cout << cur->data << " ";
		cur = cur->nxt;
	}

	Destroy(head);

	return 0;
}