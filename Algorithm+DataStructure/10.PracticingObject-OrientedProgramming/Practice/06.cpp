#include <iostream>

#include <iostream>

using namespace std;

class Point
{
	Point() = delete;
public:
	Point(const int x, const int y, const int z, const char tag = '\0')
		: mXPos(x)
		, mYPos(y)
		, mZPos(z)
		, mTag(tag)
	{
	}
	Point(const Point&) = default;
	Point& operator=(const Point&) = default;
	~Point() = default;

public:
	void		SetXPos(const int xpos) { mXPos = xpos; }
	void		SetYPos(const int ypos) { mYPos = ypos; }
	void		SetZPos(const int zpos) { mZPos = zpos; }
	void		SetTag(const char tag) { mTag = tag; }

public:
	const int	GetXPos() const { return mXPos; }
	const int	GetYPos() const { return mYPos; }
	const int	GetZPos() const { return mZPos; }
	const char	GetTag()  const { return mTag; }

public:
	void		PrintPointInfo() const
	{
		cout << "Point Tag: " << mTag << " | ";
		cout << "Coordinates: " << "(" << mXPos << ", " << mYPos << ", " << mZPos << ")" << endl;
	}
	void		Translate(const int dx, const int dy, const int dz)
	{
		cout << "Translating.." << endl;
		mXPos += dx;
		mYPos += dy;
		mZPos += dz;
	}
private:
	int		mXPos;
	int		mYPos;
	int		mZPos;
	char	mTag;
};

int main()
{
	Point p1(3, 4, 7, 'A');

	p1.PrintPointInfo();

	p1.Translate(1, 1, 1);
	p1.PrintPointInfo();

	return 0;
}