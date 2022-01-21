/*https://www.acmicpc.net/problem/9012*/
#include <iostream>

using namespace std;


int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--)
	{
		string a;
		cin >> a;
		if (a.length() % 2) // 갯수가 홀수이면 VPS일수 없다.
		{
			cout << "NO" << "\n";
		}
		else
		{
			int count = 0;
			for (int i = 0; i < a.length() - 1; i++)
			{
				for (int j = i + 1; j < a.length(); j++)
				{
					if (a[j] == ')' && a[i] == '(') 
					{
						a[i] = '0'; // 짝이 생기면 0으로 초기화해서 중복 방지
						a[j] = '0';
						count++;
						break;
					}
				}
			}
			if (count * 2 == a.length()) // VPS면 count가 문자열 a의 길이에 반절이여야 한다.
			{
				cout << "YES" << "\n";
			}
			else
			{
				cout << "NO" << "\n";
			}
		}

	}
	return 0;
}