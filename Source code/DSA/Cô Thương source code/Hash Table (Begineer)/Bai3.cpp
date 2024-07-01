#include <bits/stdc++.h>
#define MAX 26

using namespace std;


void input(char a[], int n)
{
    for (int i=0; i<n; i++) cin >> a[i];
}

void Solve(char a[], int n)
{
    char *b = new char[MAX];
    for (int i=0; i<MAX; i++) b[i] = -1;
    for (int i=0; i<n; i++)
    {
        if (isalpha(a[i])) b[toupper(a[i])-'A'] = 1;
    }
    int cnt = 0;
    for (int i=0; i<MAX; i++) if (b[i] == 1) cnt++;
    cout << 26-cnt;
}

int main()
{
    int n; cin >> n;
    char a[1000];
    input(a, n);
    Solve(a, n);
}