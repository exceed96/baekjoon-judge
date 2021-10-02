/*https://www.acmicpc.net/problem/2693*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int T;
	cin >> T;

	while (T--)
	{
		int arr[10];
		for (int i = 0; i < 10; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + 10);

		cout << arr[7] << "\n";
	}
	return 0;
}