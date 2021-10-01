/*https://www.acmicpc.net/problem/4101*/
#include <iostream>

using namespace std;

int main(void)
{
	while (1)
	{
		int A, B;
		cin >> A >> B;
		if (A == 0 && B == 0)
		{
			break;
		}
		if (A > B)
		{
			cout << "Yes" << "\n";
		}
		else
		{
			cout << "No" << "\n";
		}
	}
	return 0;
}