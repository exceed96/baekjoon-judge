/*https://www.acmicpc.net/problem/3004*/
#include <iostream>

using namespace std;

int main(void)
{
	int N, row, col;
	cin >> N;

	row = N / 2 + 1;
	col = N - row + 2;

	cout << row * col << "\n";
	return 0;
}