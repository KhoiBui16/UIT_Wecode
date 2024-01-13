// Template's header, these lines will goes before your code

#include <iostream>

// Your code
using namespace std;
int reverse(int);

// Template's footer, These lines will goes after your code
int main() 
{
    int n;
    cin >> n;
    cout << reverse(n);
}

// Hàm để nghịch đảo một số nguyên bằng đệ quy
int reverse(int n)
{
    // Tạo một biến tĩnh để lưu trữ kết quả
    static int result = 0;
    // Điều kiện dừng: nếu n bằng 0, trả về kết quả
    if (n == 0)
        return result;
    // Đệ quy: nhân kết quả với 10 và cộng với chữ số cuối cùng của n
    result = result * 10 + n % 10;
    // Gọi lại hàm với n chia cho 10
    return reverse(n / 10);
} 