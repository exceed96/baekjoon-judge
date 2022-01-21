#include <iostream>
#include <cmath>
// 0 -> 1, 1 -> 0 이 변하는 과정을 카운트하고 2로 나누어주면 같은숫자로 바꿔주는 최소 횟수가 나온다.
using namespace std;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	double count = 0;
	string S;
	cin >> S;

	for (int i = 1; i < S.length(); i++)
	{
		if (S[i - 1] != S[i]) //0 -> 1, 1 -> 0으로 변하면 count++
		{
			count++;
		}
	}

	cout << round(count / 2) << "\n"; // count에 / 2를 해주고 반올림을 해주면 답이 나온다.

	return 0;
}