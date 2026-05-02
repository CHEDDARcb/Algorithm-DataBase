#include <iostream>

using namespace std;

class SortedArray
{
public:
    SortedArray();
    SortedArray(const SortedArray& src);
    SortedArray(int p[], int size);
    ~SortedArray();

public:
    SortedArray operator+(SortedArray& op2);
    SortedArray operator=(const SortedArray& op2);
    void Show();

private:
    void Sort();

private:
    int size;
    int* p;
};

SortedArray::SortedArray()
    : size(0)
    , p(nullptr)
{
}

SortedArray::SortedArray(const SortedArray& src)
{
    size = src.size;
    p = new int[src.size];

    for (int i = 0; i < size; ++i)
    {
        p[i] = src.p[i];
    }
}

SortedArray::SortedArray(int p[], int size)
{
    this->size = size;
    this->p = new int[size];

    for (int i = 0; i < size; ++i)
    {
        this->p[i] = p[i];
    }

    Sort();
}

SortedArray::~SortedArray()
{
    delete[] p;
}

SortedArray SortedArray::operator+(SortedArray& op2)
{
    int newSize = this->size + op2.size;
    int* tmp = new int[newSize];

    int idx = 0;
    int p1 = 0;
    int p2 = 0;
    while (p1 < this->size && p2 < op2.size)
    {
        int min;
        if (this->p[p1] < op2.p[p2])
        {
            min = this->p[p1++];
        }
        else
        {
            min = op2.p[p2++];
        }

        tmp[idx++] = min;
    }

    for (int i = p1; i < this->size; ++i)
    {
        tmp[idx++] = this->p[i];
    }
    for (int i = p2; i < op2.size; ++i)
    {
        tmp[idx++] = op2.p[i];
    }

    SortedArray result(tmp, newSize);
    delete[] tmp;

    return result;
}

SortedArray SortedArray::operator=(const SortedArray& op2)
{
    if (this == &op2) return *this;

    delete[] p;
    size = op2.size;
    p = new int[op2.size];

    for (int i = 0; i < size; ++i)
    {
        p[i] = op2.p[i];
    }

    return *this;
}

void SortedArray::Show()
{
    cout << "배열 출력 : ";
    for (int i = 0; i < size; ++i)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}

void SortedArray::Sort()
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - 1 - i; ++j)
        {
            if (p[j] > p[j + 1])
            {
                int tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }
        }
    }
}


int main()
{
    int n[] = { 2, 20, 6 };
    int m[] = { 10, 7, 8, 30 };
    SortedArray a(n, 3), b(m, 4), c;

    c = a + b;

    a.Show();
    b.Show();
    c.Show();
}