#include <iostream>
#include <cmath>

using namespace std;

class Circle
{
	Circle() = delete;
public:
	Circle(int radius, bool isFilled = false, float opacity = 0.f)
		: mRadius(radius)
		, mArea(PI* radius* radius)
		, mCircumference(2 * PI * radius)
		, mColor{}
		, mIsFilled(isFilled)
		, mOpacity(opacity)
	{
	}
	Circle(int radius, const char* color, bool isFiled = false, float opacity = 0.f)
		: mRadius(radius)
		, mArea(PI* radius* radius)
		, mCircumference(2 * PI * radius)
		, mColor{}
		, mIsFilled(isFiled)
		, mOpacity(opacity)
	{
		int len = strlen(color);
		strncpy_s(mColor, len + 1, color, len);
	}
	Circle(const Circle& circle)
		: mRadius(circle.mRadius)
		, mArea(circle.mArea)
		, mCircumference(circle.mCircumference)
		, mColor{}
		, mIsFilled(circle.mIsFilled)
		, mOpacity(circle.mOpacity)
	{
		if (strlen(circle.mColor))
		{
			int len = strlen(circle.mColor);
			strncpy_s(mColor, len + 1, circle.mColor, len);
		}
	}
	Circle& operator=(const Circle& circle)
	{
		mRadius = circle.mRadius;
		mArea = circle.mArea;
		mCircumference = circle.mCircumference;
		mIsFilled = circle.mIsFilled;
		mOpacity = circle.mOpacity;

		if (strlen(circle.mColor))
		{
			int len = strlen(circle.mColor);
			strncpy_s(mColor, len + 1, circle.mColor, len);
		}
		return *this;
	}
	~Circle() = default;

public:
	void				SetRadius(const int rad)
	{
		mRadius = rad;
		mArea = PI * rad * rad;
		mCircumference = 2 * PI * rad;
	}
	void				SetColor(const char* color)
	{
		if (strlen(mColor))
			memset(mColor, 0, sizeof(mColor));
		int len = strlen(color);
		strncpy_s(mColor, len + 1, color, len);
	}
	void				SetFilled(const bool filled) { mIsFilled = filled; }
	void				SetOpacity(const float opacity) { mOpacity = opacity; }

public:
	const int			GetRadius() const { return mRadius; }
	const float			GetArea() const { return mArea; }
	const float			Getcirumference() const { return mCircumference; }
	const char* GetColor() const { return mColor; }
	const float			GetOpacity() const { return mOpacity; }

public:
	void				PrintCircleInfo() const
	{
		cout << "Circle" << endl;
		cout << "Radius: " << mRadius << endl;
		cout << "Color: " << mColor << endl;
		cout << "Filled :";
		mIsFilled ? cout << "Yes" : cout << "No";
		cout << endl;
		cout << "Opacity: " << mOpacity << endl;
		cout << "Area: " << mArea << endl;
		cout << "Circumference: " << mCircumference << endl;

	}

private:
	static const float	PI;
	int					mRadius;
	float				mArea;
	float				mCircumference;
	char				mColor[256];
	bool				mIsFilled;
	float				mOpacity;

};
const float Circle::PI = 3.14f;

int main()
{
	Circle circleSample(5, "Red", true, 0.75);
	circleSample.PrintCircleInfo();

	return 0;
}