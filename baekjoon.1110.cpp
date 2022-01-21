/*https://www.acmicpc.net/problem/1110*/
#include <iostream>

using namespace std;

int main(void)
{
	int N, number = 0, count = 0;
	cin >> N;
	number = N;

	while (1)
	{
		int sum = 0;
		if (N < 10) // N이 10 이하일때는 10을 곱해서 두자리 수로 만든다.
		{
			N = N * 10;
			sum = N / 10 + N % 10;
			N = (N / 10 * 10) + sum % 10; // 0X의 숫자를 만들지 말고 X0이므로  N % 10이 아니라 N / 10으로 한다.
			count++;
		}
		else
		{
			sum = N / 10 + N % 10;
			N = (N % 10 * 10) + sum % 10;
			count++;
		}
		if (number == N)
		{
			break;
		}
	}
	cout << count << "\n";
	return 0;
}