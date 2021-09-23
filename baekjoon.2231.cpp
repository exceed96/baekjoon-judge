/*https://www.acmicpc.net/problem/2231*/
#include <iostream>
#define NUMBER 1000000

using namespace std;

int main(void)
{
	int N, N2, result = 0;
	cin >> N;

	for (int i = 1; i <= NUMBER; i++) //1부터 NUMBER까지의 숫자까지 그때그떄의 i 값과  i의각자리수를 더해서 
	{                                 // sum과 N이 같은지를 비교해서 같으면 result에 i를 저장
		int sum = 0;
		N2 = i;
		sum += i;
		while (1)
		{
			sum += N2 % 10;
			if ((N2 / 10) == 0)
			{
				break;
			}
			N2 = N2 / 10;
		}
		if (sum == N)
		{
			result = i;
			break;
		}
	}

	if (!result) // result가 0일시에는 해당하는 생성자가 없다는 것이므로 0을 출력
	{
		cout << "0" << "\n";
	}
	else
	{
		cout << result << "\n";
	}
	return 0;
}