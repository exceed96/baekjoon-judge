/*https://www.acmicpc.net/problem/14490*/
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	int c;
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
	int n, m;
	char a;
	cin >> n >> a >> m;
	
	cout << n / gcd(n, m) << ":" << m / gcd(n, m) << "\n";
	return 0;
}