/*https://www.acmicpc.net/problem/1065*/
#include <iostream>

using namespace std;

int main(void)
{
	int X, arr[3] = {};
	cin >> X;

	if (X < 100)
	{
		cout << X; // 100밑으로는 다 한수이다.
	}
	else // 100 위의 숫자는 각 자리수마다 배열에 저장해서 한수인지 아닌지 if문을 통해서 판별
	{
		int count = 99;
		for (int i = 100; i <= X; i++) 
		{
			arr[0] = i / 100;
			arr[1] = i / 10 % 10;
			arr[2] = i % 10;
			if (arr[2] - arr[1] == arr[1] - arr[0])
			{
				count++;
			}
		}
		cout << count << "\n";
	}

	return 0;
}