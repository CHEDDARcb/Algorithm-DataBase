#include <iostream>

using namespace std;

class Product
{
	Product() = delete;
	Product(const Product&) = delete;
	Product& operator=(const Product&) = delete;
public:
	Product(const char* name, const float price, const int quantity = 0, const int discountRate = 0)
		: mName{}
		, mPrice(price)
		, mQuantity(quantity)
		, mDiscountRate(discountRate)
		, mTotalPrice(0.f)
	{
		int len = strlen(name);
		strncpy_s(mName, len + 1, name, len);

		float totalBfrDC = price * quantity;
		mTotalPrice = totalBfrDC - totalBfrDC * discountRate / 100;
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
	const float		GetPrice()const { return mPrice; }
	const int		GetQuantity()const { return mQuantity; }
	const int		GetDiscountRate()const { return mDiscountRate; }
	const float		GetTotalPrice()const { return mTotalPrice; }

public:
	void			PrintProductInfo()const
	{
		cout << "Product: " << mName << " | ";
		cout << "Price: " << "$" << mPrice << " | ";
		cout << "Quantity: " << mQuantity << " | ";
		cout << "Discount: " << mDiscountRate << "%" << endl;
		cout << "Total after discount: " << "$" << mTotalPrice << endl;
	}

	void			Selling(const int num = 1)
	{
		if (mQuantity < num)
			return;
		mQuantity -= num;
	}

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

int main()
{
	Product pen("Pen", 2.f, 10);
	pen.SetDiscountRate(10);

	pen.PrintProductInfo();

	pen.Selling(5);
	pen.PrintProductInfo();
	pen.Selling(10);

	return 0;
}