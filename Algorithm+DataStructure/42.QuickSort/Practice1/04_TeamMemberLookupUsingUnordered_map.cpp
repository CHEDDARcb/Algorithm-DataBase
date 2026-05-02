#include <iostream>
#include <unordered_map>

using namespace std;

int main(void)
{
    unordered_map<string, int> uom = {
        {"POP", 1},
        {"TOM", 1},
        {"MC", 1},
        {"JASON", 1},
        {"KFC", 1}
    };

    int N;
    cin >> N;

    while (N--)
    {
        string name;
        cin >> name;
        cout << (uom.count(name) ? "yes" : "no") << '\n';
    }

    return 0;
}