/*https://www.acmicpc.net/problem/10539*/
#include <iostream>

using namespace std;

int arr[101];

int main(void)
{
	int N,sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i]; // 수열B의 N개만큼 입력을 받는다.
	}

	for (int i = 0; i < N; i++)
	{
		if (i == 0) // A의 0번째원소랑 B의 0번째 원소는 같다
		{
			cout << arr[0] << " ";
			sum += arr[0]; 
		}
		// A의 i번째 원소를 구하는 공식에는 (SUM + x) / (i+1) = arr[i] 이므로
		// x = arr[i] * (i + 1) - sum 이다.
		else
		{
			cout << arr[i]*(i+1) - sum << " ";
			sum += (arr[i]*(i+1) - sum);
		}
	}
	return 0;
}