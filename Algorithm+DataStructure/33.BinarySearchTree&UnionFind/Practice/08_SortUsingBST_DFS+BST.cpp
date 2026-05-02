#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
};

Node* head;

void Insert(Node** cur, Node* target)
{
	if (*cur == nullptr)
		*cur = target;
	else if ((*cur)->data > target->data)
		Insert(&(*cur)->left, target);
	else if ((*cur)->data <= target->data)
		Insert(&(*cur)->right, target);

}

void Input()
{
	head = new Node;

	for (int i = 0; i < 5; ++i)
	{
		int data;
		cin >> data;

		Node* newNode = new Node;
		newNode->data = data;

		Insert(&(head->right), newNode);
	}
}

void Sort(Node* cur, vector<int>& result, int* idx)
{
	if (cur == nullptr)
		return;
	Sort(cur->left, result, idx);
	result[*idx] = cur->data;
	(*idx)++;
	Sort(cur->right, result, idx);
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
	Input();

	vector<int> result(5);
	int idx = 0;
	Sort(head->right, result, &idx);

	for (int i = 0; i < idx; ++i)
	{
		cout << result[i] << ' ';
	}

	FreeAll(head->right);
	delete head;
}