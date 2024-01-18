/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
strlen
strcat
strcmp
strcpy
memmove
strstr
###End banned keyword*/

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

int myStrcmp(char s1[], char s2[]);
int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);
void StringReverse(char st[]);

int main()
{
	char s[MAX];
	fgets(s,MAX,stdin);
	if (myStrcmp(s, "") == 0)
		cout << "Chuoi rong." << endl;
	else
	{
		StringReverse(s);
		cout << s << endl;
	}
	return 0;
}

//###INSERT CODE HERE -

int myStrcmp(char s1[], char s2[])
{
    int i = 0;
    while (s1[i] != NULL && s2[i] != NULL)
    {
        if (s1[i] > s2[i])
            return 1;
        else if (s1[i] < s2[i])
            return -1;
        i++;
    }
    if (s1[i] == NULL && s2[i] == NULL)
        return 0;
    else if (s1[i] == NULL)
        return -1;
    else
        return 1;
}

int myStrlen(char s[], int k)
{
    int cnt = 0;
    for (int i = 0; s[i] != NULL; i++)
        cnt++;
    return cnt;
}

void myStrcpy(char s[], int vt, char s1[], int k)
{
    int i = 0;
    while (s1[i] != NULL)
    {
        s[vt] = s1[i];
        i++;
        vt++;
    }
    s[vt] = NULL;
}

void mySubstr(char s[], int b, int count, char ss[])
{
    int i = 0;
    while (i < count)
    {
        ss[i] = s[b];
        i++;
        b++;
    }
    ss[i] = NULL;
}

bool myStrcat(char s1[], char s2[])
{
    int i = 0;
    while (s1[i] != NULL)
        i++;
    int j = 0;
    while (s2[j] != NULL)
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = NULL;
    return true;
}

void StringReverse(char st[])
{
    int n = myStrlen(st, 0);
    char s[MAX];
    int i = 0;
    while (i < n)
    {
        mySubstr(st, i, 1, s);
        myStrcat(s, st);
        myStrcpy(st, 0, s, 0);
        i++;
    }
}
