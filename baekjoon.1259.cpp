/*https://www.acmicpc.net/problem/1259*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	while (1)
	{
		string a, b;
		cin >> a;
		if (a == "0") //0만 입력될 경우 break
		{
			break;
		}
		b = a; //b로 a의 문자열을 저장
		reverse(a.begin(), a.end()); //a를 뒤집는 코드

		if (a == b)
		{
			cout << "yes" << "\n";
		}
		else
		{
			cout << "no" << "\n";
		}
	}
	return 0;
}