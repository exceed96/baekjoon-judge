/*https://www.acmicpc.net/problem/11721*/
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string a;
	cin >> a;
	for (int i = 0; i < a.length(); i++)
	{
		if (i % 10 == 0 && i != 0) //문자열의 인덱스가 0이 아니고 10으로 나눠지면 \n
		{
			cout << "\n";
		}
		cout << a[i];
	}
	return 0;
}