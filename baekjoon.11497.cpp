/*https://www.acmicpc.net/problem/11497*/
#include <iostream>
#include <vector>
#include <algorithm>
// 정규분포 형태를 만들면 난이도가 낮은 배열을 만들 수있다.
// 높이들을 오름차순으로 정렬해서 인덱스의 차이가 2씩 나는원소들 중 큰 원소를 작은 원소로 빼주면
// 구하고자 하는 난이도가 나온다. 그 중에 제일 큰 값이 벡터의 난이도이다.
using namespace std;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--)
	{
		int N, max = 0;
		cin >> N;
		vector <int> arr(N);

		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());

		for (int i = 0; i < N - 2; i++)
		{
			if (max < arr[i + 2] - arr[i])
			{
				max = arr[i + 2] - arr[i];
			}
		}
		cout << max << "\n";
	}
	return 0;
}