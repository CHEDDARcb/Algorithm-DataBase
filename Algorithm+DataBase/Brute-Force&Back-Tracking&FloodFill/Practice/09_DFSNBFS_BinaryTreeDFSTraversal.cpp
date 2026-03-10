#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* head = nullptr;

void Push(Node** head, int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;

	if (*head == nullptr)
	{
		*head = newNode;
		return;
	}

	bool pushed = false;
	queue<Node*> que;
	que.push(*head);

	while (!que.empty())
	{
		Node* cur = que.front();
		que.pop();

		Node** l = &(cur->left);
		Node** r = &(cur->right);

		if (*l == nullptr)
		{
			*l = newNode;
			break;
		}
		else if (*l && *r == nullptr)
		{
			*r = newNode;
			break;
		}

		que.push(*l);
		que.push(*r);
	}
}

void Init()
{
	Push(&head, 1);
	Push(&head, 2);
	Push(&head, 5);
	Push(&head, 6);
	Push(&head, 7);
	Push(&head, 4);
	Push(&head, 3);
}

void DFS(Node* cur)
{
	if (cur == nullptr)
		return;

	cout << cur->data;
	DFS(cur->left);
	DFS(cur->right);
}

void FreeAll(Node* cur)
{
	if (cur == nullptr)
		return;

	FreeAll(cur->left);
	FreeAll(cur->right);
	delete cur;
}

int main(void)
{
	Init();

	DFS(head);

	FreeAll(head);

	return 0;
}