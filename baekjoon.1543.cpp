/*https://www.acmicpc.net/problem/1543*/
#include <iostream>
#include <string>
// a의 문자열을 앞에서부터 b문자열과 차례대로 비교하면서 b문자열 전체와 a문자열의 일부가 같으면
// count++을 해주고 그 부분만큼 반복문의 시작점을 다시 정해준다.
// 만약 다른 a의 문자열과 b의 문자열이 다르다면 시작점을 1 더해준다.
using namespace std;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	int count = 0;
	string a, b;
	getline(cin, a);
	getline(cin, b);

	if (a.length() < b.length()) // a문자열의 길이가 b문자열의 길이보다 짧으면 0을 출력하고 종료
	{
		cout << 0 << "\n";
		return 0;
	}

	for (int i = 0; i < a.length();) 
	{
		bool c = true;
		for (int j = 0; j < b.length(); j++)
		{
			if (a[i + j] != b[j]) // i는 0으로 고정된 상태에서 j값만 순차적으로 더해주면 순서대로 문자열 비교 가능
			{
				c = false; //틀릴경우 c를 false로 바꾼다.
				break;
			}
		}

		if (c) // b의 문자열과 다 같을경우
		{
			count++;
			i += b.length(); // 시작점을 b문자열의 size만큼 더해준 부분으로 기준을 다시 잡는다.
		}
		else // 틀릴경우에는 a 문자열의 시작점 1 더해준다.
		{
			i++;
		}
	}
	cout << count << "\n";
	return 0;
}