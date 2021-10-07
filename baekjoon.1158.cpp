/*https://www.acmicpc.net/problem/1158*/
#include <iostream>
#include <queue> //큐 구현을 위해 호출

using namespace std;

queue <int> arr;

int main(void)
{
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		arr.push(i); // arr큐에 1~N까지의 수를 순서대로 넣어준다
	}

	cout << "<";
	
	while (1)
	{
		if (arr.size() == 1) //  arr의 크기가 1이면 그 원소를 출력해주고 무한루프 break
		{
			cout << arr.front() << ">";
			arr.pop();
			break;
		}
		for (int i = 0; i < K - 1; i++) //EX) K = 3이면 앞의 두 원소를 추가해주고 중복하는 앞의 두 원소를 지워준다.
		{
			arr.push(arr.front());
			arr.pop();
		}
		cout << arr.front() << ", "; //K번째의 수를 출력
		arr.pop(); // 출력해준수는 제거해준다.
		// 이렇게 해주면 원소를 하나씩 줄여주면서 요세푸스조건에 맞는 수를 출력 가능
		// BUT 크기가 커진다면 시간이 오래걸리는게 단점
	}
	return 0;
}
