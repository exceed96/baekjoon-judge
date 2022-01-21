/*https://www.acmicpc.net/problem/13164*/
// 그리디 문제
// 티셔츠 만드는 비용 최소로 하여서 출력해야한다.
// 최소로 하기 위해서는 원생들을 오름차순으로 정렬 하여서 해야 하지만 문제에서 주어진 조건에 원생들은 이미 키 순서대로 줄 세워져있다.
// 원생들의 키 차이를 arr2벡터에 저장하고 오름차순으로 정렬한 후 N-K만큼의 벡터 원소값을 더해주면
// 최소  티셔츠 비용이 나온다.
// 인접한 수들의 차이를 최소로 해야하고 그룹을 지을 때, 인접한 수들의 차이가 큰 곳을 그룹의 경계로 만들어야 하므로 구하는 값이 최소가 될 수 있다.
#include <iostream>
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
		if (i >= 1)
		{
			arr2.push_back(arr[i] - arr[i - 1]);
		}
	}
	sort(arr2.begin(), arr2.end());

	for (int i = 0; i < N - K; i++)
	{
		sum += arr2[i];
	}
	cout << sum << "\n";
	
	
	return 0;
}
