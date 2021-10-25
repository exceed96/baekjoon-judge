/*https://www.acmicpc.net/problem/2847*/
// 맨 끝의 점수를 기준으로 바로 앞의 원소와 비교하면서 앞의 원소값이 클 경우 1씩 빼주면서 횟수에는 1을 더해주기
// 다만 한 기준에 대한 무한루프가 끝난다면 기준을 바꿔주는것을 생각해야한다.
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N, count = 0;
	cin >> N;
	vector <int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int s = arr[N - 1]; // 기준점을 벡터의 제일 끝 값으로 잡는다.

	for (int i = N - 2; i >= 0; i--) // 기준부터 차례대로 아래로 내려가면서	                             
	{                                // 앞의 원소가 뒤의 원소보다 클 경우 1 씩 빼주면서 count에 1을 더해준다.
		while(arr[i] >= s)
		{
			arr[i] -= 1;
			count++;
		}
		s = arr[i];
	}
	cout << count << "\n";
	return 0;
}
