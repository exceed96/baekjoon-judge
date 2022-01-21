#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	while (1)
	{
		stack <char> arr;
		string a;
		getline(cin, a);//공백 없이 문자받기 위하여
		if (a == ".")
		{
			break;
		}
		for (int i = 0; i < a.length() - 1; i++) //.은 문자열로 안쳐주니 a의 크기-1까지로 범위 설정
		{
			if (a[i] == '(' || a[i] == '[') // (,[가 나올경우에는 stack에 넣어준다
			{
				arr.push(a[i]);
			}
			else if (a[i] == ')') // ')'가 나올경우 stack top에 '(' 이고 비어있는 칸이 아니라면 제거 해준다.
			{
				if (arr.size() && arr.top() == '(')
				{
					arr.pop();
				}
				else // 아닐경우 stack에 )을 추가
				{
					arr.push(a[i]);
				}
			}
			else if (a[i] == ']') // 25~42줄에 ')'와 같은 방식
			{
				if (arr.size() && arr.top() == '[')
				{
					arr.pop();
				}
				else
				{
					arr.push(a[i]);
				}
			}
		}
		if (!arr.empty()) //서로 짝지어질경우 stack은 비어있을 것이므로 yes를 출력 아니면 no출력
		{
			cout << "no" << "\n";
		}
		else
		{
			cout << "yes" << "\n";
		}
	}
	return 0;
}