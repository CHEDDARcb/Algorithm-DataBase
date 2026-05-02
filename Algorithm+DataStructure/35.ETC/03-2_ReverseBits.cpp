#include<iostream>
using namespace std;

uint32_t reverseBits(uint32_t n) \
{ 
    uint32_t res = 0; 
    for (int i = 0; i < 32; ++i) 
    { 
        res = (res << 1) | (n & 1); 
        n >>= 1; 
    } 
    return res;
}

int main() {
    string s;
    cin >> s;

    uint32_t n = 0;
    for (char c : s) {
        n = (n << 1) + (c - '0');
    }

    cout << reverseBits(n);
}
