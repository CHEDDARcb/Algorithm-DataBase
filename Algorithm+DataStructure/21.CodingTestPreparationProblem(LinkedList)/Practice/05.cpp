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

Node* Reverse(Node* head)
{
	Node* prev = nullptr;
	Node* cur = head;

	while (cur)
	{
		Node* nxt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;
	}

	return prev;
}

bool IsPalindrome(Node* head)
{
	if (head == nullptr || head->next == nullptr)
		return true;

	Node* slow = head;
	Node* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	if (fast != nullptr) slow = slow->next;

	Node* halfStart = Reverse(slow);
	Node* c1 = head;
	Node* c2 = halfStart;
	while (c2)
	{
		if (c1->data != c2->data) return false;

		c1 = c1->next;
		c2 = c2->next;
	}

	return true;
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
	int n;
	cin >> n;

	Node* head = nullptr;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		head = Insert(head, x);
	}

	bool result = IsPalindrome(head);

	cout << (result ? "true" : "false");

	return 0;
}