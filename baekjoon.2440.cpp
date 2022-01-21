/*https://www.acmicpc.net/problem/2440*/
#include <iostream>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) //N번만큼 줄을 만든다. EX)5면 5줄
	{
		for (int j = 1; j <= N - i; j++) // 한줄마다 N-i만큼의 별을 만든다.
		{
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}