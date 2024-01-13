#include <iostream>
using namespace std;

int a[256] = {0};

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++)
        a[s[i]]++;

    for (int i = 0; i < 256; i++)
        if (a[i] != 0)
            cout << (char)i << ": " << a[i] << endl;

    return 0;
}