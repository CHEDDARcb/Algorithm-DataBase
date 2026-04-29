#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> bst;

struct Node
{
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
};
Node* head;

void Insert(Node** cur, Node* data)
{
	if ((*cur) == nullptr)
		(*cur) = data;
	else if ((*cur)->data > data->data)
	{
		Insert(&(*cur)->left, data);
	}
	else
	{
		Insert(&(*cur)->right, data);
	}
}

bool Find(Node* start, int target)
{
	if (start == nullptr)
		return false;

	if (start->data == target)
		return true;
	else if (start->data > target)
		return Find(start->left, target);
	else
		return Find(start->right, target);
}

int main(void)
{
	cin >> n;

	bst.resize(n + 1, 0);

	head = new Node;
	while (n--)
	{
		int data;
		cin >> data;

		//Insert(1, data);
		Node* newNode = new Node;
		newNode->data = data;
		Insert(&(head->right), newNode);
	}

	for (int i = 1; i <= 6; ++i)\
	{
		cout << i << ": ";
		if (Find(head->right, i))
			cout << "O" << endl;
		else
			cout << "X" << endl;
	}

	return 0;
}
