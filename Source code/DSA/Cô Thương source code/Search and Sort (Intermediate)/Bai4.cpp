/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

void qs(int *a, int l, int r)
{
    int i = l, j = r;
    int m = a[(i+j)/2];
    while (i <= j)
    {
        while (a[i] < m) i++;
        while (a[j] > m) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j) qs(a, l, j);
    if (i < r) qs(a, i, r);
}

void sort(int *a, int n)
{
    int *b = new int[n], *c = new int[n];
    int curb = 0, curc = 0;
    for (int i=0; i<n; i++) 
    {
        if (a[i] % 2 == 0)
        {
            b[curb++] = a[i];
            c[curc++] = i;
        }
    }
    qs(b, 0, curb-1);
    int res = 0;
    for (int i=0; i<curc; i++) a[c[i]] = b[res++];
    delete[] b;
    delete[] c;
}

int main(){
    int *a, n; cin >> n;
    a = new int [n];



    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    sort(a, n);

    for(int i = 0; i < n; i ++){
        cout << a[i] << " ";
    }
}
