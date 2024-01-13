
#include <iostream>
using namespace std;

void input(int &a)
{
	std::cin >> a;
}

int TongChuSo(int a)
{
	int s = 0;
	for (int t = a; t != 0; t /= 10)
		s += t % 10;
	return s;
}

int main()
{
	int a;
	input(a);
	cout << TongChuSo(a);
	return 0;
}
