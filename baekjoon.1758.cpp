/*https://www.acmicpc.net/problem/1758*/
#include <iostream>
#include <algorithm>
#include <vector>
// 주어진 팁들을 내림차순으로 정렬(최대한의 이득을 얻기위하여) 하여서 
// 계산한 팁이 0 이상인것을 sum에 더해주면
// 강호가 받을 수 있는 최대 팁을 구할 수 있다.
using namespace std;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	int N;
	long long sum = 0;
	cin >> N;
	vector <long long> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), greater <long long> ());

	for (int i = 0; i < N; i++)
	{
		long long n = arr[i] - i;
		if (n > 0)
		{
			sum += n;
		}
	}
	cout << sum << "\n";

	return 0;
}