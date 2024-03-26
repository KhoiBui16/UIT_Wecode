#include <iostream>
#include <string>
#include <vector>
using namespace std;

int BinarySearch(vector<string> arr, int n, string str)
{
    int Left = 0, Right = n - 1;
    while (Left <= Right)
    {
        int Mid = Left + (Right - Left) / 2;
        if (arr[Mid] > str)
            Right = Mid - 1;
        else if (arr[Mid] < str)
            Left = Mid + 1;
        else
            return Mid;
    }
    return -1;
}

int CountStepFindElement(vector<string> arr, int n, string str)
{
    int Left = 0, Right = n - 1;
    int count = 0;
    while (Left <= Right)
    {
        count++;
        int Mid = Left + (Right - Left) / 2;
        if (arr[Mid] > str)
            Right = Mid - 1;
        else if (arr[Mid] < str)
            Left = Mid + 1;
        else
            break;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (string& it : arr)
        cin >> it;
    
    string element;
    cin >> element;

    int pos = BinarySearch(arr, n, element);
    int count = CountStepFindElement(arr, n, element);
    if (pos != -1)
    {
        cout << pos << endl;
        cout << count;
    }
    else
        cout << -1;
    return 0;
}