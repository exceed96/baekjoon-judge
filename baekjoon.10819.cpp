/*https://www.acmicpc.net/problem/10819*/
// 브루트포스 문제
// N의 범위가 3~8즉 최대로 나올수 있는 범위가 6개밖에 안되므로 브루트포스 적용 가능
// next_permutation을 이용하여 순열을 하나씩 체크해보며 최댓값을 찾는다.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, result = 0;
	cin >> N;
	
	vector <int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	do
	{
		int sum = 0;
		for (int i = 0; i < N - 1; i++)
		{
			sum += abs(arr[i] - arr[i + 1]);
		}
		if (sum > result)
		{
			result = sum;
		}

	}while(next_permutation(arr.begin(), arr.end())); //사전순 순열이 끝날시 반복문 종료

	cout << result << "\n";
	return 0;
}