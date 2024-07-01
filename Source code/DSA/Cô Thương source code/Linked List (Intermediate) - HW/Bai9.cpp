/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
[
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

struct Node
{
    int info;
    Node *next;
};

struct List
{
    Node *head, *tail;
};

Node* getNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void init(List &L)
{
    L.head = L.tail = NULL;
}

void inputList(List &L, int n)
{
    for (int i=0; i<n; i++)
    {
        int x; cin >> x;
        Node *p = getNode(x);
        if (!L.head) L.head = L.tail = p;
        else
        {
            L.tail->next = p;
            L.tail = p;
        }
    }
}

void MySort(List &L)
{
    for (Node *p = L.head; p->next != NULL; p = p->next)
    {
        Node *min_node = p;
        for (Node *q = p->next; q != NULL; q = q->next)
        {
            if (q->info < min_node->info) min_node = q;
        }
        swap(p->info, min_node->info);
    }
}

void outputList(List L)
{
    if (!L.head) 
    {
        cout << "List is empty";
        return;
    }
    for (Node *p = L.head; p != NULL; p = p->next) cout << p->info << " ";
}

int MySearch(List L, int x)
{
    int res = -1, i = 0;
    for (Node *p = L.head; p != NULL; p = p->next)
    {
        if (p->info == x) 
        {
            res = i;
            break;
        }
        i++; 
    }
    return res;
}

int main()
{
    int n; cin>>n;
    List L;init (L);
    inputList(L,n);
    MySort(L);
    cout<<"Sorted List: ";
    outputList(L);// liet ke cac phan tu cach nhau boi 1 khoang cach

    cout<< "\nFind an element: ";
    int x; cin>>x;
    cout<<x<<endl;
    int result = MySearch(L,x);
    if (result ==-1) cout<<x<<" is not found";
    else cout<<x<<" is found at the position " << result;

	return 0;
}

