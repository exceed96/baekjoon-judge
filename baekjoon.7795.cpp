/*https://www.acmicpc.net/problem/7795*/
// 이중루프라서 시간은 최대 O(20000 * 20000), 즉 1초를 넘긴다. 근데 이게 정답..??
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T;
	cin >> T;

	while (T--)
	{
		int N, M,count =0;
		cin >> N >> M;
		int* arr = new int[N];
		int* arr2 = new int[M];
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		for (int i = 0; i < M; i++)
		{
			cin >> arr2[i];
		}
		
		sort(arr, arr + N, greater<>());
		sort(arr2, arr2 + M, greater<>());

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[i] > arr2[j])
				{
					count += M - j;
					break;
				}
			}
		}
		cout << count << "\n";
	}
	return 0;
}