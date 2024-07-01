#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node *parent;
};
typedef struct Node *TREE;

Node* createNode(int x)
{
    Node *p;
    p = new Node;
    p->key = x;
    p->left = p->right = NULL;
    return p;
}

void insertNode(TREE& T, int x)
{
    if (T) {
        if (T->key == x)
            return;
        if (T->key > x)
            return insertNode(T->left, x);
        else
            return insertNode(T->right, x);
    }
    else T = createNode(x);
}

void inputTree(TREE& T)
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        insertNode(T, x);
    }
}

void traverseTree(TREE T, vector<int>& result)
{
    //* # insert your code here
    
}

int main()
{
    TREE T = NULL;
    inputTree(T);
    vector<int> result;
    traverseTree(T, result);
    sort(result.begin(), result.end());
    for (int it : result)
        cout << it << " ";
    return 0;
}