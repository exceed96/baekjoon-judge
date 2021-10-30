/*https://www.acmicpc.net/problem/14241*/
// 단순한 정렬문제
// 제일 큰 숫자는 나중에 곱해주는게 최대값을 얻을수 있다.
// 오름차순으로 정렬한 후 반복문의 시작을 1부터 하여서 바로 앞의 원소와 계산을 해준다.
// 두 원소를 더 한 값은 i에 초기화해준다.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, sum = 0, score = 0;
	cin >> N;
	vector <int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	for (int i = 1; i < N; i++)
	{
		sum = arr[i] + arr[i - 1];
		score += arr[i] * arr[i - 1];
		arr[i] = sum;
	}
	cout << score << "\n";
	return 0;
}