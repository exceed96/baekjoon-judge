/*https://www.acmicpc.net/problem/10867*/
#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std;

vector <int> arr;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		arr.push_back(n); //arr벡터에 값을 넣어준다.
	}
	sort(arr.begin(), arr.end()); // arr벡터를 오름차순으로 정렬
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	// arr벡터를 오름차순으로 정렬 후 unique를 통해서 중복하는 값을 지워주고 뒤에 남은 반환값을 erase로 제거

	for (int i = 0; i < arr.size(); i++) //결론적으로 중복을 제거한 수만 남게 된다.
	{
		cout << arr[i] << " "; 
	}
	return 0;
}