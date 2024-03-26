#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int x)
{
    int Left = 0, Right = n - 1;
    while (Left <= Right)
    {
        int Mid = Left + (Right - Left) / 2;
        if (arr[Mid] > x)
            Right = Mid - 1;
        else if (arr[Mid] < x)
            Left = Mid + 1;
        else
            return Mid;
    }
    return -1;
}

int CountStepFindElement(int arr[], int n, int x)
{
    int Left = 0, Right = n - 1;
    int count = 0;
    while (Left <= Right)
    {
        int Mid = Left + (Right - Left) / 2;
        if (arr[Mid] > x)
        {
            Right = Mid - 1;
            count++;
        }
        else if (arr[Mid] < x)
        {
            Left = Mid + 1;
            count++;
        }
        else
        {
            count++;
            break;
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    
    int arr[n];
    for (int& it : arr)
        cin >> it;

    int element;
    cin >> element;

    int res = BinarySearch(arr, n, element);
    int count = CountStepFindElement(arr, n, element);

    if (res != -1)
    {
        cout << res << endl;
        cout << count;
    }
    else
        cout << -1;

    return 0;
}

