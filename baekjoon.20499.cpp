/*https://www.acmicpc.net/problem/20499*/
#include <iostream>

using namespace std;

int main(void)
{
	char a;
	int K, D, A;
	cin >> K >> a >> D >> a >> A;

	if (K + A < D || D == 0)
	{
		cout << "hasu" << "\n";
	}
	else
	{
		cout << "gosu" << "\n";
	}

	return 0;
}