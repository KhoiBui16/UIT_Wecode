// Template's header, these lines will goes before your code
#include <iomanip>
#include <iostream>
#include <stdio.h>
using namespace std;

struct SinhVien {
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};

// Your code
#include <cstring>
// Hàm cstring duoc khai bao de su dung ham strlen
void Nhap(SinhVien& x)
{
    // ham strlen duoc dung de tinh do dai cua chuoi (dem ca khoang trang)
    // trong chuoi se co 1 ky tu \0 de bao hieu ket thuc chuoi
    if (fgets(x.MASV, 10, stdin) != NULL)
        // x.MASV[strlen(x.MASV) - 1] = '\0' de xoa ky tu \n
        x.MASV[strlen(x.MASV) - 1] = '\0';
    if (fgets(x.HoTen, 100, stdin) != NULL)
        // x.HoTen[strlen(x.HoTen) - 1] = '\0' de xoa ky tu \n
        x.HoTen[strlen(x.HoTen) - 1] = '\0';

    cin >> x.NgaySinh;
    cin >> x.GioiTinh;
    cin >> x.DiemToan;
    cin >> x.DiemLy;
    cin >> x.DiemHoa;
}

void Xuat(SinhVien x)
{
    x.DTB = (x.DiemToan + x.DiemLy + x.DiemHoa) / 3;
    cout << x.MASV << "	" << x.HoTen << "	" << x.NgaySinh << "	" << x.GioiTinh << "	" << x.DiemToan << "	" << x.DiemLy << "	" << x.DiemHoa << "	" << setprecision(3) << x.DTB;
}

// Template's footer, These lines will goes after your code
int main() {
    SinhVien A;
    Nhap(A);
    Xuat(A);
    return 0;
}
