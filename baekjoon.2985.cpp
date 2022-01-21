/*https://www.acmicpc.net/problem/2985*/
#include <iostream>

using namespace std;

int main(void)
{
	int A, B, C;
	cin >> A >> B >> C;
	if (A + B == C)
	{
		cout << A << "+" << B << "=" << C;
	}
	else if (A - B == C)
	{
		cout << A << "-" << B << "=" << C;
	}
	else if (A * B == C)
	{
		cout << A << "*" << B << "=" << C;
	}
	else if (A / B == C)
	{
		cout << A << "/" << B << "=" << C;
	}
	else if (B + C == A)
	{
		cout << A << "=" << B << "+" << C;
	}
	else if (B - C == A)
	{
		cout << A << "=" << B << "-" << C;
	}
	else if (B * C == A)
	{
		cout << A << "=" << B << "*" << C;
	}
	else
	{
		cout << A << "=" << B << "/" << C;
	}

	return 0;
}