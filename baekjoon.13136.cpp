/*https://www.acmicpc.net/problem/13136*/
#include <iostream>

using namespace std;

int main(void)
{
	int R, C, N;
	long long result = 0, result2 = 0;
	cin >> R >> C >> N;

	if (R % N == 0) result = R / N;	
	else result = R / N + 1;
	if (C % N == 0) result2 = C / N;
	else result2 = C / N + 1;

	cout << result * result2 << "\n";

	return 0;
}