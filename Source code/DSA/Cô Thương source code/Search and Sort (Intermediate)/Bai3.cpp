/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

void inputArray(int *a, int n)
{
    for (int i=0; i<n; i++) cin >> a[i];
}


/*void MergeSort(int *a, int l, int r)
{
    int *b = new int[1000001];
    if (l >= r) return;
    int m = (l+r)/2;
    MergeSort(a, l, m);
    MergeSort(a, m+1, r);
    int i = l, j = m+1;
    int cur = 0;
    while (i <= m || j <= r)
    {
        if (i > m) b[cur++] = a[j++];
        else if (j > r) b[cur++] = a[i++];
        else if (a[i] < a[j]) b[cur++] = a[i++];
        else b[cur++] = a[j++];
    }
    for (int i=0; i<cur; i++) a[l+i] = b[i];
    delete[] b;
}*/

void Merge(int *a, int l, int mid, int r)
{
    mid = (l + r) / 2;
    int *c = new int[r - l + 1];
    int i = l, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r)
    {
        if (a[i] < a[j]) c[k] = a[i++];
        else c[k] = a[j++];
        k++;
    }
    while (i <= mid) c[k++] = a[i++];
    while (j <= r) c[k++] = a[j++];
    for (int i=0; i<k; i++) a[l+i] = c[i];
    delete[] c;
}

void MergeSort(int *a, int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        MergeSort(a, l, mid);
        MergeSort(a, mid + 1, r);
        Merge(a, l, mid, r);
    }
}

void outputArray(int *a, int n)
{
    for (int i=0; i<n; i++) cout << a[i] << " ";
}

int binarySearch(int *a, int n, int l, int r, int x)
{
    while (l <= r)
    {
        int m = (l+r)/2;
        if (x == a[m]) return m;
        else if (x < a[m]) r = m-1;
        else l = m + 1;
    }
    return -1;
}

int main()
{
    int n; cin>>n;
    int *a = new int[n];
    inputArray(a,n);
    MergeSort(a,0,n-1);
    cout<<"Sorted Array: ";
    outputArray(a,n);// liet ke cac phan tu cach nhau boi 1 khoang cach

    cout<< "\nFind an element: ";
    int x; cin>>x;
    cout<<x<<endl;
    int result = binarySearch(a,n,0,n-1,x);
    if (result ==-1) cout<<x<<" is not found";
    else cout<<x<<" is found at the position " << result;

	return 0;
}

