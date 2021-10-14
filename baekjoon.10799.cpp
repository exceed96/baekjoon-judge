/*https://www.acmicpc.net/problem/10799*/
#include <iostream>
#include <stack> //스택 구현

using namespace std;

stack <int> arr;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int count = 0;
	string a; //문자열로 괄호를 입력
	cin >> a;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == '(') // '('일시 stack에 넣어준다
		{
			arr.push(a[i]);
		}
		else
		{
			// ')'일시 ()짝이 나온것이므로 지워준다. 그리고 두 가지 경우로 나뉜다
			arr.pop();
			if (a[i - 1] == '(') // 바로 앞의 문자가 '('일 경우 레이져 이므로 스택에 쌓여있는 '('만큼 더해준다.(그림보면 이해 가능)
			{
				count += arr.size();
			}
			else //')'일시 1을 더해준다.
			{
				count += 1;
			}
		}
	}
	cout << count << "\n";
	return 0;
}