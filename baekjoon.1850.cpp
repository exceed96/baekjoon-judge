/*https://www.acmicpc.net/problem/1850*/
#include <iostream>

using namespace std;
long long gcd(long long a, long long b)
{
	long long c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main(void)
{
	long long A, B;
	long long com = 0;
	cin >> A >> B;
	com = gcd(A, B);
	
	while (com--)
	{
		cout << 1;
	}
	return 0;
}