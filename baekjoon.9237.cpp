/*https://www.acmicpc.net/problem/9237*/
#include <iostream>
#include <vector>
#include <algorithm>
// 자라는데 오래걸리는 나무를 먼저 심어야 한다. 그래야 최소의 일수를 구할 수 있다.
// 나무가 다 자라는데 걸리는 일수를 내림차순으로 정렬하여서 각각의 원소와 원소마다 해당하는
// 인덱스 값을 더해주고 1을 더해주면 나무가 다 자라는데 걸리는 시간이 구해진다.
// 총 일수를 구하고 거기다 1을 더해주면 이장님을 초대하는데 걸리는 날짜가 구해진다.
// 이장님은 나무가 다 자라고 다음날에 오는 것이므로 1을 더해주는 것이다.
using namespace std;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	int N, max_day = 0;
	cin >> N;
	vector <int> arr(N); 

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), greater<int>()); // 내림차순

	for (int i = 0; i < N; i++)
	{
		max_day = max(max_day, i + arr[i] + 1); // 계속해서 비교해주면서 최대값을 max_day에 저장
	}

	cout << max_day + 1 << "\n"; // 이장은 나무들이 다 자라고 다음날에 오므로 +1을 해준다.
	return 0;
}
