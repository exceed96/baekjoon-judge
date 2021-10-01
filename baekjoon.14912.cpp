/*https://www.acmicpc.net/problem/14912*/
#include <iostream>

using namespace std;

int main(void)
{
	int n, d, count = 0;
	cin >> n >> d;

	for (int i = n; i >= 1; i--)
	{
		int number = i;
		while (1)
		{
			if ((number % 10) == d) // 10으로 나눈값이 d이면 count++
			{
				count++;
			}	
			if ((number / 10) == 0) // number가 한 자리 수일때는 10으로 나누면 0이므로 break
			{
				break;
			}
			else // 한 자리수가 아닐때는 10으로 나눠준다
			{
				number /= 10;
			}
		}
	}
	cout << count << "\n";
	return 0;
}