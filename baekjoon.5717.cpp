/*https://www.acmicpc.net/problem/5717*/
#include <iostream>

using namespace std;

int main(void)
{
	while (1)
	{
		int M, F;
		cin >> M >> F;
		if (!M && !F)
		{
			break;
		}
		cout << M + F << "\n";
	}
	return 0;
}