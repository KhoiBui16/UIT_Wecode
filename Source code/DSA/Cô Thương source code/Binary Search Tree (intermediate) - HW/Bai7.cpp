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

Tree Search(Tree T, int x)
{
    Tree p = NULL;
    if (!T) return NULL;
    if (T->info == x) return T;
    p = Search(T->left, x);
    if (!p) p = Search(T->right, x);
    return p;
}

void SetLeft(Tree T, int x)
{
    if (!T) 
    {
        cout<<"Node khong ton tai\n";
        return;
    }
    if (T->left) 
    {
        cout << "Da co node con ben trai\n";
        return;
    }
    T->left = getNode(x);
}

void SetRight(Tree T, int x)
{
    if (!T) 
    {
        cout<<"Node khong ton tai\n";
        return;
    }
    if (T->right) 
    {
        cout << "Da co node con ben phai\n";
        return;
    }
    T->right = getNode(x);
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

bool checkBSTUltility(Tree T, Node*& p) {
    if (T) {
        if (!checkBSTUltility(T->left, p)) return false;
        if (p != NULL && T->info <= p->info) return false;
        p = T;
        return checkBSTUltility(T->right, p);
    }
    return true;
}

bool isBST(Tree T) {
    Node* p = NULL;
    return checkBSTUltility(T, p);
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
    if(isBST(T)) cout<<"\Cay vua tao la cay BST";
    else cout<<"\Cay vua tao khong phai la cay BST";

	return 0;
}
