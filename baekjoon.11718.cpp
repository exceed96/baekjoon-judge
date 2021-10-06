/*https://www.acmicpc.net/problem/11718*/
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	while (1)
	{
		string a;
		getline(cin, a); //공백을 받기 위하여 getline 호출
		if (a == "") //문자열을 입력하지 않을시 무한루프 종료
		{
			break;
		}
		cout << a << "\n";
	}
	return 0;
}