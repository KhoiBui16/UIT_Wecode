/*
    Cắt bánh
    Vào dịp sinh nhật, An được mẹ mua cho một chiếc bánh kem có kích thước rất lớn. An muốn chia bánh cho mọi người cùng ăn nhưng lại theo phương pháp cắt bánh “ABC” mà cậu ấy mới học được trên mạng. 

    Phương pháp “ABC” như sau:

    Đầu tiên, lấy dao cắt 1 đường từ tâm bánh đến rìa vỏ bánh ở hướng 12 giờ.

    Sau đó, thực hiện liên tiếp N thao tác:

    Xoay bánh theo chiều kim đồng hồ X độ.

    Lấy dao cắt 1 đường từ tâm bánh đến rìa bánh ở hướng 12 giờ.

    Có tất cả N + 1 người tham dự vào sinh nhật của An (tính cả An) , vì thế An muốn chia chiếc bánh thành N + 1, bằng thực hiện liên tiếp N thao tác với mỗi lần xoay là 
    D
    i
    độ.

    An là nhân vật quan trọng trong buổi hôm nay nên cậu ấy muốn biết là sau quá trình cắt bánh này thì An có thể nhận phần bánh lớn nhất với góc bao nhiêu độ?

    Ví dụ: Có 5 người trong buổi tiệc sinh nhật của An. Để cắt bánh thì An phải thực hiện 4 thao tác với mỗi lần xoay với các độ là  [90, 180, 45, 195].  Sau quá trình cắt bánh thì phần lớn nhất mà An nhận được sẽ là phần 
    120
    o
    (hình dưới).

    Input:

    Dòng đầu tiên chứa số nguyên N 
    (
    1
    ≤
    N
    ≤
    359
    )
    là số các thao tác.

    Dòng tiếp theo chứa N số nguyên D1,D2,…,DN  (1≤Di≤359)
    là các độ xoay trong mỗi lần xoay.  

    Lưu ý:  Các bộ test luôn đảm bảo các nhát cắt bánh là phân biệt.

    Output:

    Một số nguyên là độ lớn của góc mà phần bánh lớn nhất An nhận được.

    Input
    4

    90 180 45 195

    Output
    120
*/

#include <iostream>
#include <cmath>
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

void Function(int[], int& n);

int main()
{
    int a[MAX];
    int n;
    Function(a, n);
    return 0;
}

void Function(int a[], int& n)
{
    cin >> n;
    vector<int> v;
    int sum = 0;
    v.push_back(0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        v.push_back(sum % 360);
    }
    sort(v.begin(), v.end());
    int res = 0;
    for (int i = 0; i < v.size() - 1; i++)
        res = max(res, v[i+1] - v[i]);
    res = max(res, 360 - v.back());
    cout << res << "\n";
}