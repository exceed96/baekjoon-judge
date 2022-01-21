/*https://www.acmicpc.net/problem/11004*/
#include <iostream>
#include <algorithm>
//sort를 사용하면 쉽게 풀수 있지만 데이터가 5000000개까지 가기 때문에 시간이 많이걸리는 코드
using namespace std;

int arr[5000001];

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr+N);
	
	cout << arr[K - 1] << "\n";
	return 0;
}