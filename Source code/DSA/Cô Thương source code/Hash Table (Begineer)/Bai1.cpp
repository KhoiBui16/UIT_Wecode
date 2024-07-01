
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <math.h>

using namespace std;

//###INSERT CODE HERE -
int MAX = -1;

void inputArray(int a[], int &n)
{
    cin >> n;
    for (int i=0; i<n; i++) 
    {
        cin >> a[i];
        if (MAX < a[i]) MAX = a[i];
    }
}

void printArray(int a[], int n)
{
    for (int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;
}

void removeDups(int a[], int n)
{
    int *b = new int[MAX+1];
    for (int i=0; i<=MAX; i++) b[i] = 0;
    for (int i=0; i<n; i++) b[a[i]] = 1;
    for (int i=0; i<=MAX; i++)
    {
        if (b[i]) cout << i << " ";
    }
}

int main()
{
    int a[100],n;
    inputArray(a,n);

    // In mang ban dau
    printArray(a, n);

    /* Goi ham thuc hien xuat mang nhung chi xuat nhung gia tri xuat hien lan dau tien,
    *  khong xuat nhung gia tri bi lap lai/bi trung
    */


    cout << "After removing the duplicate elements:" << endl;

    removeDups(a, n);

    return 0;
}
