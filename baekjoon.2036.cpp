/*https://www.acmicpc.net/problem/2036*/
// 정렬을 이용한 그리디 문제
// 1보다 큰 양수, 음수, 1 즉 세가지로 구분하여서 1보다 큰 양수는 내림차순으로 정렬하여서 값을 구하고 음수는 오름차순으로 해서 값을 구하고
// 1은 나온횟수만큼 더해준다. 이래야 최대 점수가 나온다. 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector <ll> arr;
vector <ll> arr2;

int main(void)
{
	int n, number, count_z = 0;
	ll sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		if (number > 1) // 1보다 큰 양수
		{
			arr.push_back(number);
		}
		else if (number < 1) // 1보다 작은 수
		{
			arr2.push_back(number);
		} 
		else // 1은 나올때마다 카운트 해준다,(나중에 한번에 더해주기 위하여)
		{
			count_z++;
		}
	}

	sort(arr.begin(), arr.end(), greater<int>()); // 양수는 내림차순으로 정렬 ex) 5,5,4,3,1
	sort(arr2.begin(), arr2.end()); // 1보다 작은 수는 오름차순으로 정렬 ex) -4,-3,-2,-1,0

	if (arr.size() % 2) // 양수만 모인 벡터의 원소의 갯수가 홀수일 경우 남은 1개는 마지막에 더해준다.
	{
		for (int i = 0; i < arr.size() - 1; i += 2)
		{
			sum += arr[i] * arr[i + 1];
		}
		sum += arr[arr.size() - 1];
	}
	else  
	{
		for (int i = 0; i < arr.size(); i += 2)
		{
			sum += arr[i] * arr[i + 1];
		}
	}

	if (arr2.size() % 2)
	{
		for (int i = 0; i < arr2.size() - 1; i += 2)
		{
			sum += arr2[i] * arr2[i + 1];
		}
		sum += arr2[arr2.size() - 1];
	}
	else
	{
		for (int i = 0; i < arr2.size(); i += 2)
		{
			sum += arr2[i] * arr2[i + 1];
		}
	}

	cout << sum + count_z << "\n"; //1의 갯수와 1을 기준으로 나눈 벡터로 기준잡은 합을 더해준다.
	return 0;
}