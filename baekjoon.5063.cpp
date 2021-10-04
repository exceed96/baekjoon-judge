/*https://www.acmicpc.net/problem/5063*/
#include <iostream>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		long long r, e, c; // int의 범위를 넘어갈수 있으므로 long long선언
		cin >> r >> e >> c;

		if (r < e - c)
		{
			cout << "advertise" << "\n";
		}
		else
		{
			if (r == (e - c))
			{
				cout << "does not matter" << "\n";
			}
			else
			{
				cout << "do not advertise" << "\n";
			}
		}
	}
	return 0;
}