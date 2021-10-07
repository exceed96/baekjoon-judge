/*https://www.acmicpc.net/problem/9325*/
#include <iostream>

using namespace std;

int main(void)
{
	int T; //테스트갯수
	cin >> T;
	while (T--)
	{
		int s,n,o,o2, sum = 0; // s = 자동차가격, n = 옵션의 갯수, o = 특정옵션 갯수, o2 = 특정옵션의 가격
		cin >> s >> n;
		sum += s;
		for (int i = 0; i < n; i++)
		{
			cin >> o >>o2;
			sum += o * o2;
		}
		cout << sum << "\n";
	}
	
	return 0;
}