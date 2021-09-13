#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main(void)
{
	int A1, A2, B1, B2, par = 0, chil = 0, com = 0;
	cin >> A1 >> B1 >> A2 >> B2;

	par = B1 * B2;
	chil = A1 * B2 + A2 * B1;

	if (par >= chil)
	{
		com = gcd(par, chil);
		cout << chil / com << " " << par / com << "\n";
	}
	else
	{
		com = gcd(chil, par);
		cout << chil / com << " " << par / com << "\n";
	}
	
	return 0;
}