/*https://www.acmicpc.net/problem/20115*/
// 정렬을 이용한 그리디 문제

// 문제에서 요구하는 조건에 따라서 합쳐진 에너지 드링크의 양을 최대로 하려면 주어진 에너지 드링크의 양이 가장 큰것을 기준으로 삼아야 한다.
// 기준으로 삼은 드링크 외의 나머지 드링크들을 2로 나누어서 더해주면 에너지 드링크의 양이 최대가 된다.
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	vector <int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end()); // 오름차순 정렬
	double sum = arr[N - 1]; // 가장 양이 많은 드링크를 기준

	for (int i = 0; i < N - 1; i++)
	{
		sum += double(arr[i] / 2.0); // 2로 나눴을시 .5까지 계산하기 위하여 2.0으로 설정
	}

	cout << sum << "\n";
	return 0;
}