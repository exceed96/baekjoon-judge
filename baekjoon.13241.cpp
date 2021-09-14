/*https://www.acmicpc.net/problem/13241*/
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

long long lcm(long long a, long long b, long long c)
{
	return a * b / c;
}

int main(void)
{
	long long A, B, com = 0,result = 0;
	cin >> A >> B;

	com = gcd(A, B);
	result = lcm(A, B, com);

	cout << result << "\n";
	return 0;
}