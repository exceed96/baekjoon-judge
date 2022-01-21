/*https://www.acmicpc.net/problem/1912*/
// dp문제
// 연속된 몇 개의 수를 선책해서 구할 수 있는 합 중 가장 큰 합을 구한다.
// 배열의 0번째 인덱스를 초기값으로 잡고 누적으로 더하여서 합이 가장 큰 연속된 구간을 찾는다.
// 만약 i번쨰에 더한값이 i번째의 값보다 작을경우에는 연속 된 시작점을 i번째로 바꿔준다.(가장 큰 합이 될 수 없다.)
// result에 값을 계속 저장해줌으로써 가장 큰 값을 출력한다. 

#include <iostream>

using namespace std;

int arr[100001];
int arr2[100001];

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int result = arr2[0] = arr[0];

	for (int i = 1; i < n; i++)
	{
		arr2[i] = max(arr[i], arr2[i - 1] + arr[i]); //arr[i]가 클경우 가장 큰 합이 될수 없으므로 i번째 값이 시작점이 된다.
		cout << arr2[i] << " ";
		result = max(arr2[i], result);
	}

	cout << result << "\n";
	return 0;
}