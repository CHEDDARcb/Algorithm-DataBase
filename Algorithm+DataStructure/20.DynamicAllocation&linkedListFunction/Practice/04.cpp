#include <iostream>

using namespace std;

struct Node
{
	char data;
	Node* left;
	Node* right;

	Node(char _data, Node* _left = nullptr, Node* _right = nullptr)
		: data(_data)
		, left(_left)
		, right(_right)
	{
	}
};

void Destory(Node* delNode)
{
	if (delNode == nullptr)
		return;

	Destory(delNode->left);
	Destory(delNode->right);

	delete delNode;
}

int main(void)
{
	Node* head =
		new Node('A',
			new Node('B',
				new Node('D'),
				new Node('E')),
			new Node('C'));
	char input[4];

	cin >> input;

	Node* cur = head;
	for (int i = 0; input[i] != '\0'; ++i)
	{
		if (input[i] == 'H') cur = head;
		else if (input[i] == 'L') cur = cur->left;
		else if (input[i] == 'R') cur = cur->right;
	}

	cout << cur->data;

	Destory(head);

	return 0;
}