/*https://www.acmicpc.net/problem/2212*/
// BOJ 13164와 논리가 같은 그리디 문제
// 13164와 같은 풀이의 문제이다 다만 이 문제에서의 차이점은
// 처음에 주어진 벡터가 오름차순으로 주어지지 않는 점이다. 그래서 주어진 벡터를 오름차순으로 정렬한 후
// 인접한 벡터원소끼리의 차이를 arr2벡터에 넣어줘야 한다.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, K, sum = 0;
	cin >> N >> K;
	vector <int> arr(N);
	vector <int> arr2;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	for (int i = 1; i < N; i++)
	{
		arr2.push_back(arr[i] - arr[i - 1]);
	}
	sort(arr2.begin(), arr2.end());

	for (int i = 0; i < N - K; i++)
	{
		sum += arr2[i];
	}
	cout << sum << "\n";
	
	
	return 0;
}