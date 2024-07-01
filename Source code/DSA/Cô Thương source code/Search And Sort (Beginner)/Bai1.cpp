
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include <time.h>
using namespace std;
#define MIN -1000
#define MAX 1000

int isTotalOven(int *a, int n) // or (int a[], int n)
{
    for (int i=0;i<n;i++)
        if(a[i]%2!=0)
            return 0;
    return 1;
}
int isValidValue (int *a, int n) // or (int a[], int n)
{
    for (int i=0;i<n;i++)
        if (a[i]<2*MIN||a[i]>2*MAX)
            return 0;
    return 1;
}

void outputArray(int *a, int n)
{
    cout << "\nArray: ";
    for (int i=0; i<n; i++) cout << a[i] << " ";
}

int main()
{
//###INSERT CODE HERE -
    int n; cin >> n;
    int *a = new int[n];
    int x = MIN, y = MAX;
    srand(time(NULL));
    for (int i=0; i<n; i++) a[i] = 2*(x + rand()%(y-x+1));
    if(isTotalOven(a,n)==1) cout<<"Mang toan so chan"<<endl;
    if (isValidValue(a,n)==1) cout<<"Mang chua cac gia tri nam trong khoang ["<<2*MIN<<","<<2*MAX<<"]";
    outputArray(a, n);
    return 0;
}


