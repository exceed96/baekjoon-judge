/*https://www.acmicpc.net/problem/5911*/
// 그리디, 정렬, 브루트포스를 곁들인 문제

// 가격의 합이 작은거부터 오름차순으로 정렬, 또한 선물의 가격을 오름차순으로 정렬하여서 최대로 선물할수있는 인원수를 비교해주면 된다.
// 더 쉬운 풀이가 있을것이다. 너무 돌아돌아가는 로직이다.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Sort(const pair<int, int>& a, const pair<int, int>& b) // 가격의 합을 오름차순으로 정렬
{
	int a_ = a.first + a.second;
	int b_ = b.first + b.second;
	if (a_ < b_) return 1;
	else if (a_ == b_)
	{
		if (a.first < b.first) return 1;
	}
	return 0;
}


int main(void)
{
	int N, B, count = 0, count2 = 0;
	cin >> N >> B;
	
	int B_2 = B; // 선물의 가격이 오름차순일때에 쓰기위한 B값
	vector <pair<int, int>> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end(), Sort);
	
	for (int i = 0; i < N; i++)
	{
		int sum = arr[i].first + arr[i].second;
		if (sum <= B) // 합이 작은거부터 B와 비교하여서 B보다 작거나 같으면 B에서 마이너스 해주고 인원수를 1 더해준다.
		{
			B -= sum;
			count++;
		}
		else
		{
			if (arr[i].first / 2 + arr[i].second <= B) // 
			{
				count++;
				break;
			}
		}
	}

	sort(arr.begin(), arr.end());
	
	for (int i = 0; i < N; i++)
	{
		int sum = arr[i].first + arr[i].second;
		if (sum <= B_2) // 선물값이 작은거부터 B와 비교하여서 B보다 작거나 같으면 B에서 마이너스 해주고 인원수를 1 더해준다.
		{
			B_2 -= sum;
			count2++;
		}
		else
		{
			if (arr[i].first / 2 + arr[i].second <= B)
			{
				count2++;
				break;
			}
		}
	}

	if (count > count2) cout << count << "\n"; // 두가지 경우중 큰 값을 출력한다.
	else cout << count2 << "\n";
	
	return 0;
}