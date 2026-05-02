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

			Node()
				: back(nullptr)
			{
			}
		};
		class Iterator
		{
		public:
			Iterator(Node* node)
				: iter(node)
			{
			}

		public:
			Iterator& operator=(const Iterator node)
			{
				iter = node.iter;

				return *this;
			}

			Iterator& operator++()
			{
				if (iter) iter = iter->back;

				return *this;
			}

			T& operator*()
			{
				if (iter) return iter->data;
			}

			bool operator!=(const Iterator node)
			{
				return iter != node.iter;
			}
		private:
			Node* iter;
		};

	public:
		list()
			: mHead(nullptr)
			, mTail(nullptr)
			, mSize(0)
		{

		}
		~list()
		{
			Node* delNode = mHead;
			Node* delNxt;
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
			++mSize;
		}

		Iterator begin()const { return Iterator(mHead); }
		Iterator end()const { return Iterator(mTail->back); }

	public:
		int size()const { return mSize; }

	private:
		Node* mHead;
		Node* mTail;
		int		mSize;
	};
}

int main(void)
{
	ya::list<int> yaList;

	yaList.push_back(1);
	yaList.push_back(2);
	yaList.push_back(3);
	yaList.push_back(4);
	yaList.push_back(5);
	yaList.push_back(6);
	yaList.push_back(7);
	yaList.push_back(8);
	yaList.push_back(9);

	int a = 1;
	for (ya::list<int>::Iterator iter = yaList.begin(); iter != yaList.end(); ++iter)
	{
		cout << *iter << endl;
	}

	return 0;
}