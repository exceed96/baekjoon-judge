/*https://www.acmicpc.net/problem/4796*/
#include <iostream>

using namespace std;

int main(void)
{
	int count = 1;

	while (1)
	{
		int L, P, V;
		cin >> L >> P >> V;
		if (!L && !P && !V) // 셋 다 0일때 무한루프 종료
		{
			break;
		}
		// V/P*L,  L과 V % P중에 작은값을 더하면 이용하는 날의 최대날이 나온다. 
		cout << "Case " << count << ": " << (V / P * L) + min(L, V % P) << "\n";
		count++;
	}
	return 0;
}