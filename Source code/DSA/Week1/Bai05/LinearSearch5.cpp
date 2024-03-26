#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int test;
    cin >> test;

    vector<long> list;
    while (test--)
    {
        int n;
        cin >> n;
        vector<long> arr(n);
        for (long& it : arr)
        {
            cin >> it;
        }
        sort(arr.begin(), arr.end());

        long TongTrong = 0;
        if (n == 0 || n == 1)
            TongTrong = 0;
        else if (n == 2 || n == 3)
            TongTrong = arr[n - 1] - arr[0];
        else
            TongTrong = (arr[n - 1] - arr[0]) + (arr[n - 2] - arr[1]);

        cout << TongTrong << endl;
    }

    return 0;
}