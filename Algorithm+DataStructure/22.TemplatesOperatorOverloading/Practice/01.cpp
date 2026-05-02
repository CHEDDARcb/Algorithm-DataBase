#include <iostream>
#include <list>

using namespace std;

namespace ya
{
	template <typename T>
	class list
	{
	public:
		struct Node
		{
			T data;
			Node* back;
		};

	public:
		list()
			: mHead(nullptr)
			, mTail(nullptr)
		{

		}
		~list()
		{
			Node* delNode = mHead;
			Node* delNxt = delNode->back;
			while (delNode)
			{
				delNxt = delNode->back;
				delete delNode;
				delNode = delNxt;
			}
		}

	public:
		void push_back(T data)
		{
			Node* newNode = new Node;
			newNode->data = data;
			newNode->back = nullptr;

			if (mHead == nullptr) mHead = newNode;
			if (mTail) mTail->back = newNode;

			mTail = newNode;
		}

	private:
		Node* mHead;
		Node* mTail;
	};
}

int main(void)
{
	ya::list<int> intList;

	intList.push_back(1);
	intList.push_back(2);

	std::list<int> stdList;
	stdList.push_back(1);
	stdList.push_back(2);

	return 0;
}