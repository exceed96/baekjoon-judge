/*https://www.acmicpc.net/problem/19944*/
#include <iostream>

using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;

	if (N >= M)
	{
		if (M == 1 || M == 2)
		{
			cout << "NEWBIE!" << "\n";
		}
		else
		{
			cout << "OLDBIE!" << "\n";
		}
	}
	else
	{
		cout << "TLE!" << "\n";
	}
	return 0;
}