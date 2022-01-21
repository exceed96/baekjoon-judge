/*https://www.acmicpc.net/problem/4641*/
#include <iostream>
using namespace std;

int main(void)
{
	while (1)
	{
		int arr[14] = {}, i = 0, count = 0;
		while (1)
		{
			cin >> arr[i];
			if (!arr[i] || arr[i] == -1) // 0이거나 -1이면 무한루프 종료
			{
				break;
			}
			i++;
		}
		if (arr[i] == -1) // -1이면 무한루프 종료
		{
			break;
		}

		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < i; k++)
			{
				if (2 * arr[j] == arr[k]) // 이중루프를 통해서 2배인수 찾기
				{
					count++;
				}
			}
		}

		cout << count << "\n";
	}
	return 0;
}