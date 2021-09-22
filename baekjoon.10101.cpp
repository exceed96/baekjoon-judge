/*https://www.acmicpc.net/problem/10101*/
#include <iostream>

using namespace std;

int main(void)
{
	int A, B, C;
	cin >> A >> B >> C;

	if (A + B + C != 180)
	{
		cout << "Error" << "\n";
	}
	else
	{
		if ((A == B) && (B == C))
		{
			cout << "Equilateral" << "\n";
		}
		else if ((A != B) && (B != C) && (A != C))
		{
			cout << "Scalene" << "\n";
		}
		else if((A == B && B != C) || (A == C && C != B) || (B == C && A != B))
		{
			cout << "Isosceles" << "\n";
		}
	}
	return 0;
}