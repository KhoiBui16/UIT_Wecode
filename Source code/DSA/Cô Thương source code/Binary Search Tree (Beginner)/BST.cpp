#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int info;
    Node *left, *right;
};

typedef Node* Tree;
// struct Tree
// {
//     Node* root; //disgusting
// };

Node* getNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}

void inputTree(Tree &T, int x) //(Node* T)
{
    if (T != NULL) 
    {
        if (x == T->info) cout << "Unavailable";
        else if (x < T->info) 
            inputTree(T->left, x);
        else 
            inputTree(T->right, x);
    }
    else //cây đang rỗng (hoặc T = NULL)
        T = getNode(x);
}

//Node - Left - Right method of output:
void outputNLR(Tree T)
{
    if (T) //(T == NULL) ? return;
    {
        //xuất root node
        cout << T->info << " ";
        //xuất hết nhánh trái
        outputNLR(T->left);
        //xuất hết nhánh phải
        outputNLR(T->right);
    }
}

//Right - Left - Node method of output:
void outputRLN(Tree T)
{
    if (T)
    {
        outputRLN(T->right);
        outputRLN(T->left);
        cout << T->info << " ";
    }
}

//Left - Right - Node method of output:
void outputLRN(Tree T)
{
    if (T)
    {
        outputLRN(T->left);
        outputLRN(T->right);
        cout << T->info << " ";
    }
}

//Left - Node - Right method of output:
void outputLNR(Tree T)
{
    if (T)
    {
        outputLNR(T->left);
        cout << T->info << " ";
        outputLNR(T->right);
    }
}

int main()
{
    Tree T = NULL;

}