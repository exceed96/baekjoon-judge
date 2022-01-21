/*https://www.acmicpc.net/problem/2476*/
// 너무 어렵게 풀었다. sort로 정렬해주면 더 간단한 코드로 구현 가능
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, max = 0;
	cin >> N;
	while (N--)
	{
		int arr[3] = {}, result = 0;
		for (int i = 0; i < 3; i++)
		{
			cin >> arr[i];
		}

		if (arr[0] == arr[1] && arr[1] == arr[2] && arr[0] == arr[2])
		{
			result = arr[0] * 1000 + 10000;
		}
		else if (arr[0] == arr[1] && arr[1] != arr[2] && arr[0] != arr[2])
		{
			result = arr[1] * 100 + 1000;
		}
		else if (arr[0] == arr[2] && arr[1] != arr[2] && arr[0] != arr[1])
		{
			result = arr[0] * 100 + 1000;
		}
		else if (arr[1] == arr[2] && arr[0] != arr[1] && arr[0] != arr[2])
		{
			result = arr[1] * 100 + 1000;
		}
		else result = *max_element(arr, arr + 3) * 100;

		if (result > max)
		{
			max = result;
		}
	}

	cout << max << "\n";
	return 0;
}