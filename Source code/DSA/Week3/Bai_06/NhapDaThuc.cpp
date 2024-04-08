/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};


//###INSERT CODE HERE -
void Nhap(DATHUC& F,double hso, int mu) 
{
	if (hso == 0)
		return;
	DONTHUC* newDonThuc = new DONTHUC(hso, mu);
	Node *p;
	p = new Node(newDonThuc);
	if (F.head == nullptr)
	{
		F.head = F.tail = p;
	}
	else 
	{
		F.tail->next = p;
		F.tail = p;
	}
}

void Xuat(const DATHUC& B) {
    Node* current = B.head;
    bool isFirstTerm = true;
	bool AllZero = true;
    
    while (current != nullptr)
	{
        if (current->data->heso != 0)
		{
			AllZero = false;
            if (!isFirstTerm)
			{
                if (current->data->heso > 0)
				{
                    cout << "+";
                }
				else
				{
                    cout << "-";
                }
            }
			else
			{
                if (current->data->heso < 0)
				{
                    cout << "-";
                }
            }

            if(abs(current->data->heso) != 1 || current->data->somu == 0)
			{
                cout << abs(current->data->heso);
            }

            if(current->data->somu > 0)
			{
                cout << "x";
            }

            if(current->data->somu > 1)
			{
                cout << "^" << current->data->somu;
            }

            isFirstTerm = false;
        }
        
        current = current->next;
    }
	if(AllZero == true)
	{
		cout << "0";
	}
	
}

double TinhDaThuc(DATHUC F, double x) {
    double res = 0;

    Node *tmp = F.head;
    while (tmp != nullptr) {
        res += (tmp->data->heso * pow(x, tmp->data->somu));
        tmp = tmp->next;
    }

	return res;
}

int main() {
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
        << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
