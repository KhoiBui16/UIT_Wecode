#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float a, b, c;
	cin >> a >> b >> c;
	float delta = pow(b, 2) - 4 * a * c;
	// kiem tra pt co nghiem kep hay la vo nghiem
	if (delta <= 0) 
	{
		if (delta == 0)
		{
			float x = -b / (2 * a);
			cout << "PT co nghiem kep: x1 = x2 = " << x;
		}
		else
			cout << "PTVN";
	}
	// Neu delta > 0 => PT co hai nghiem phan biet
	else
	{
		
		float x1 = (-b + sqrt(delta)) / (2 * a);
		float x2 = (-b - sqrt(delta)) / (2 * a);
		cout << "PT co hai nghiem phan biet:" << endl;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2;
	}

	return 0;
}
