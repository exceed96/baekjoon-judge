/*https://www.acmicpc.net/problem/19698*/
#include <iostream>

using namespace std;

int main(void)
{
	int N, W, H, L;
	cin >> N >> W >> H >> L;

	int	result = (W / L) * (H / L); // 최대로 들어갈수 있는 소의 수
	if (result < N) // 최대로 들어갈 수가 N보다 작을경우 result 출력
	{
		cout << result << "\n";
	}
	else // N이 더 클 경우 N 출력
	{
		cout << N << "\n";
	}
	return 0;
}