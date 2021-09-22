/*https://www.acmicpc.net/problem/5532*/
#include <iostream>

using namespace std;

int main(void)
{
	int L, A, B, C, D, day1, day2, m;
	cin >> L >> A >> B >> C >> D;

	if (A % C != 0) day1 = A / C + 1;
	else day1 = A / C;

	if (B % D != 0) day2 = B / D + 1;
	else day2 = B / D;
	
	m = max(day1, day2);

	cout << L - m << "\n";
	return 0;
}