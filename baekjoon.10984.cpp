/*https://www.acmicpc.net/problem/10984*/
#include <iostream>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, sum = 0;
		double sum2 = 0;
		cin >> N;
		while (N--)
		{
			int score;
			double score2;
			cin >> score >> score2;
			sum += score;
			sum2 += score * score2;
		}
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << sum << " " << sum2 / sum << "\n";
	}
	return 0;
}