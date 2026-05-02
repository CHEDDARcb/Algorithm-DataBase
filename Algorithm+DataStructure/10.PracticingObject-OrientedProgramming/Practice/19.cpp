#include <iostream>

using namespace std;

class Product
{
	Product() = delete;
	Product(const Product&) = delete;
	Product& operator=(const Product&) = delete;
public:
	Product(const char* name, const float price, const int quantity = 0, const int disocountRate = 0)
		: mName{}
		, mPrice(price)
		, mQuantity(quantity)
		, mDiscountRate(disocountRate)
		, mTotalPrice(0.f)
	{
		int len = strlen(name);
		strncpy_s(mName, len + 1, name, len);

		float totalBfrDC = price * quantity;
		mTotalPrice = totalBfrDC - totalBfrDC * disocountRate / 100;
	}
	~Product() = default;

public:
	void			SetQuantity(const int quantity)
	{
		mQuantity = quantity;

		CalcTotalPrice();
	}

	void			SetDiscountRate(const int dcRate)
	{
		mDiscountRate = dcRate;

		CalcTotalPrice();
	}

public:
	const char* GetName()const { return mName; }
	const int		GetPrice()const { return mPrice; }
	const int		GetQuantity()const { return mQuantity; }
	const int		GetDiscountRate()const { return mDiscountRate; }
	const int		GetTotalPrice()const { return mTotalPrice; }

private:
	void			CalcTotalPrice()
	{
		float totalBfrDC = mPrice * mQuantity;
		mTotalPrice = totalBfrDC - totalBfrDC * mDiscountRate / 100;
	}

private:
	char		mName[256];
	float		mPrice;
	int			mQuantity;
	int			mDiscountRate;
	float		mTotalPrice;
};

class Order
{
	Order() = delete;
	Order(const Order&) = delete;
	Order& operator=(const Order&) = delete;
public:
	Order(const char* _name, const char* date)
		: mName{}
		, mDate{}
		, mProducts{}
		, mProductNum(0)
		, mTotalPrice(0)
	{
		int len = strlen(_name);
		strncpy_s(mName, len + 1, _name, len);

		len = strlen(date);
		strncpy_s(mDate, len + 1, date, len);
	}

public:
	void		AddOrderedProduct(Product* _product)
	{
		mProducts[mProductNum++] = _product;
		mTotalPrice += _product->GetTotalPrice();
	}

	void		SetName(const char* _name)
	{
		if (strlen(mName))
			memset(mName, 0, sizeof(mName));
		int len = strlen(_name);
		strncpy_s(mName, len + 1, _name, len);
	}

	void		SetDate(const char* _date)
	{
		if (strlen(mDate))
			memset(mDate, 0, sizeof(mDate));
		int len = strlen(_date);
		strncpy_s(mDate, len + 1, _date, len);
	}

public:
	void		PrintOrderInfo()const
	{
		cout << "Order by: " << mName << "| ";
		cout << "Date: " << mDate << endl;
		cout << "Items: " << endl;
		for (int i = 0; i < mProductNum; ++i)
		{
			cout << " - " << mProducts[i]->GetName() << ": ";
			cout << "$" << mProducts[i]->GetPrice();
			cout << " x " << mProducts[i]->GetQuantity();
			cout << " (Discount " << mProducts[i]->GetDiscountRate() << "%) ";
			cout << "-> $" << mProducts[i]->GetTotalPrice() << endl;
		}
		cout << "Total: $" << mTotalPrice << endl;
	}

private:
	char		mName[256];
	char		mDate[256];
	Product* mProducts[100];
	int			mProductNum;
	int			mTotalPrice;
};

int main()
{
	Product p1("Keyboard", 50, 1, 0);
	Product p2("Mouse", 20, 2, 10);
	Order order("Alice", "2024-05-18");

	order.AddOrderedProduct(&p1);
	order.AddOrderedProduct(&p2);

	order.PrintOrderInfo();

	return 0;
}