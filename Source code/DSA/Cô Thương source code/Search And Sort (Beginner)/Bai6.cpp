e/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;



//###INSERT CODE HERE -

int binarySearch2(int *a, int n, int x)
{
    if (x < a[0] || x > a[n-1]) return -1;
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = (l+r)/2;
        if (x == a[m]) 
        {
            while (x == a[m]) m++;
            return m-1; 
        }
        else if (x < a[m]) r = m - 1;
        else l = m + 1;
    }
    return -1;
}

void inputArray(int* &a, int &n)
{
    cin >> n;
    a = new int[n];
    for (int i=0; i<n; i++) cin >> a[i];
}

int main()
{
    int n, *a = NULL;
    inputArray(a,n); //Luu y van de tham chieu cho con tro a va n

    // nhap cac gia tri can tim, neu nhap -1 thi ket thuc viec tim kiem
    int x;
    while(1)
    {
        cin>>x;
        if(x==-1)break;
        cout<<binarySearch2(a,n,x)<<endl;

    }

    return 0;
}

