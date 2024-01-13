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

// Your code
int reverse(int k)
{
    int rev = 0;

    for (int t = k; t > 0; t /= 10)
    {
        rev = rev * 10 + t % 10;
    }
    return rev;
}