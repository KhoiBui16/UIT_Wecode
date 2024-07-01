/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;
int main()
{
//###INSERT CODE HERE -
    int n; cin >> n;
    int *a = new int[n];
    for (int i=0; i<n; i++) cin >> a[i];
    int m; cin >> m;
    while (m--)
    {
        int x; cin >> x;
        int idx = -1;
        for (int i=0; i<n; i++)
        {
            if (a[i] == x) 
            {
                idx = i;
                break;
            }
        }
        cout << idx << endl;
    }
    return 0;
}
