#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct point
{
    long double x, y, z;
};

int n, m;

pair<int, int> searching(point *A, int n, point x)
{
    int l = 0, r = n-1;
    int cnt = 0;
    while (l <= r)
    {
        cnt++;
        int m = l + (r-l)/2;
        if (A[m].x < x.x || (A[m].x == x.x && A[m].y < x.y) || (A[m].x == x.x && A[m].y == x.y && A[m].z < x.z)) l = m+1;
        else if (A[m].x > x.x || (A[m].x == x.x && A[m].y > x.y) || (A[m].x == x.x && A[m].y == x.y && A[m].z > x.z)) r = m-1;
        else return {m, cnt};
    }
    return {-1, cnt};
}

int main()
{
    cin >> n;
    point *A = new point[n];
    for (int i=0; i<n; i++) cin >> A[i].x >> A[i].y >> A[i].z;
    cin >> m;
    point *p = new point[m];
    for (int i=0; i<m; i++) cin >> p[i].x >> p[i].y >> p[i].z;
    /*sort(A, A+n, [](const point a, const point b)
    {
        return (a.x == b.x && a.y == b.y) ? a.z < b.z : (a.x == b.x) ? a.y < b.y : a.x < b.x;
    });*/
    for (int i=0; i<m; i++)
    {
        pair<int, int> idx = searching(A, n, p[i]);
        if (idx.first != -1) cout << idx.second << "\n";
        else cout << "KHONG\n";
    }
    delete[] A, p;
}