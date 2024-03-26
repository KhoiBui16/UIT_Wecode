#include <iostream>
#include <vector>
using namespace std;

int CountStepToFindElement(vector<int> arr, int n, int x)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            cnt++;
    if (cnt != 0)
        return cnt;
    else
        return -1;    
}

void FindElement(vector<int> arr, int n, int x)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt++;
        if (arr[i] == x)
        {
            cout << i << " " << cnt << endl;
        }
    }
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

    int res1 = CountStepToFindElement(arr, n, element);
    if (res1 != -1)
    {
        cout << res1 << endl;
        FindElement(arr, n, element);
    }
    else
    {
        cout << 0;
    }
    return 0;
}