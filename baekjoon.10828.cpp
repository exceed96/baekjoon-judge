#include <iostream>
#include <stack> //스택 구현하기 위해 stack 

using namespace std;

stack <int> arr;

void push_(int x) //입력받을시 arr스택에 push
{
	arr.push(x);
}

void pop_() //지울시 지워지는 top부분을 보여주고 지우는 코드
{
	if (arr.size())
	{
		cout << arr.top() << "\n";
		arr.pop();
	}
	else
	{
		cout << "-1" << "\n";
	}
}

void size_() // arr스택에 사이즈를 반환
{
	cout << arr.size() << "\n";
}

void empty_() //arr스택이 있을시 크기는 0보다 크므로 0을출력 없을시  1출력
{
	if (arr.size())
	{
		cout << "0" << "\n";
	}
	else
	{
		cout << "1" << "\n";
	}
}

void top_() //arr스택에 원소가 있을시 맨 나중에 입력된 원소 출력
{
	if (arr.size())
	{
		cout << arr.top() << "\n";
	}
	else
	{
		cout << "-1" << "\n";
	}
}
int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	while (N--)
	{
		string a;
		cin >> a;
		if (a == "push")
		{
			int n;
			cin >> n;
			push_(n);
		}
		else if (a == "pop")
		{
			pop_();
		}
		else if (a == "empty")
		{
			empty_();
		}
		else if (a == "size")
		{
			size_();
		}
		else
		{
			top_();
		}
	}
	return 0;
}