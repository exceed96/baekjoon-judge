/*https://www.acmicpc.net/problem/10707*/
#include <iostream>

using namespace std;

int main(void) //두 개의 수도회사의 수도요금을 다 구해서 더 낮은쪽을 출력
{
	int A, B, C, D, P, result1, result2;
	cin >> A >> B >> C >> D >> P;

	result1 = A * P;
	if (P <= C)
	{
		result2 = B;
	}
	else
	{
		result2 = B + (P - C) * D;
	}

	cout << min(result1, result2) << "\n";
	return 0;
}