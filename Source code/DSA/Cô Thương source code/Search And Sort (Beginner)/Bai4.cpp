/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

void inputArray(int* &a, int &n)
{
    cin >> n;
    int *b = new int[n];
    a = b;
    for (int i=0; i<n; i++) cin >> b[i];
}

void findElements(int *a, int n, int &m)
{
    cin >> m;
    while (m--)
    {
        int x; cin >> x;
        int idx = -1;
        for (int i=0; i<n; i++)
            if (a[i] == x)
            {
                idx = i;
                break;
            }
        cout << idx << endl;
    }
}

/*void outputArray(int *a, int n)
{
    cout << "\nArray: ";
    for (int i=0; i<n; i++) cout << a[i] << " ";
}*/

int main()
{
    int n,m;
    int *a=NULL;
    inputArray(a,n);
    findElements(a,n,m);
    //outputArray(a, n);
    return 0;
}
