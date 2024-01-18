// Template's header, these lines will goes before your code
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

int myStrlen(char s[], int k); //Ham tra ve chieu dai chuoi s ke tu vi tri k
void myMemmove(char s[], int vt, int k); //Xoa k ky tu trong chuoi s, bat dau tu vi tri vt. 
int myStrstr(char s[], char s1[]); //Tim chuoi s1 trong chuoi s, neu tim thay tra ve vi tri s1[0] trong chuoi s, khong tin thay tra ve -1
void Chuanhoa(char s[]);

int main()
{
	char s[MAX];
	fgets(s, MAX, stdin);	//Nhap chuoi s	
	Chuanhoa(s);
	cout << s << endl;
	return 0;
}

// Your code

// không được dùng strlen
int myStrlen(char s[], int k)
{
	int i = k;
	while (s[i] != '\0')
		i++;
	return i - k;
}

// không được dùng memmove
void myMemmove(char s[], int vt, int k)
{
	int n = strlen(s);
	for (int i = vt; i < n; i++)
		s[i] = s[i + k];
	s[n - k] = '\0';
}

// không được dùng strstr

int myStrstr(char s[], char s1[])
{
	int n = strlen(s);
	int m = strlen(s1);
	for (int i = 0; i < n - m + 1; i++)
	{
		int j = 0;
		while (j < m && s[i + j] == s1[j])
			j++;
		if (j == m)
			return i;
	}
	return -1;
}

void Chuanhoa(char s[])
{
	int n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			myMemmove(s, i, 1);
			i--;
		}
	}
	if (s[0] == ' ')
		myMemmove(s, 0, 1);
	if (s[n - 1] == ' ')
		s[n - 1] = '\0';
}