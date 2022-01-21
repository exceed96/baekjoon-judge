/*https://www.acmicpc.net/problem/2405*/
// 탐색을 곁들인 그리디 문제
// 중위값을 b라고 하고 세개의 수를 각각 a,b,c라고 한다면 구하고자 하는 식은 b - ((a+b+c)/3)이다.
// 식을 변형시키면 a - 2/b + c이다. 이 값이 최대가 되는것을 찾으면 된다.
// 그러기 위해선 탐색을 해야하는데 a와 c를 각각 고정시키는 2가지의 경우를 생각하면된다.
// 그러면 전체 구간에 대한 식에 대한 최대값이 나오는 구간을 찾을 수 있다.
// a는 arr[0], c 는 arr[n-1]값으로 고정하며 벡터 전체에서 3개를 고르는 모든 경우를 탐색할수있다.
// 그리디 보다는 브루트포스에 가까운 문제 같다고 생각한다.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, result = 0;
	cin >> n;
	vector <int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	for (int i = 1; i < n - 1; i++)
	{
		result = max(result, abs(arr[0] - (arr[i] * 2) + arr[i + 1]));
	}
	for (int i = 0; i < n - 2; i++)
	{
		result = max(result, abs(arr[n - 1] + arr[i] - arr[i + 1] * 2));
	}
	cout << result << "\n";
	return 0;
}