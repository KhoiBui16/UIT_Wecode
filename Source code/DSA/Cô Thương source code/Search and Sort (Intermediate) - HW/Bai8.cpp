/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

class Data{
private:
    int x;
    static int assignment_count;
    static int n;
public:

    friend ostream& operator<<(ostream &os, const Data& a);
    friend istream& operator>>(istream &os, Data& a)    ;
    static void set_n(int n){
        if (Data::n == 0) Data::n = n;
        else cout << "WRONG";
    }
    Data& operator=(const Data& a){
        assignment_count++;
        if (assignment_count > 3* Data::n){
            cout << "WRONG";
        }
        this->x = a.x;
        return *this;
    }

    bool operator<(const Data& a){
        return this->x < a.x;
    }
};
int Data::assignment_count = 0;
int Data::n = 0;

ostream& operator<<(ostream &os, const Data& a){
    return os << a.x;
}
istream& operator>>(istream &os, Data& a){
    return os >> a.x;
}


//###INSERT CODE HERE -
void select_sort(Data *A, int n)
{
    int mini = 0;
    for (int i=0; i<n-1; i++)
    {
        mini = i;
        for (int j=i+1; j<n; j++)
        {
            if (A[j] < A[mini]) mini = j;
        }
        swap(A[mini], A[i]);
    }
}



int main(){
    int n;
    cin >> n;
    Data::set_n(n);

    Data *A = new Data[n];
    for (int i = 0; i < n; i++){
        int x;
        cin >> A[i];
    }

    select_sort(A, n);

    for(int i = 0; i < n; i++){
        cout << A[i] << " " ;
    }
}
