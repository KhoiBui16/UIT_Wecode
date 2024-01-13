/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
###End banned keyword*/
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

void Chuanhoa(char *s);
int main()
{
	char *s;
	s = new char[MAX];
	//gets(s);	//Nhap chuoi s	
	cin.getline(s,MAX-1);
	Chuanhoa(s);
	cout << s << endl;
	return 0;
}

//###INSERT CODE HERE -