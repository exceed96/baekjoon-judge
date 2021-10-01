/*https://www.acmicpc.net/problem/11170*/
#include <iostream>

using namespace std;

int main(void)
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, M, count = 0;
		cin >> N >> M;

		for (int i = N; i <= M; i++)
		{
			int number = i;
			while(1)
			{
				if (number % 10 == 0) // 나머지가 0 이면 count++
				{
					count++;
				}
				if (number / 10 == 0) // 몫이 0 이면 한자리수 이므로 break
				{
					break;
				}
				else // 한자리수가 아닐 경우 10으로 나눠줘서 반복
				{
					number /= 10;
				}
			}
		}
		cout << count << "\n";
	}
	return 0;
}