/*https://www.acmicpc.net/problem/10768*/
#include <iostream>

using namespace std;

int main(void)
{
	int M, D;
	cin >> M >> D;
	
	if (M > 2) // 2월 이후에는 After
	{
		cout << "After" << "\n";
	}
	else if(M < 2) // 2월 전에는 Befor
	{
		cout << "Before" << "\n";
	}
	else // 2월일때 일수를 따져서 After, Before, Special 구분
	{
		if (D > 18)
		{
			cout << "After" << "\n";
		}
		else if (D < 18)
		{
			cout << "Before" << "\n";
		}
		else
		{
			cout << "Special" << "\n";
		}
	}
	return 0;
}