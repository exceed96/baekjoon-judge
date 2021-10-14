/*https://www.acmicpc.net/problem/10866*/
//간단한 덱 구현 코드
#include <iostream>
#include <deque>

using namespace std;

deque <int> arr;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	while (N--)
	{
		string a;
		cin >> a;
		if (a == "push_back")
		{
			int n;
			cin >> n;
			arr.push_back(n);
		}
		else if (a == "push_front")
		{
			int n;
			cin >> n;
			arr.push_front(n);
		}
		else if (a == "pop_front")
		{
			if (!arr.empty())
			{
				cout << arr.front() << "\n";
				arr.pop_front();
			}
			else
			{
				cout << "-1" << "\n";
			}
		}
		else if (a == "pop_back")
		{
			if (!arr.empty())
			{
				cout << arr.back() << "\n";
				arr.pop_back();
			}
			else
			{
				cout << "-1" << "\n";
			}
		}
		else if (a == "size")
		{
			cout << arr.size() << "\n";
		}
		else if (a == "empty")
		{
			cout << arr.empty() << "\n";
		}
		else if (a == "front")
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
		else if(a == "back")
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
	}
	return 0;
}