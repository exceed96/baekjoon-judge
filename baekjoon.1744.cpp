/*https://www.acmicpc.net/problem/1744*/
// 그리디 문제
// 합이 최대가 되게 하는 경우는 2이상 양수, 음수, 0, 1 4가지로 분류해서 계산해야 한다.
// 2이상 양수에서는 내림차순으로 정렬하여서 가능한 큰값 * 큰값이 나와야한다.
// 만약 양수의 갯수가 홀수일 경우에는 남은 1개를 그냥 더해준다.
// 음수에서는 오름차순으로 정렬하여서 절대값이 큰값끼리 곱해줘야한다.
// 만약 음수의 갯수가 홀수일 경우 0이 있는지 없는지를 판단하여서 있을경우는 곱하여서 0으로 만들고 아닐경우에는 그냥 더해준다.
// 1의 갯수는 있는 갯수만큼 더해주는것이 최대 값이 나온다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> arr;
vector <int> arr_n;

int main(void)
{
	bool c = false;
	int N, z_count = 0, o_count = 0, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		if (n > 1)
		{
			arr.push_back(n);
		}
		else if (n == 1)
		{
			o_count++;
		}
		else if (!n)
		{
			c = true;
		}
		else
		{
			arr_n.push_back(n);
		}
	}
	sort(arr.begin(), arr.end(), greater<int>());
	sort(arr_n.begin(), arr_n.end());

	for (int i = 0; i < arr.size(); i += 2)
	{
		if (i + 1 == arr.size())
		{
			sum += arr[i];
			break;
		}
		sum += arr[i] * arr[i + 1];
	}

	for (int i = 0; i < arr_n.size(); i += 2)
	{
		if (i + 1 == arr_n.size())
		{
			if (!c)
			{
				sum += arr_n[i];
				break;
			}
			else
			{
				continue;
			}
		}
		sum += arr_n[i] * arr_n[i + 1];
	}
	cout << sum + o_count << "\n";
	return 0;
}