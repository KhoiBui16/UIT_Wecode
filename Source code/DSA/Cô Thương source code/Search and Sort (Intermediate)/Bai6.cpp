/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nhapMang(vector<int> &a, int &n)
{
    cin >> n;
    for (int i=0; i<n; i++) 
    {
        int x; cin >> x;
        a.push_back(x);
    }
    /*
    a.resize(n);
    for (int i=0; i<n; i++) cin >> a[i];
    */
}

void xuatMang(vector<int> a, int n)
{
    cout << "Mang vua nhap:\n";
    for (int i=0; i<n; i++) cout << a[i] << " ";
    cout << "\n";
}

void soChan(vector<int> a, int n)
{
    int i, maxChan;
    for (i = 0; i < n; i++)
    {
        if (!(a[i]%2)) 
        {
            cout << endl << a[i] << " la so chan dau tien, co chi so " << i << " trong mang";
            maxChan = a[i]; 
            break;
        }
    }
    if (i == n)
    {
        cout << "\nMang khong co so chan";
        return;
    }
    for (int i=n-1; i >= 0; i--)
    {
        if (!(a[i]%2))
        {
            cout << endl << a[i] << " la so chan cuoi cung, co chi so " << i << " trong mang";
            break;
        }
    }
    for (int i=0; i<n; i++)
    {
        if (!(a[i]%2)) maxChan = max(maxChan, a[i]);
    }
    cout << "\nSo chan lon nhat: " << maxChan;
}

int main()
{
    int n;
    vector<int> a;
    nhapMang(a, n);
    xuatMang(a, n);
    soChan(a, n);
    return 0;
}