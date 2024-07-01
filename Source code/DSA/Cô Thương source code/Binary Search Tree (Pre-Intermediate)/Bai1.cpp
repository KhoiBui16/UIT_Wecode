/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct Node
{
    int info;
    Node *left, *right;
};
typedef Node* Tree;

Node* getNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}

Node *Search(Tree T, int x)
{
    Node *p = NULL;
    if (!T) return NULL;
    if (T->info == x) return T;
    p = Search(T->left, x);
    if (!p) p = Search(T->right, x);
    return p;
}

void SetLeft(Node *p, int c)
{
    if (!p) 
    {
        cout << "Node khong ton tai\n";
        return;
    }
    if (p->left) 
    {
        cout << "Da co node con ben trai\n";
        return;
    }
    p->left = getNode(c);
}

void SetRight(Node *p, int c)
{
    if (!p) 
    {
        cout << "Node khong ton tai\n";
        return;
    }
    if (p->right) 
    {
        cout << "Da co node con ben phai\n";
        return;
    }
    p->right = getNode(c);
}

void LNR(Tree T)
{
    if (T)
    {
        LNR(T->left);
        cout << T->info << " ";
        LNR(T->right);
    }
}       

int main()
{
	Tree T = NULL;
	int x,b,c; char a;
	cin>>x;	T=getNode(x); // tao nut goc
	while(true)
    {
        cin>>a; // Ky tu cho biet chen vao trai hay phai
        if(a!='L'&& a!='R') break; // Neu khong phai L hoac R thi ket thuc viec tao cay
        cin>>b>>c;
        if(a=='L') SetLeft(Search(T,b),c); // chen c vao ben trai b
        else if (a=='R') SetRight(Search(T,b),c); // chen c vao ben phai b
    }
	cout<<"\nLNR: "; LNR(T); cout<<endl;

	return 0;
}
