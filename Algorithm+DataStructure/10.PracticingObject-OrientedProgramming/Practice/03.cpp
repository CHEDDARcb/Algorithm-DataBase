#include <iostream>

using namespace std;

class Rectangle
{
	Rectangle() = delete;
public:
	Rectangle(int width, int height)
		: mWidth(width)
		, mHeight(height)
		, mArea(width* height)
		, mPerimeter(2 * width + 2 * height)
		, mBorder(0)
		, mColor{}
	{
	}

	Rectangle(int width, int height, const int border, const char* color)
		: mWidth(width)
		, mHeight(height)
		, mArea(width* height)
		, mPerimeter(2 * width + 2 * height)
		, mBorder(border)
		, mColor{}
	{
		int len = strlen(color);
		strncpy_s(mColor, len + 1, color, len);
	}

	Rectangle(const Rectangle& rt)
		: mWidth(rt.mWidth)
		, mHeight(rt.mHeight)
		, mArea(rt.mWidth* rt.mHeight)
		, mPerimeter(2 * rt.mWidth + 2 * rt.mHeight)
		, mBorder(rt.mBorder)
		, mColor{}
	{
		if (strlen(rt.mColor))
		{
			int len = strlen(rt.mColor);
			strncpy_s(mColor, len + 1, rt.mColor, len);
		}
	}

	Rectangle& operator=(const Rectangle& rt)
	{
		mWidth = rt.mWidth;
		mHeight = rt.mHeight;
		mArea = rt.mArea;
		mPerimeter = rt.mPerimeter;
		mBorder = rt.mBorder;

		if (strlen(rt.mColor))
		{
			int len = strlen(rt.mColor);
			strncpy_s(mColor, len + 1, rt.mColor, len);
		}

		return *this;
	}

	~Rectangle() = default;

public:
	void				SetWidth(const int width)
	{
		mWidth = width;

		mArea = mWidth * mHeight;
		mPerimeter = 2 * mWidth + 2 * mHeight;
	}
	void				SetHeight(const int height)
	{
		mHeight = height;

		mArea = mWidth * mHeight;
		mPerimeter = 2 * mWidth + 2 * mHeight;
	}
	void				SetBorder(const int border) { mBorder = border; }
	void				SetColor(const char* color)
	{
		if (strlen(mColor))
		{
			memset(mColor, 0, sizeof(mColor));
		}
		int len = strlen(color);
		strncpy_s(mColor, len + 1, color, len);
	}

public:
	const int			GetWidth() const { return mWidth; }
	const int			GetHeight() const { return mHeight; }
	const int			GetArea() const { return mArea; }
	const int			GetPerimeter() const { return mPerimeter; }
	const int			GetBorder() const { return mBorder; }
	const char* GetColor() const { return mColor; }

public:
	void PrintRectangleInfo()const
	{
		cout << "Color: " << mColor << ", ";
		cout << "Border: " << mBorder << "px" << endl;
		cout << "Area: " << mArea << ", ";
		cout << "Perimeter: " << mPerimeter << endl;
	}

	bool IsSquare() const { return mWidth == mHeight; }

private:
	int		mWidth;
	int		mHeight;
	int		mArea;
	int		mPerimeter;
	int		mBorder;
	char	mColor[256];
};

int main()
{
	Rectangle rt1(1, 2, 3, "Blue");
	rt1.PrintRectangleInfo();

	if (rt1.IsSquare())
		cout << "Squre";
	else
		cout << "Not Squre";

	return 0;
}