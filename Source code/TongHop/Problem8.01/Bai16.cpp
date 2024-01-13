//Template's header, these lines will goes before your code
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

// Your code
int main()
{
	char s[MAX];
	cin.getline(s, MAX);
	bool check = false;
	for (int i = 0; i <= MAX - 1; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			check = true;
	}
	if (check == true)
		cout << "CHUOI KHONG HOP LE." << endl;
	else
		cout << s;
	return 0;
}
