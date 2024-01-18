#include <iostream>
using namespace std;


// Cách 2 dùng hàm có sẵn => s.erase(s.begin() + indx_begin, s.begin() + indx_end)

void deleteSubstring(char *str, int a, int b) 
{
    // count the numbers of elements in char array
    int n = 0;
    while (str[n] != '\0')
        n++;
    
    for (int i = a; i < n - b; i++) 
        str[i] = str[i + b];

    str[n - b] = '\0';
}

int main() {
    const int maxLength = 100001; // 100000 characters + 1 for null terminator
    char str[maxLength];
    int a, b;

    // Input
    cin >> str >> a >> b;

    // Call the function to delete substring
    deleteSubstring(str, a, b);

    // Output
    cout << str << std::endl;

    return 0;
}
