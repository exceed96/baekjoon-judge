/*https://www.acmicpc.net/submit/2476*/
// sort로 구현할시 간단하게 할수 있다
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, m = 0;
	cin >> N;
	while (N--)
	{
		int arr[3] = {}, result = 0;
		for (int i = 0; i < 3; i++)
		{
			cin >> arr[i];
		}

		sort(arr, arr + 3);

		if (arr[0] == arr[1] && arr[1] == arr[2])
		{
			result = arr[0] * 1000 + 10000;
		}
		else if (arr[0] == arr[1] || arr[1] == arr[2])
		{
			result = arr[1] * 100 + 1000;
		}
		else
		{
			result = arr[2] * 100;
		}
		m = max(result, m);
	}

	cout << m << "\n";
	return 0;
}