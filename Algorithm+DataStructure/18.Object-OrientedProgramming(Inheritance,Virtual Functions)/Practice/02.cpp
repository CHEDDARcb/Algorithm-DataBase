#include <iostream>

using namespace std;

const float PI = 3.14159;

class Shape
{
	Shape(const Shape&) = delete;
	Shape& operator=(const Shape&) = delete;

public:
	Shape() = default;
	~Shape() = default;

public:
	virtual float Area()const = 0;
};

class Circle : public Shape
{
	Circle() = delete;
	Circle(const Circle&) = delete;
	Circle& operator=(const Circle&) = delete;

public:
	Circle(const float rad)
		:mRadius(rad)
	{
	}
	~Circle() = default;

public:
	float Area()const override
	{
		return mRadius * mRadius * PI;
	}

private:
	float mRadius;
};

class Rectangle : public Shape
{
	Rectangle() = delete;
	Rectangle(const Rectangle&) = delete;
	Rectangle& operator=(const Rectangle&) = delete;

public:
	Rectangle(const float width, const float height)
		: mWidth(width)
		, mHeight(height)
	{
	}
	~Rectangle() = default;

public:
	float Area()const override
	{
		return mWidth * mHeight;
	}

private:
	float mWidth;
	float mHeight;
};

int main(void)
{
	Circle c(3.0);
	Rectangle r(4.0, 2.0);
	Shape* shapes[] = { &c, &r };

	for (int i = 0; i < 2; ++i)
		std::cout << shapes[i]->Area() << std::endl;

	return 0;
}