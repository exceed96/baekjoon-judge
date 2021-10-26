/*https://www.acmicpc.net/problem/11501*/
// 주가가 제일 높을때 팔고 다시 내려갈때 매수하면 된다.
// 즉 값이 반복문에서 원소의 값이 감소하는 부분이 있으면 그 부분에서는 다시 매수하는 코드를 짜면 된다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		long long sum = 0;
		cin >> N;
		vector <long long> arr(N);
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		reverse(arr.begin(), arr.end()); //벡터를 reverse해도 괜찮고 안하고 반복문을 끝에서부터 돌려도 상관없다.

		long long max = arr[0];

		for (int i = 1; i < N; i++)
		{
			if (max < arr[i]) //max보다 큰 값이 나올경우 기준을 바꿔준다. 즉 다시 매수
			{
				max = arr[i];
			}
			else //max보다 작을경우는 그 차이만큼 이득이므로 sum에 계속 이익을 더해준다
			{
				sum += max - arr[i];
			}
		}
		cout << sum << "\n";
	}

	return 0;
}