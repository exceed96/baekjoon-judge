/*https://www.acmicpc.net/problem/2441*/
#include <iostream>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) // N만큼 줄을 만든다.
	{
		for (int j = 0; j < i; j++) // 범위만큼 공백을 먼저 생성
		{
			cout << " ";
		}
		for (int k = N - i; k > 0; k--) //N-i 만큼의 별을 생성 
		{
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}