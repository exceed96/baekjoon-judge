/*https://www.acmicpc.net/problem/10814*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool Sort(const pair<int, string> &a, const pair<int, string> &b)
{
	return a.first < b.first;
}

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	vector <pair<int, string>> arr; //2차원 벡터를 통해서 나이,이름을 받는다
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string a;
		int n;
		cin >> n >> a;
		arr.push_back(make_pair(n, a)); //arr 2차원 벡터에 나이와 이름을 입력
	}

	stable_sort(arr.begin(), arr.end(), Sort); //stable_sort를 통해서 정렬
	// 그냥 sort로 하면 두 원소를 받을 때 순서를 유지시켜준다는 보장이 없다
	// 그래서 stable_sort를 통해서 입력 순서 유지하면서 정렬
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i].first << " " << arr[i].second << "\n";
	}
	return 0;
}