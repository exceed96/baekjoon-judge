/*https://www.acmicpc.net/problem/11943*/
#include <iostream>

using namespace std;

int main(void)
{
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	
	if (B + C > A + D) //답이 될 경우는 A + D, B + C 2가지 경우중에 하나이므로 if문을 통해서 조건을 만든다.
	{
		cout << A + D << "\n";
	}
	else
	{
		cout << B + C << "\n";
	}

	return 0;
}