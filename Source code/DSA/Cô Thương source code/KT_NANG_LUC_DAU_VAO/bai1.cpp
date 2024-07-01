#include <bits/stdc++.h>
#pragma GCC optimize("02")

using namespace std;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool isprime(int n)
{
    for (int i=2; i*i<=n; i++)
    {
        if (n%i==0) return 0;
    }
    return n>=2;
}

void inputArray(int a[], int n)
{
    for (int i=0; i<n; i++) cin >> a[i];
}

void outputArray(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
}

void filterPrimes(int a[], int na, int b[], int &nb, int m)
{
    nb = 0;
    for (int i=0; i<na; i++)
    {
        if (isprime(a[i])) b[nb++] = a[i];
    }
    if (nb == 0) cout << "Mang a khong chua so nguyen to" << endl;
    else
    {
        if (nb < m) cout << "Mang a khong co du " << m << " so nguyen to" << endl;
        else if (nb > m) nb = m;
    }
}

int main()
{
    int na, a[100],nb, b[100];
    cin>>na;
    inputArray(a,na);
    cout<<"Mang a:"<<endl;
    outputArray(a,na);
    cout<<endl;
    int m;cin>>m;
    filterPrimes(a,na,b,nb,m); //tao ra mang b bang cach tach m so nguyen to tu a
    cout<<"Mang b:"<<endl;
    outputArray(b,nb);

    return 0;
}
