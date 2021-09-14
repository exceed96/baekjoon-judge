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

long long lcm(long long a, long long b)
{
	return a * b / gcd(a,b);
}

int main(void)
{
	int n;
	long long a, b;
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		cout << lcm(a, b) << "\n";

	}
	return 0;
}