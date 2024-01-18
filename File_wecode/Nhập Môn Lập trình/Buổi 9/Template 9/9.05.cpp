/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
strcat
strlen
define
###End banned keyword*/

#include <iostream>
#include <string.h>
using namespace std;
#define MAX 255

int myStrlen(char *s);
char* myStrcat(char *s1, char *s2);

int main()
{
	char *s1 = NULL, *s2 = NULL;
	s1 = new char[MAX];
	s2 = new char[MAX];
	//gets(s1);
	//gets(s2);
	cin.getline(s1, MAX-1);
	cin.getline(s2, MAX-1);	
	char *s = myStrcat(s1, s2);
	puts(s);
	return 0;
}

//###INSERT CODE HERE -