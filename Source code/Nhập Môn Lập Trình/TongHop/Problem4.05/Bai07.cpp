// Template's header, these lines will goes before your code
#include <iostream>

// Your code
void input(int&);
int TongChuSo(int);

// Template's footer, These lines will goes after your code
int main() 
{
    int a;
    input(a);
    std::cout << TongChuSo(a);
    return 0;
}

void input(int& a)
{
    std::cin >> a;
}
int TongChuSo(int a)
{
    int s = 0;
    for (int t = a; t > 0; t /= 10)
        s += t % 10;
    return s;
}