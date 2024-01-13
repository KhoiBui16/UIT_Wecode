/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
strlen
strcat
string
strcmp
strcpy
memmove
strstr
###End banned keyword*/

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 255

int myStrcmp(char s1[], char s2[]);

int main()
{
	char s1[MAX], s2[MAX];
	fgets(s1,MAX,stdin);
	fgets(s2,MAX,stdin);
	int kt = myStrcmp(s1, s2);
	cout << kt << endl;
	return 0;
}
//###INSERT CODE HERE -