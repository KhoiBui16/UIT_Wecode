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
    if (!T) return;
    if (T->left) return;
    T->left = getNode(x);
}

void SetRight(Tree T, int x)
{
    if (!T) return;
    if (T->right) return;
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

void DeleteLeft(Tree T)
{
    if (!T)
    {
        cout<<"Node khong ton tai\n";
        return;
    }
    if (!T->left) 
    {
        cout << "Khong co node ben trai\n";
        return;
    }
    if (T->left->left || T->left->right) 
    {
        cout << "Khong la node la nen khong xoa duoc\n";
        return;
    }
    T->left = NULL;
}

void DeleteRight(Tree T)
{
    if (!T)
    {
        cout<<"Node khong ton tai\n";
        return;
    }
    if (!T->right)
    {
        cout << "Khong co node ben phai\n";
        return;
    }
    if (T->right->left || T->right->right) 
    {
        cout << "Khong la node la nen khong xoa duoc\n";
        return;
    }
    T->right = NULL;
}

int main()
{
	Tree T = NULL;
	int x,b,c; char a;
	cin>>x;	T=getNode(x); // tao nut goc
	while(true)
    {
        cin>>a; // Ky tu cho biet chen vao trai hay phai
        if(a!='L'&& a!='R') break;
        cin>>b>>c;
        if(a=='L') SetLeft(Search(T,b),c);
        else if (a=='R') SetRight(Search(T,b),c);

    }
	cout<<"LNR: "; LNR(T);
	cout<<"\nDelete some nodes:\n";
	string s;
	while(true)
    {
        cin>>s; // Chuoi cho biet xoa ben trai hay ben phai
        if(s!="DL"&& s!="DR") break;
        cin>>b;
        if(s=="DL") DeleteLeft(Search(T,b));
        else if(s=="DR") DeleteRight(Search(T,b));

    }
    cout<<"\nLNR: "; LNR(T);

	return 0;
}
