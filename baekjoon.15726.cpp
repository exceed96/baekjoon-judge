/*https://www.acmicpc.net/problem/15726*/
#include <iostream>

using namespace std;

int main(void)
{
	double A, B, C;
	cin >> A >> B >> C; 

	if ((A * B / C) > (A / B * C))
	{
		cout << int(A * B / C) << "\n"; // 소수점 아래를 버리기 위하여 double형을 int형으로 강제변환
	}
	else
	{	
		cout << int(A / B * C) << "\n";
	}
	return 0;
}