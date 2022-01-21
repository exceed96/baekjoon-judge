/*https://www.acmicpc.net/problem/11508*/
#include <iostream>
#include <vector>
#include <algorithm>
// 유제품의 가격을 내림차순으로 정렬한후 sum에다가 모두 저장해준다.
// 그 후 유제품의 갯수를 3으로 나눠서 나머지가 나오면 그에 해당하는 인덱스의 유제품 가격들은 모두 사야하므로 가격에 포함
// i + 1 %  3 이 0 인 경우는 3개로 묶었을 시 제일 싼 가격의 유제품이므로 그 유제품은 sum에서 빼준다.
using namespace std;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, sum = 0;
	cin >> N;
	vector <int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr.begin(), arr.end(), greater<int>());

	for (int i = 0; i < N - N % 3; i++)
	{
		if ((i + 1) % 3 == 0)
		{
			sum -= arr[i];
		}
	}

	cout << sum << "\n";
	return 0;
}