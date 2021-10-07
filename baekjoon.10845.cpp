/*https://www.acmicpc.net/problem/10845*/
// [큐]에 관한 원리를 이해하는 기본적인 코드 
#include <iostream>
#include <queue>

using namespace std;

queue <int> arr;

void push_(int x)
{
	arr.push(x);
}

void pop_()
{
	if (!arr.empty())
	{
		cout << arr.front() << "\n";
		arr.pop();
	}
	else
	{
		cout << "-1" << "\n";
	}
}

void size_()
{
	cout << arr.size() << "\n";
}

void empty_()
{
	cout << arr.empty() << "\n";
}

void front_()
{
	if (!arr.empty())
	{
		cout << arr.front() << "\n";
	}
	else
	{
		cout << "-1" << "\n";
	}
}

void back_()
{
	if (!arr.empty())
	{
		cout << arr.back() << "\n";
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
		else if (a == "size")
		{
			size_();
		}
		else if (a == "empty")
		{
			empty_();
		}
		else if (a == "front")
		{
			front_();
		}
		else if (a == "back")
		{
			back_();
		}
	}
	return 0;
}