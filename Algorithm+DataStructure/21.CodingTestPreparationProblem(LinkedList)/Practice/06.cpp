#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* Insert(Node* head, int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;

	if (head == nullptr) head = newNode;
	else
	{
		Node* cur = head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}

	return head;
}

void MakeCycle(Node* head, int pos)
{
	if (pos < 0) return;

	Node* target = nullptr;
	Node* cur = head;
	int idx = 0;
	while (cur->next)
	{
		if (idx == pos) target = cur;
		cur = cur->next;
		++idx;
	}

	if (idx == pos)
		target = cur;
	if (target)
		cur->next = target;
}

bool IsCycle(Node* head)
{
	Node* slow = head;
	Node* fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) return true;
	}

	return false;
}

void PrintAll(Node* head)
{
	Node* cur = head;
	while (cur)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
}

int main(void)
{
	int n, pos;
	cin >> n >> pos;

	Node* head = nullptr;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		head = Insert(head, x);
	}

	MakeCycle(head, pos);

	bool result = IsCycle(head);

	cout << (result ? "true" : "false");

	return 0;
}