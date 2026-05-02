#include <iostream>

using namespace std;

struct Node
{
	char* name;
	Node* love1;
	Node* love2;

	Node(const char* _name, Node* l1 = nullptr, Node* l2 = nullptr)
		: love1(l1)
		, love2(l2)
	{
		int len = strlen(_name);
		name = new char[len + 1];
		strcpy_s(name, len + 1, _name);
	}
	~Node()
	{
		delete[] name;
	}
};

int main(void)
{
	Node* head =
		new Node("boss",
			new Node("wife"),
			new Node("son",
				new Node("girlfriend"),
				new Node("boyfriend")));

	head->love1->love1 = head;
	head->love1->love2 = head->love2;
	head->love2->love1->love1 = head->love2;
	head->love2->love1->love2 = head->love2->love2;
	head->love2->love2->love1 = head->love2->love1;

	cout << head->love2->love1->name << endl;
	cout << head->love2->love2->name << endl;

	return 0;
}