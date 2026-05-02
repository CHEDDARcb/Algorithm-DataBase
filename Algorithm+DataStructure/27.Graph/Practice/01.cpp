#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void push(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = nullptr;

	if (head == nullptr) head = newNode;
	else tail->next = newNode;
	tail = newNode;
}

void pop()
{
	if (head)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

int main()
{
	int n;
	cin >> n;

	while (n--)
	{
		char menu;
		int data;
		cin >> menu >> data;

		switch (menu)
		{
		case 'E':
			push(data);
			break;
		case 'D':
			pop();
		default:
			break;
		}
	}

	Node* cur = head;
	while (cur)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}

	return 0;
}