/*https://www.acmicpc.net/problem/11055*/
// 11053과 같은 풀이인 dp문제
// 11053과 같은 풀이로 풀수 있다. 다만 여기서 추가된 조건은 합이 가장 큰것이므로
// arr2에 증가 부분 수열의 합을 각 원소마다 저장해주고 그중에 가장 큰값을 출력하면 된다.

#include <iostream>

using namespace std;

int arr[1001];
int arr2[1001];

int main(void)
{
	int N, m = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		arr2[i] = arr[i];
		for(int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				arr2[i] = max(arr2[j] + arr[i], arr2[i]);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		m = max(m, arr2[i]);
	}
	cout << m << "\n";
	return 0;

}