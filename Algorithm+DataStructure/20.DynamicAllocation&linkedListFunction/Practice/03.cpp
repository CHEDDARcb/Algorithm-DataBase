#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

int main(void)
{
	Node* head = new Node;

	head->data = 3;
	head->left = new Node;
	head->right = new Node;

	head->left->data = 7;

	head->right->data = 6;
	head->right->left = new Node;

	head->right->left->data = 2;

	return 0;
}