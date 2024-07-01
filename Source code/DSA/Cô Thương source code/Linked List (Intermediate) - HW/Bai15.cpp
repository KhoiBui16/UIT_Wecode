/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
[
]
define
include
###End banned keyword*/
#include<iostream>
#include <iomanip>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
};


struct Node{
	DONTHUC* data;
	Node* next;

};

typedef struct DATHUC{
	Node* head;
	Node* tail;
}List;


//###INSERT CODE HERE -

Node* getNode(double heso, int somu)
{
    Node *p = new Node;
    p->data = new DONTHUC;
    p->data->heso = heso;
    p->data->somu = somu;
    p->next = NULL;
    return p;
}

void Nhap(List& B)
{
    B.head = B.tail = NULL;
    int n; cin >> n;
    if (n == 0) return;
    for (int i=0; i<n; i++)
    {
        double x; int y; cin >> x >> y;
        Node *p = getNode(x, y);
        if (!B.head) B.head = B.tail = p;
        else
        {
            B.tail->next = p;
            B.tail = p;
        }
    }
}

void Nhap(List& B, double x, int y)
{
    Node *p = getNode(x, y);
    if (!B.head) B.head = B.tail = p;
    else
    {
        B.tail->next = p;
        B.tail = p;
    }
}

void Xuat(List B)
{
    if (!B.head)
    {
        cout << 0;
        return;
    }
    bool check = 0;
    Node *p = B.head;
    while (p)
    {
        double u = p->data->heso;
        int v = p->data->somu;
        p = p->next;
        if (u == 0.0) continue;
        if (!check) check = 1;
        else if (u > 0.0) cout << "+";
        if (u != 1 && u != -1) cout << u;
        else if (u == -1 && v != 0) cout << "-";
        else if (!v) cout << u;
        if (!v) continue;
        cout << "x";
        if (v == 1) continue;
        cout << "^" << v;
    }
    if (!check) cout << 0;
}

List Tong2DaThuc(List A, List B)
{
    List Sum;
    Sum.head = Sum.tail = NULL;
    Node *p = A.head, *q = B.head;
    while (p && q)
    {
        if (p->data->somu == q->data->somu)
        {
            Nhap(Sum, p->data->heso + q->data->heso, p->data->somu);
            p = p->next;
            q = q->next;
        }
        else if (p->data->somu > q->data->somu)
        {
            Nhap(Sum, p->data->heso, p->data->somu);
            p = p->next;
        }
        else
        {
            Nhap(Sum, q->data->heso, q->data->somu);
            q = q->next;
        }
    }
    while (p)
    {
        Nhap(Sum, p->data->heso, p->data->somu);
        p = p->next;
    }
    while (q)
    {
        Nhap(Sum, q->data->heso, q->data->somu);
        q = q->next;
    }
    return Sum;
}

int main() {
    DATHUC A, B;
    Nhap(A);
    Nhap(B);
    cout << "Da thuc A: "; Xuat(A);
    cout << "\nDa thuc B: "; Xuat(B);
    cout << "\nA+B = "; Xuat(Tong2DaThuc(A, B));
    return 0;
}
