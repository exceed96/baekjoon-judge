/*https://www.acmicpc.net/problem/11006*/
#include <iostream>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		cout << M * 2 - N << " " << N - M << "\n";
	}
	return 0;
}