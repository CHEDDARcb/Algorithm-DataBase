#include <iostream>

using namespace std;

struct Vector2
{
	float x, y;
	Vector2(float x_, float y_) : x(x_), y(y_) {}

	friend ostream& operator<<(ostream& out, const Vector2& v);

	bool operator==(const Vector2& v)
	{
		return (x == v.x) && (y == v.y);
	}

	bool operator!=(const Vector2& v)
	{
		return (x != v.x) || (y != v.y);
	}

	Vector2 operator+(const Vector2& v)
	{
		return Vector2(x + v.x, y + v.y);
	}

	Vector2 operator-(const Vector2& v)
	{
		return Vector2(x - v.x, y - v.y);
	}

	Vector2 operator*(const Vector2& v)
	{
		return Vector2(x * v.x, y * v.y);
	}

	Vector2 operator/(const Vector2& v)
	{
		return Vector2(x / v.x, y / v.y);
	}

	Vector2 operator+=(const Vector2& v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	Vector2 operator-=(const Vector2& v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}

	Vector2 operator*=(const Vector2& v)
	{
		x *= v.x;
		y *= v.y;
		return *this;
	}

	Vector2 operator/=(const Vector2& v)
	{
		x /= v.x;
		y /= v.y;
		return *this;
	}

	bool operator<(const Vector2& v)
	{
		return (x < v.x) && (y < v.y);
	}

	bool operator>(const Vector2& v)
	{
		return (x > v.x) && (y > v.y);
	}

	bool operator<=(const Vector2& v)
	{
		return (x <= v.x) && (y <= v.y);
	}
	// 10가지 이상의 연산자 구현하기
	// ==, !=, +, -, *, /, +=, -=, *=, /=, <, >, <= 등
};

ostream& operator<<(ostream& out, const Vector2& v)
{
	out << v.x << ", " << v.y;
	return out;
}

int main(void)
{
	Vector2 v1(1.f, 1.f);
	Vector2 v2(2.f, 2.f);

	//==
	cout << (v1 == Vector2(1.f, 1.f)) << endl;
	cout << (v1 == v2) << endl;

	//!=
	cout << (v1 != Vector2(1.f, 1.f)) << endl;
	cout << (v1 != v2) << endl;

	//=, <<, +, -, *, /, +=, -=, *=, /=
	Vector2 v3 = v1 + v2;
	cout << v3 << endl;

	v3 = v1 - v2;
	cout << v3 << endl;

	v3 = v1 * v2;
	cout << v3 << endl;

	v3 = v1 / v2;
	cout << v3 << endl;

	v1 += v2;
	cout << v1 << endl;

	v1 -= v2;
	cout << v1 << endl;

	v1 *= v2;
	cout << v1 << endl;

	v1 /= v2;
	cout << v1 << endl;

	// <
	cout << (v1 < v2) << endl;

	// >
	cout << (v1 > v2) << endl;

	// <=
	cout << (v1 <= v2) << endl;

	return 0;
}
