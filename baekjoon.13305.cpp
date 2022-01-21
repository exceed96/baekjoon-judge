/*https://www.acmicpc.net/problem/13305*/
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	int N;
	long long sum = 0; //sum값의 int형 범위를 오버할수도 있어서 long long으로 선언
	cin >> N;
	vector <long long> arr(N - 1);
	vector <long long> arr2(N);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> arr2[i];
	}

	sum += arr[0] * arr2[0]; //처음에는 무조건 다음도시로 가는 거리만큼 첫번째 주유소에서 주유를 해야한다
	long long s = arr2[0]; //첫번째 주유소의 가격을 기준 삼는다
	for (int i = 1; i < N - 1; i++)
	{
		if (s > arr2[i]) // 두번째 주유소와 비교하여서 더 작은값으로 기준을 잡아준다.
		{
			s = arr2[i];
		}
		sum += s * arr[i]; //가는 거리만큼 곱해서 더해준다.
	}
	cout << sum << "\n";
	return 0;
}