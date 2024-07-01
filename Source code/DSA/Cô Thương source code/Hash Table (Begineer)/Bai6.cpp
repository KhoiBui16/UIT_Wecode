/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
->
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
#define M 10		// M là số nút có trên bảng băm, đủ để chứa các nút nhập vào bảng băm
#define NULLKEY -1
using namespace std;

//###INSERT CODE HERE -

struct Hash
{
    int length, m;
    int *buckets;
};

void initHash(Hash &H)
{
    H.m = M;
    H.buckets = new int[H.m];
    for (int i=0; i<M; i++) H.buckets[i] = NULLKEY;
    H.length = 0;
}

int hashFunc(int x)
{
    return x % M;
}

void insertHash(Hash &H, int x)
{
    if (H.length == M) 
    {
        cout << "\nBang bam bi day, khong them duoc";
        return;
    }
    int i = hashFunc(x), n = 0;
    while (H.buckets[i] != -1 && n <= M) 
    {
        i++;
        if (i == M) i = 0;
    }
    H.buckets[i] = x;
    H.length++;
}

void traverseAllHash(Hash H)
{
    for (int i=0; i<M; i++) cout << H.buckets[i] << " ";
    delete[] H.buckets;
}

int main()
{
    Hash H;
    initHash(H);

    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;
        cout<<"\nInsert "<<x;
        insertHash(H,x); // them 1 gia tri du lieu vao bang bam
    }
    cout<<"\nCreated Hash:"<<endl;
    traverseAllHash(H);

    return 0;
}

