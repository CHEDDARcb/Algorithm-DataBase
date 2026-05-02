#include <iostream>

using namespace std;

class Item
{
	Item() = delete;
	Item(const Item&) = delete;
	Item& oeprator(const Item&) = delete;
public:
	Item(const char* _name, const char* _descript,
		const float _weight, const int _number)
		: mName{}
		, mDescript{}
		, mWeight(_weight)
		, mNumber(_number)
	{
		int len = strlen(_name);
		strncpy_s(mName, len + 1, _name, len);

		len = strlen(_descript);
		strncpy_s(mDescript, len + 1, _descript, len);
	}
	~Item() = default;

public:
	void			IncreaseItem(const int _num) { mNumber += _num; }
	void			DecreaseItem(const int _num) { mNumber -= _num; }

public:
	const char* GetName()const { return mName; }
	const char* GetDescript()const { return mDescript; }
	const float		GetWeight()const { return mWeight; }
	const int		GetNumber()const { return mNumber; }

private:
	char		mName[256];
	char		mDescript[256];
	float		mWeight;
	int			mNumber;
};

class Inventory
{
	Inventory() = delete;
	Inventory(const Inventory&) = delete;
	Inventory& operator=(const Inventory&) = delete;
public:
	Inventory(const char* _owner)
		: mOwner{}
		, mItems{}
		, mItemNum(0)
	{
		int len = strlen(_owner);
		strncpy_s(mOwner, len + 1, _owner, len);
	}
	~Inventory() = default;

public:
	void		AddItem(Item* _item) { mItems[mItemNum++] = _item; }
	void		IncreaseItem(const char* _itemName, const int _incNum)
	{
		for (int i = 0; i < mItemNum; ++i)
		{
			if (!strcmp(_itemName, mItems[i]->GetName()))
			{
				mItems[i]->IncreaseItem(_incNum);
			}
		}
	}
	void		DecreaseItem(const char* _itemName, const int _incNum)
	{
		for (int i = 0; i < mItemNum; ++i)
		{
			if (!strcmp(_itemName, mItems[i]->GetName()))
			{
				mItems[i]->DecreaseItem(_incNum);
			}
		}
	}

public:
	void		PrintInventoryInfo()const
	{
		cout << "Inventory of: " << mOwner << endl;
		for (int i = 0; i < mItemNum; ++i)
		{
			cout << "Item: " << mItems[i]->GetName() << " - ";
			cout << mItems[i]->GetDescript() << " ";
			cout << "(x" << mItems[i]->GetNumber() << ")" << " | ";
			cout << "Weight: " << mItems[i]->GetWeight() << endl;
		}
	}
private:
	char	mOwner[256];
	Item* mItems[100];
	int		mItemNum;
};

int main()
{
	Item item1("Potion", "Heals 50HP", 0.5f, 1);
	Item item2("Bomb", "Deals 100 Damage", 1.f, 2);

	Inventory iven("Player1");

	iven.AddItem(&item1);
	iven.AddItem(&item2);
	iven.IncreaseItem("Potion", 4);

	iven.PrintInventoryInfo();

	return 0;
}