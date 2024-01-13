// Template's header, these lines will goes before your code
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXN 100

struct SinhVien {
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};

// Your code
void Nhap(SinhVien A[], int& n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        if (fgets(A[i].MASV, 10, stdin) != NULL)
            A[i].MASV[strlen(A[i].MASV) - 1] = '\0';
        if (fgets(A[i].HoTen, 100, stdin) != NULL)
            A[i].HoTen[strlen(A[i].HoTen) - 1] = '\0';
        cin >> A[i].NgaySinh;
        cin >> A[i].GioiTinh;
        cin >> A[i].DiemToan;
        cin >> A[i].DiemLy;
        cin >> A[i].DiemHoa;
    }
}

void Xuat(SinhVien A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i].DTB = (A[i].DiemToan + A[i].DiemLy + A[i].DiemHoa) / 3;
        cout << A[i].MASV << "	" << A[i].HoTen << "	" << A[i].NgaySinh << "	" << A[i].GioiTinh << "	" << A[i].DiemToan << "	" << A[i].DiemLy << "	" << A[i].DiemHoa << "	" << setprecision(3) << A[i].DTB << endl;
    }
}

void SapXepGiamTheoMASV(SinhVien A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            // strcmp(A[i].MASV, A[j].MASV) > 0 de sap xep giam dan
            // strcmp(A[i].MASV, A[j].MASV) < 0 de sap xep tang dan
            // strcmp(A[i].MASV, A[j].MASV) == 0 de sap xep bang nhau
            if (strcmp(A[i].MASV, A[j].MASV) < 0)
            {
                SinhVien temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
    }
}

// Template's footer, These lines will goes after your code
int main() {
    SinhVien A[MAXN];
    int n;
    Nhap(A, n);
    SapXepGiamTheoMASV(A, n);
    Xuat(A, n);
    return 0;
}
