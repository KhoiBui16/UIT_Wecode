#include <iostream>

using namespace std;

struct Ngay
{
	int Ngay;
	int Thang;
	int Nam;
};
typedef struct Ngay NGAY;

int KtNhuan(NGAY);
int SoNgayToiDaTrongThang(NGAY);
int SoNgayTrongNam(NGAY);
int SoThuTu(NGAY);
int TimNgay(NGAY, int, int);
int main()
{
	NGAY k;
	int x, y, i, j;
	cin >> x >> y >> i >> j;

	cout << TimNgay(k, i, j);
	return 0;
}

int KtNhuan(NGAY x)
{
	if ((x.Nam % 4 == 0 && x.Nam % 100 != 0) || x.Nam % 400 == 0)
		return 1;
	return 0;
}

int SoNgayToiDaTrongThang(NGAY x)
{
	int ngathang[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (KtNhuan(x))
		ngathang[1] = 29;
	return ngathang[x.Thang - 1];
}

int SoNgayToiDaTrongNam(NGAY x)
{
	if (KtNhuan(x))
		return 366;
	return 365;
}

int SoThuTu(NGAY x)
{
	int stt = 0;
	for (int i = 1; i <= x.Nam - 1; i++)
	{
		NGAY temp = { 1, 1, i };
		stt = stt + SoNgayToiDaTrongNam(temp);
	}
	return stt + SoNgayToiDaTrongThang(x);
}

int TimNgay(NGAY x, int i, int j)
{
		int stt = SoThuTu(x);
	stt = stt + i - 1;
	int nam = 1;
	while (stt > SoNgayToiDaTrongNam({ 1, 1, nam }))
	{
		stt = stt - SoNgayToiDaTrongNam({ 1, 1, nam });
		nam++;
	}
	int thang = 1;
	while (stt > SoNgayToiDaTrongThang({ 1, thang, nam }))
	{
		stt = stt - SoNgayToiDaTrongThang({ 1, thang, nam });
		thang++;
	}
	return stt;
}
