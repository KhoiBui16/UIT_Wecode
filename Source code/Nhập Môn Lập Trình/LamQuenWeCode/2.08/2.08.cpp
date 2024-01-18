#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float T;
	float L;
	float H;
	cin >> T >> L >> H;
	float DTB = (T + L + H) / 3;
	cout << "DTB = " << fixed << setprecision(2) << DTB << endl;

	if (DTB >= 9 && DTB <= 10)
		cout << "Loai: XUAT SAC";
	else if (DTB >= 8 && DTB < 9)
		cout << "Loai: GIOI";
	else if (DTB >= 7 && DTB < 8)
		cout << "Loai: KHA";
	else if (DTB >= 6 && DTB < 7)
		cout << "Loai: TB KHA";
	else if (DTB >= 5 && DTB < 6)
		cout << "Loai: TB";
	else if (DTB >= 4 && DTB < 5)
		cout << "Loai: YEU";
	else if (DTB < 4)
		cout << "Loai: KEM";
	return 0;
}