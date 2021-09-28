/*https://www.acmicpc.net/problem/4299*/
#include <iostream>

using namespace std;

int main(void)
{
	int sum, min, a = 0;
	cin >> sum >> min;

	a = sum + min;

	if (a % 2 || sum < min) // 두 점수의 합이 홀수이거나 차가 합보다 크면 -1 출력
	{
		cout << "-1" << "\n";
	}
	else // 합과 차의 합을 2로 나눈게 득점 많이한팀, 2로 나눈값에서 차를 빼주면 득점 적게한 팀
	{
		cout << a / 2 << " " << a / 2 - min << "\n";
	}
	return 0;
}