#include <iostream>
#include <vector>
#include <algorithm>
"수정"
using namespace std;


bool Sort(const pair<string,double> &a, const pair<string,double> &b)
{
	return a.second > b.second;
}

int main(void)
{
	while(1)
	{
		int N;
		cin >> N;
		if(!N) break;
		else
		{
			vector <pair<string,double>> arr(N);
			for(int i = 0; i < N; i++)
			{
				cin >> arr[i].first >> arr[i].second;
			}
			sort(arr.begin(), arr.end(),Sort);

			cout << arr[0].first << " ";
			for(int i = 1; i < N; i++)
			{
				if(arr[i].second == arr[i-1].second)
				{
					cout << arr[i].first << " ";
				}
				else break;
			}
			cout << "\n";
		}
	}
	return 0;
}
