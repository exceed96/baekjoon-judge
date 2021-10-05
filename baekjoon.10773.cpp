#include <iostream>
#include <stack> //스택 구현

using namespace std;

stack <int> arr;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int K, sum = 0;
	cin >> K;
	while (K--)
	{
		int n;
		cin >> n;
		if (n)
		{
			arr.push(n);
			sum += n; //0이아닌 숫자일시 arr스택에 n을 추가 하고 sum에 n 더하기
		}
		else
		{
			sum -= arr.top(); // 0일시 arr스택 마지막으로 들어간 값을 빼주기
			arr.pop(); //마지막 원소 제거
		}
	}
	cout << sum << "\n";
	return 0;
}