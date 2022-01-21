/*https://www.acmicpc.net/problem/12931*/
// 그리디 문제
// 문제에 조건을 보면 배열에 있는 값 하나를 1 증가, 배열에 있는 모든 값을 두 배 이렇게 2가지 조건이 있다.
// 여기서 생각해야할 점은 원소들이 다 0인 배열에서 입력으로 주어진 배열로 가는것보다
// 입력으로 주어진 배열에서 원소를 다 0 으로 만드는것이 빠를 것이다.
// 만약 원소가 2의 배수가 아닐시 1을 빼주고 count를 1증가시키고 만약 다 2의 배수일시에는 전체적으로 2로 나눠주고 count에 1을 더해준다.

#include <iostream>
#include <vector>

using namespace std;

bool zero(vector <int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i])
		{
			return 0;
		}
	}
	return 1;
}

bool two(vector <int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] % 2)
		{
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	int N, count = 0;
	cin >> N;
	vector <int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	while(1)
	{
		for (int i = 0; i < N; i++)
		{
			if (arr[i] % 2)
			{
				arr[i] -= 1;
				count++;
			}
		}

		if (zero(arr))
		{
			break;
		}

		if (two(arr))
		{
			for (int i = 0; i < N; i++)
			{
				arr[i] /= 2;
			}
			count++;
		}
	}

	cout << count << "\n";
	return 0;
}


// 또 다른 풀이로는 원소 하나하나를 각각 0으로 만드는 방법을 찾은다음에 2로 나눴을때 가장 큰 횟수를 1을 뻇을시의 카운트에다가 더해주면 된다.
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, count = 0, result = 0;
	cin >> n;
	vector <int> arr(n);

	for (int i = 0; i < n; i++)
	{
		int count2 = 0;
		cin >> arr[i];
		while (arr[i])
		{
			if (arr[i] % 2)
			{
				arr[i] -= 1;
				count++;
			}
			else
			{
				arr[i] /= 2;
				count2++;
			}
		}
		result = max(result, count2);
	}
	cout << count + result << "\n";


	return 0;
}