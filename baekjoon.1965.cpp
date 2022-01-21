/*https://www.acmicpc.net/problem/1965*/
// BOJ 11055와 똑같은 유형의  DP문제
// 어떤한 수열이 주어졌을때 그 수열에서 가장 긴 증가하는 부분수열을 구하면 된다.
// 11055와 풀이가 똑같다.
#include <iostream>

using namespace std;

int arr[1001];
int arr2[1001];

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		arr2[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				arr2[i] = max(arr2[i], arr2[j] + 1);
			}
		}
	}

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		result = max(result, arr2[i]);
	}

	cout << result << "\n";
	return 0;
}