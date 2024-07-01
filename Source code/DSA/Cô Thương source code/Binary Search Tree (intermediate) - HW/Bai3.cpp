/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;

//###INSERT CODE HERE -

typedef struct PRODUCT
{
    int id, year, warranty;
    string name, type;
} Pro;

struct Node
{
    Pro info;
    Node *pLeft, *pRight;
};
typedef Node* Tree;

Node* getNode(Pro x)
{
    Node *p = new Node;
    p->info = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

Pro inputInfo()
{
    Pro x;
    cin >> x.id;
    cin.ignore();
    getline(cin, x.name);
    getline(cin, x.type);
    cin >> x.year >> x.warranty;
    return x;
}

void inputTreeNode(Tree &T, Pro x)
{
    if (T)
    {
        if (x.id < T->info.id) inputTreeNode(T->pLeft, x);
        else if (x.id > T->info.id) inputTreeNode(T->pRight, x);
    }
    else T = getNode(x);
}

void inputTree(Tree &T)
{
    int n; cin >> n;
    while (n--)
    {
        Pro x = inputInfo();
        inputTreeNode(T, x);
    }
}

void listProduct(Tree T, string type)
{
    if (T)
    {
        listProduct(T->pLeft, type);
        if (T->info.type == type) cout << T->info.id << "\t" << T->info.name << "\t" << T->info.type << "\t" \
                                       << T->info.year << "\t" << T->info.warranty << "\n";
        listProduct(T->pRight, type);
    }
}

int countProduct(Tree T, int year)
{
    if (!T) return 0;
    int count = 0;
    if (T->info.warranty > year) count = 1;
    return count + countProduct(T->pLeft, year) + countProduct(T->pRight, year);
}

int main()
{
    Tree T = NULL;
    inputTree(T);

    string type;  cin.ignore(); getline(cin,type);
    cout<<"List of products whose type is  "<<type<<": ";
    cout<<"\nID\tName\tType\tYear\tWarranty\n";
    listProduct(T,type);

    int year;cin>>year;
    cout<<"Number of products with more than "<<year<<" years of warranty: "<<countProduct(T,year)<<endl;


	return 0;
}

