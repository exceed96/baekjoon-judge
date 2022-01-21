/*https://www.acmicpc.net/problem/10824*/
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string A, B, C, D; // 두 수를 합치기 위해서 문자열로 숫자를 입력받는다.
	cin >> A >> B >> C >> D;
	
	cout << stoll(A + B) + stoll(C + D) << "\n"; //문자열을 long long으로 바꿔줘서 더한다
	return 0;
}