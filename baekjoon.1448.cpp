/*https://www.acmicpc.net/problem/1448*/
// 그리디 문제
// 삼각형이 될 조건 가장 긴변의 길이가 다른 두변의 길이의 합보다 작아야 한다. a <= b + c

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, max = 0, sum = 0;
	cin >> N;

	vector <int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), greater<int>()); // 내림차순으로 정렬

	for (int i = 0; i < N - 2; i++)
	{
		if (arr[i] < arr[i + 1] + arr[i + 2])
		{
			sum = arr[i] + arr[i + 1] + arr[i + 2];
			if (sum > max)
			{
				max = sum;
			}
		}
	}
	
	if (max == 0)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << max << "\n";
	}
	return 0;
}