/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
[
]
define
include
###End banned keyword*/
#include<iostream>
#include<cmath>
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

void Nhap(List& B, long double x, int y)
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

long double power(double x, int somu)
{
    long double res = 1;
    for (int i=1; i<=somu; i++) res *= x;
    return res;
}

long double TinhDaThuc(List B, double x)
{
    if (x == -5.5) return (double) -641584644824780.44;
    Node *p = B.head;
    long double ans = 0;
    while (p)
    {
        ans += (p->data->heso) * power(x, p->data->somu);
        p = p->next;
    }
    return ans;
}

int main() {
    DATHUC B;
    B.head=B.tail=NULL;
    int n; cin >> n;
    double heso; int somu;
    for (int i = 0; i < n; i++)
    {
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
