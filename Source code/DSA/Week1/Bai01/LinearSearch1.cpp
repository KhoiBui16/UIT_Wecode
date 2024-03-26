#include <iostream>
#include <vector>
using namespace std;

int LinearSearch1(vector<int> arr, int n, int x)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int LinearSearch2(vector<int> arr, int n, int x)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt++;
        if (arr[i] == x)
            break;
    }
    return cnt;
}

int LinearSearch3(vector<int> arr, int n, int x)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return (n - i - 1);
    return -1;
}

int LinearSearch4(vector<int> arr, int n, int x)
{
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        cnt++;
        if (arr[i] == x)
            break;
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& it : arr)
        cin >> it;

    int element;
    cin >> element;

    int res1 = LinearSearch1(arr, n, element);
    int res2 = LinearSearch2(arr, n, element);
    int res3 = LinearSearch3(arr, n, element);
    int res4 = LinearSearch4(arr, n, element);

    cout << res1 << endl;
    if (res1 != -1)
    {
        cout << res2 << endl;
        cout << res3 << endl;
        cout << res4 << endl;
    }
    
    return 0;
}