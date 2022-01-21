/*https://www.acmicpc.net/problem/2012*/
#include <iostream>
#include <vector>
#include <algorithm>
// 주어진 예상등수를 오름차순으로 정렬하여서 각각의 인덱스에 1을 더한값에 빼주면 된다.
// 최악의 경우를 생각하지 않는 그리디 정석 문제

using namespace std;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	long long count = 0;
	cin >> N;
	vector <long long> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	for (int i = 1; i <= N; i++)
	{
		count += abs(arr[i - 1] - i);
	}

	cout << count << "\n";
	return 0;
}