/*
Trò chơi của An
Trò chơi Flappy Bird đã trở thành một hiện tượng toàn cầu, với cơ chế điều khiển đơn giản nhưng những thách thức mà trò chơi tạo ra rất ức chế. Trong trò chơi, mục tiêu của người chơi là hướng dẫn một chú chim bay qua một loạt các cột đứng (cột dài vô tận) , mỗi cây cột đứng thứ i đều có vị trí khoét lỗ từ vị trí có chiều cao 
a
i
 đến 
b
i
 (tính từ mặt đất). An đang muốn thực hiện lại trò chơi này, nhưng khổ nỗi là tính năng trò chơi của An vẫn chưa đầy đủ (không thể điều khiển chú chim lên xuống như trò chơi gốc) mà tính năng chỉ là chọn vị trí bắt đầu (vị trí nguyên) của chú chim, sau đó là chú chim sẽ bay theo đường thẳng. Nếu chú chim bay qua tất cả N cột mà không chạm vào cột nào thì sẽ là một lần chơi thắng.

An tự hỏi không biết có bao nhiêu vị trí bắt đầu mà để thắng trò chơi này. Bạn hay giúp An trả lời câu hỏi nhé!

Input: 

Dòng đầu tiên chứa số nguyên N (1≤N≤105) là số lượng cột trong trò chơi.

Dòng tiếp theo chứa N số nguyên a1,a2,…,aN vớiai (1≤ai≤109) là vị trí bị khoét thấp nhất của cây cột thứ i

Dòng cuối cùng chứa N số nguyên b1,b2,…,bN vớibi (1≤bi≤109) là vị trí bị khoét cao nhất của cây cột thứ i.

Ouput:

Số lượng vị trí có thể thắng trong trò chơi này.

Input
3

3 2 5

6 9 8

Output
2

Giải thích:

Có 2 vị trí có thể thắng trong trò chơi này chính là vị trí 5 và vị trí 6.
*/

#include <iostream>
using namespace std;

long long MaxArrA(long long*, int);
long long MinArrB(long long*, int);
long long SoLuongViTriThang(long long, long long);
const long long MAX = 1000000;

int main()
{
    // n: so luong cot
    int n;
    cin >> n;
    long long *a = new long long[n];
    long long *b = new long long[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    long long MaxA = MaxArrA(a, n);
    long long MinB = MinArrB(b, n);
    long long kq = SoLuongViTriThang(0, MinB - MaxA + 1);
    cout << kq;

    delete[] a;
    delete[] b;
    return 0;
}

long long MaxArrA(long long* a, int n)
{
    long long max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

long long MinArrB(long long* b, int n)
{
    long long min = b[0];
    for (int i = 1; i < n; i++)
        if (b[i] < min)
            min = b[i];
    return min;
}

long long SoLuongViTriThang(long long a, long long b)
{
    long long result = 0;
    if (a > b)
        result = a;
    else
        result = b;
    return result;
}
