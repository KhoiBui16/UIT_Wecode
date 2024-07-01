#include <iostream>

using namespace std;
//Goi y: SV co the viet cac ham sau

long long Factorial (int n); // tinh n!
int isFactorial (int n); // kiem tra n co phai la 1 so giai thua hay khong, nghia la co 1 con so i sao cho i!=n
int isTotalFactorial(int a[], int n); //kiem tra mang co phai chua toan so giai thua hay khong


void inputArray(int a[], int &n)
{
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
}

void outputArray(int a[], int n)
{
    for (int i=0; i<n; i++) cout << a[i] << " ";
}

long long Factorial(int n)
{
    long long fact[n+1];
    fact[0] = fact[1] = 1;
    for (int i=2; i<=n; i++)
    {
        fact[i] = fact[i-1]*i;
    }
    return fact[n];
}

int isFactorial(int n)
{
    for (int i=0; i<=100; i++)
    {
        if (Factorial(i) == n) return 1;
    }
}

int isTotalFactorial(int a[], int n)
{
    int cnt = 0;
    for (int i=0; i<n; i++)
    {
        if (isFactorial(a[i])) cnt++;
    }
    return cnt == n;
}

long long maxFactorial(int a[], int n)
{
    int maxn = (int)(-1e9);
    for (int i=0; i<n; i++)
    {
        if (isFactorial(a[i]) && maxn < a[i]) maxn = a[i];
    }
    return maxn;
}

int main()
{
    int n, a[100];
    inputArray(a,n);
    cout<<"Array:"<<endl;
    outputArray(a,n);
    cout<<endl;

    if (isTotalFactorial (a,n)==1)
    {
        cout <<"Mang toan so giai thua"<<endl;
        cout << "So giai thua lon nhat: "<<maxFactorial (a,n);
    }
    else cout<<"Mang khong phai chua toan cac so giai thua";

    return 0;
}
