/*https://www.acmicpc.net/problem/11722*/
// BOJ 11055와 같은 논리의 DP문제
// 11055에서는 가장 긴 증가하는 부분 수열이였지만 이 문제에서는 가장 긴 감소하는 부분 수열이다.
// 결국 가장 긴 감소하는 부분수열이란 말은 배열은 거꾸로 뒤집으면 가장 긴 증가하는 부분수열을 찾으라는 것이다.
// 배열을 역순으로 해준다음에 배열에서 가장 긴 증가하는 부분 수열을 찾아주면 된다.

#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int arr2[1001];

int main(void)
{
	int N, result = 0;;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	reverse(arr, arr + N);

	for (int i = 0; i < N; i++)
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

	for (int i = 0; i < N; i++)
	{
		result = max(result, arr2[i]);
	}
	cout << result << "\n";
	return 0;
}