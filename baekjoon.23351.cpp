/*https://www.acmicpc.net/problem/23351*/
// 그리디 문제
// A는 N개의 약수이다. 그러면 전체적인 화분의 갯수를 N개로 볼개 아니라 A로 나눈값만큼 갯수로 보면된다.
// 그 다음 벡터의 원소 하나하나씩 물을 준다고 가정하여서 나머지는 1씩 깍이게 해서 0이 되는 원소를 만나면 첫 캣닢이 죽는 날짜이므로 
// 그때까지 카운트한 값을 출력하면 된다.

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N, K, A, B, count = 0;
	cin >> N >> K >> A >> B;
	vector <int> arr(N / A, K);

	bool c = false;

	int i = 0;

	while (!c)
	{
		arr[i] += B - 1; // 물을 준 캣닢
		count++;
		for (int j = 0; j < N / A; j++)
		{
			if (i != j) arr[j]--; // 물을 주지 않은 캣닢은 1을 빼기
			if (!arr[j]) // 0을 만났다면 C를 TRUE로 바꾸고 무한루프 벗어나기
			{
				c = true;
				break;
			}
		}
		i++;
		if (i >= N / A) i = 0;
	}

	cout << count << "\n";
	return 0;
}