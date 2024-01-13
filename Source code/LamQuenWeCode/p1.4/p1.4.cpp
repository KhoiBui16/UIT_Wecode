#include <iostream>
#include <iomanip>
using namespace std;

float ChuVi(float);
float DienTich(float);

int main()
{
	float a;
	cin >> a;
	cout << "Chu vi: " << fixed << setprecision(2) << ChuVi(a) << endl;
	cout << "Dien tich: " << fixed << setprecision(2) << DienTich(a);
	return 0;
}

float ChuVi(float a)
{
	return (a * 4);
}
float DienTich(float a)
{
	return(a * a);
}