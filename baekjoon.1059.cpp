#include <iostream>
#include <algorithm>

using namespace std;

int arr[50];

int main(void)
{
	int L, n, A = 0, B = 0, count = 0;
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		cin >> arr[i];
	}
	cin >> n;

	sort(arr, arr + L); //수가 오름차순으로 주어지는것이 아니므로 정렬을 통해서 오름차순으로 정렬

	for (int i = 0; i < L; i++) // n이 속한 구간을 찾아준다. 만약 배열의 크기가 1이고 n이 배열의 원소값보다 작으면
	{                           // 구간의 범위의 앞 숫자를 0으로 한다.
		if (n < arr[i])
		{
			if (i == 0)
			{
				A = 0;
				B = arr[i];
			}
			else
			{
				A = arr[i - 1];
				B = arr[i];
			}
			break;
		}
	}

	for (int j = A+1; j <= n; j++) // n의 조건과 좋은구간 조건이 성립하면 count에 1씩 증가
	{
		for (int k = n; k < B; k++)
		{
			count++;
		}
	}

	if (count == 0) // count가 0일시에는 0을 출력하게 하고 아닐시에는 count의 최종값에서 1을 빼준다. 
	{
		cout << "0" << "\n";
	}
	else
	{
		cout << count - 1 << "\n";
	}
	return 0;
}