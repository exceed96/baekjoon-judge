/*https://www.acmicpc.net/problem/11659*/
// dp, 누적합문제
// 이중루프를 돌릴경우 시간복잡도는 O(MN)이므로 제한된 시간을 넘어가게된다.
// 그래서 입력을 받을때 누적된 합을 arr2를 저장함으로써 시간복잡도를 O(N)으로 줄일수 있다.
#include <iostream>
#include <vector>
using namespace std;

int arr2[100001];

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
	cin >> N >> M;

	vector <int> arr(N + 1);

	arr.push_back(0); //입력받는 배열앞에 0을 넣는다(누적합 구현하기 위하여)
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		arr2[i] = arr2[i - 1] + arr[i]; // 예를 들어서 배열이 5,4,3,2,1이라고 하면 누적합 배열에는 5,9,12,14,15가 들어간다.
	}

	while (M--)
	{
		int i, j;
		cin >> i >> j;
		cout << arr2[j] - arr2[i - 1] << "\n";
	}

	return 0;
}