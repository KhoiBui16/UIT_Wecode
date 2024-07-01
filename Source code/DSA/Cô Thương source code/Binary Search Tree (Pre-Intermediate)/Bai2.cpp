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

Node *getNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}

void inputTreeNode(Tree &T, int x)
{
    if (!T)
    {
        T = getNode(x);
        return;
    }
    if (T->info > x) inputTreeNode(T->left, x);
    else if (T->info < x) inputTreeNode(T->right, x);
}

void inputTree(Tree &T)
{
    int n; cin >> n;
    while (n--)
    {
        int x; cin >> x;
        inputTreeNode(T, x);
    }
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

int countNodes(Tree T)
{
    if (!T) return 0;
    return 1 + countNodes(T->left) + countNodes(T->right);
}

int depth(Tree T)
{
    if (!T) return 0;
    return max(1 + depth(T->left), 1 + depth(T->right));
}

int depthOfTree(Tree T)
{
    int ans = 0;
    ans = max(ans, depth(T->left));
    ans = max(ans, depth(T->right));
    return ans;
}

void countEven(Tree T, int &cnt)
{
    if (!T) return;
    if (!(T->info % 2)) cnt++;
    countEven(T->left, cnt);
    countEven(T->right, cnt);
}

void countOdd(Tree T, int &cnt)
{
    if (!T) return;
    if (T->info % 2) cnt++;
    countOdd(T->left, cnt);
    countOdd(T->right, cnt);
}

int countPositive(Tree T)
{
    if (!T) return 0;
    return (T->info > 0) ? 1 + countPositive(T->left) + countPositive(T->right) : 0 + countPositive(T->left) + countPositive(T->right); 
}

int countNegative(Tree T)
{
    if (!T) return 0;
    return (T->info < 0) ? 1 + countNegative(T->left) + countNegative(T->right) : 0 + countNegative(T->left) + countNegative(T->right); 
}

bool isPrime(int x)
{
    for (int i=2; i*i<=x; i++) if (x%i==0) return 0;
    return x >= 2;
}

int countPrime(Tree T)
{
    if (!T) return 0;
    return (isPrime(T->info)) ? 1 + countPrime(T->left) + countPrime(T->right) : 0 + countPrime(T->left) + countPrime(T->right); 
}

void listPrime(Tree T)
{
    if (T)
    {
        if (isPrime(T->info)) cout << T->info << " ";
        listPrime(T->left);
        listPrime(T->right);
    }
}

int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<"LNR: "; LNR(T); cout<<endl;

	cout<<"Number of nodes: " << countNodes(T)<<endl;
    cout<<"Depth of Tree: "<<depthOfTree(T)<<endl;

    int count_even = 0, count_odd =0;
    countEven(T, count_even);countOdd(T, count_odd);
    cout<<"Number of even nodes: "<<count_even<<endl;
    cout<<"Number of odd nodes: "<<count_odd<<endl;

    cout<<"Number of positive nodes: "<<countPositive(T)<<endl;
    cout<<"Number of negative nodes: "<<countNegative(T)<<endl;

    cout<<"Number of prime nodes: "<<countPrime(T)<<endl;
    cout<<"Prime numbers: "; listPrime(T);



	return 0;
}
