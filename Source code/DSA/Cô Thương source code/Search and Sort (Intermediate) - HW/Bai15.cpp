/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

int calculateHIndex(int *citation, int n);

//###INSERT CODE HERE -

void qs(int *a, int l, int r)
{
	int i=l, j=r;
	int mid = a[(i+j)/2];
	while (i <= j)
	{
		while (a[i] > mid) i++;
		while (a[j] < mid) j--;
		if (i <= j) swap(a[i++], a[j--]);
	}
	if (l < j) qs(a, l, j);
	if (i < r) qs (a, i, r);
}

int calculateHIndex(int *citation, int n)
{
	qs(citation, 0, n-1);
	int ans = 0;
	for (int i=0; i<n; i++)
	{
		if (citation[i] > i) ans++;
	}
	return ans;
}


int main()
{
	int* citation;
	int n;
	int i;
	cin >> n;
	//cout << n << endl;
	citation = new int[n];
	for (i = 0; i < n; i++)
		cin >> citation[i];
	cout << calculateHIndex(citation, n);
	return 0;


}