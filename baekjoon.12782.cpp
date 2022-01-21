/*https://www.acmicpc.net/problem/12782*/
// 그리디문제
// 문제에서 요구하는 우정비트를 구하는 방법은 다음과 같다.
// 각 이진수의 각 자리에서 서로 다른것을 찾아서 카운트 해준다.
// 1,0 둘중에 하나를 정해서 각각 갯수를 카운트해주고 절대값을 취해서 빼준다.
// 그 다음에 위에서 구한 절대값을 구한 값에 서로 다른것을 찾아서 카운트해준값을 빼주고 2로 나눠주고 더하면 비트 우정지수가 나온다.
#include <iostream>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		string N, M;
		int c_z_1 = 0, c_z_2 = 0, c_d = 0, result = 0;
		cin >> N >> M;
		for (int i = 0; i < N.length(); i++)
		{
			if (N[i] != M[i]) c_d++; // 각 자리에서 서로 다른것이 나오면 c_d++
			if (N[i] == '0') c_z_1++; // N에서 0이 나오면 c_z_1++
			if (M[i] == '0') c_z_2++; // M에서 0이 나오면 c_z_2++
		}

		result = abs(c_z_1 - c_z_2)  + (c_d - abs(c_z_1 - c_z_2)) / 2;
		cout << result << "\n";
	}
	return 0;
}