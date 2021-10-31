/*https://www.acmicpc.net/problem/17497*/
// 그리디 문제
// K부터 0까지 가는 과정을 구해서 기능들을 벡터에 집어넣고 역순으로 해준 후 출력하면 된다.
// 처음 K가 홀수인 경우에는 *2를 해줘야 한다. 안 그럴 경우에는 누른횟수가 크게 증가한다.
// 무한 루프안에서의 K가 2로 나눴을때 나머지가 없을경우네는 K가 2,2의 배수인 형태로 구분지어서 
// K가 2이면 2를 빼주고 무한루프에서 탈출한다.
// 무한 루프 안에서의 K가 2로 나눴을때 나머지가 1일 경우에는 홀수이므로 바로 앞의 단계에서 2로 나눠준것을
// 취소하고 +2를 해준다.(그래야 다시 나눴을때 값이 작아져서 누른횟수가 감소하게 된다., 안해줄 경우에는 값이 커지므로 누른횟수가 증가해서 제한된 메모리를 넘는다.)
// ex) K = 7 -> 14 -> 16 -> 8 -> 4 -> 2 -> 0 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	vector <char> arr;
	long long K;
	cin >> K;

	if (K % 2 == 1)
	{
		arr.push_back('/');
		K *= 2;
	}
	
	while (K)
	{
		if (K % 2 == 0)
		{
			if (K == 2)
			{
				arr.push_back('+');
				K -= 2;
				continue;
			}
			else
			{
				arr.push_back('*');
				K /= 2;
			}
		}
		else
		{
			arr.pop_back();
			K *= 2;
			arr.push_back('-');
			K += 2;
		}
	}
	
	if (arr.size() > 99)
	{
		cout << -1 << "\n";
	}
	else
	{
		reverse(arr.begin(), arr.end());
		cout << arr.size() << "\n";
		for (int i = 0; i < arr.size(); i++)
		{
			cout << "[" << arr[i] << "]" << " ";
		}
	}
	return 0;
}