/*https://www.acmicpc.net/problem/17608*/
#include <iostream>
#include <stack>

using namespace std;

stack <int> arr;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N,s,count = 1;
	cin >> N;
	while (N--)
	{
		int h;
		cin >> h;
		arr.push(h); //각각의 높이를 순서대로 스택에 넣어준다
	}

	s = arr.top(); //맨 오른쪽 기둥의 높이를 s에 저장
	arr.pop(); //맨 오른쪽 기둥의 높이를 지워준다.

	while (!arr.empty()) //arr스택이 비어질때까지 무한루프
	{
		if (s < arr.top()) //arr스택의 top이 s보다 크면 count++
		{
			count++;
			s = arr.top(); // arr.top()을 새로운 기준으로 생성
			arr.pop(); // 새로운 기준이 된 높이를 지워준다.
		}
		else // arr스택의 top이 s보다 작으면 스택에서 지워준다.
		{
			arr.pop();
		}
	}
	cout << count << "\n";
	return 0;
}