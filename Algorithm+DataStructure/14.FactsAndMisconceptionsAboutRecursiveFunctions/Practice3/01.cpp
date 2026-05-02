#include <iostream>

using namespace std;

class Tower
{
public:
	Tower()
		: mHeight(0)
		, mWidth(0)
	{
	}
	Tower(const int _length)
		: mHeight(_length)
		, mWidth(_length)
	{
	}

public:
	void		SetHeight(const int _height) { mHeight = _height; }
	void		SetWidth(const int _width) { mWidth = _width; }

public:
	int			getHeight()const { return mHeight; }
	int			getWidth()const { return mWidth; }

private:
	int mHeight;
	int mWidth;
};
int main()
{
	Tower myTower;
	Tower seoulTower(100);

	cout << "높이는 " << myTower.getHeight() << "미터" << endl;
	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;

	return 0;
}