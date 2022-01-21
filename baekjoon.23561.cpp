/*https://www.acmicpc.net/problem/23561*/
// 전형적인 그리디 문제
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	vector <int> arr(3 * N); // 3N명의 대학생들이 참가
	for (int i = 0; i < 3 * N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end()); // 대학생들의 나이를 오름차순으로 정렬

	if (N == 1) cout << 0 << "\n"; // 참가한 대학생의 수가 3명일 경우 에너지 차이의 최소화는 똑같은 값끼리 빼는것이므로 0을 출력
	else cout << arr[N * 2 - 1] - arr[N] << "\n"; // 참가한 대학생 수가 3명을 넘어갈 경우 최소화한 에너지 차이는 (2,3),(3,5),(4,7) 씩 짝이지어진다.
	return 0;
}