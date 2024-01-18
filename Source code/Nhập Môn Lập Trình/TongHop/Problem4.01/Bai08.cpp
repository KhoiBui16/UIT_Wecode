// Template's header, these lines will goes before your code

#include <iostream>
using namespace std;

// Your code
int Input();
int sum_even_divisor(int);

// Template's footer, These lines will goes after your code

int main() {
	int n;
	n = Input();
	cout << sum_even_divisor(n);
}

// Your code
int Input()
{
	int n;
	cin >> n;
	return n;
}

int sum_even_divisor(int n)
{
	int s = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (n % i == 0 && i % 2 == 0)
		{
			s += i;
			cnt++;
		}
	if (cnt == 0)
		return -1;
	else
		return s;
}	