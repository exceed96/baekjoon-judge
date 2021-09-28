/*https://www.acmicpc.net/problem/16486*/
#include <iostream>
#define PI 3.141592

using namespace std;

int main(void)
{
	double d1, d2, result = 0;
	cin >> d1 >> d2;

	result = 2 * d1 + 2 * d2 * PI;

	cout.setf(ios::fixed);
	cout.precision(6);
	cout << result << "\n";
	return 0;
}