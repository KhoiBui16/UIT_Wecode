/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<string>
#include<cstring>
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;


//###INSERT CODE HERE -

struct Stack
{
    char arr[MAX];
    int n;
};

void Init(Stack& S)
{
    S.n = 0;
}

bool isFull(Stack S)
{
    return S.n == MAX;
}

bool isEmpty(Stack S)
{
    return S.n == 0;
}

void Push(Stack& S, char c)
{
    if (isFull(S)) return;
    S.arr[S.n++] = c;
}

void Pop(Stack& S)
{
    if (isEmpty(S)) return;
    S.arr[S.n-1] = '0';
    S.n--;
}

char Top(Stack S)
{
    if (isEmpty(S)) return '0';
    return S.arr[S.n-1];
}

bool isValid(string s)
{
    Stack S;
    Init(S);
    for (int i=0; i<s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') Push(S, s[i]);
        else if (s[i] == ')')
        {
            if (Top(S) == '(') Pop(S);
            else return 0;
        }
        else if (s[i] == ']')
        {
            if (Top(S) == '[') Pop(S);
            else return 0;
        }
        else 
        {
            if (Top(S) == '{') Pop(S);
            else return 0;
        }
    }
    return isEmpty(S);
}

int main()
{
	string expr; cin>>expr;
	cout<< isValid(expr);

	return 0;
}



