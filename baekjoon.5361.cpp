/*https://www.acmicpc.net/problem/5361*/
#include <iostream>

using namespace std;

int main(void)
{
	double arr[5] = { 350.34, 230.90, 190.55, 125.30, 180.90 };
	int T;
	cin >> T;
	while (T--)
	{
		double sum = 0;
		int A, B, C, D, E;
		cin >> A >> B >> C >> D >> E;
		sum = arr[0] * A + arr[1] * B + arr[2] * C + arr[3] * D + arr[4] * E;
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "$" << sum << "\n";
	}
	return 0;
}