#include <iostream>
using namespace std;

void input(int a[], int &n, int m)
{
    int x; cin >> x;
    while (x != -1)
    {
        a[n++] = x;
        cin >> x;
    }
    cin >> m;
}

void output(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
}

void output2(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        if (a[i] != 0) cout << a[i] << " ";
    }
}

int main()
{
    int n = 0, m;
    int a[101];
    input(a, n, m);
    cout << "Before:";
    output(a, n);
    cout << endl;
    
    }
}
