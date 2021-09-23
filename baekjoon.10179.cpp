/*https://www.acmicpc.net/problem/10179*/
#include <iostream>

using namespace std;

int main(void)
{
	int T;
	double n;
	cin >> T;

	while (T--)
	{
		cin >> n;
		cout.precision(2); // 소수점 2자리까지 표현
		cout << fixed << "$" << n * 0.8 << "\n"; // fixed를 통하여 소수점을 고정시켜 표현
	}
	return 0;
}