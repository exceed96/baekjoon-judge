/*https://www.acmicpc.net/problem/1547*/
#include <iostream>

using namespace std;

int main(void)
{
	int T;
	cin >> T;

	int arr[3] = { 1, 0, 0 };

	while (T--)
	{
		int X, Y, temp = 0;
		cin >> X >> Y;
		temp = arr[X - 1];
		arr[X - 1] = arr[Y - 1];
		arr[Y - 1] = temp;
	}
	for (int i = 0; i < 3; i++)
	{
		if (arr[i])
		{
			cout << i + 1 << "\n";
		}
	}
	return 0;
}