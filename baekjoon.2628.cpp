#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int L,B,C;
	cin >> L >> B >> C;
	vector <int> arr;
	vector <int> arr2;

	int i = 0;
	while(i != C)
	{
		int N,N_;
		cin >> N >> N_;
		if(N) arr.push_back(N_);
		else arr2.push_back(N_);
		i++;
	}

	arr.push_back(L);
	arr2.push_back(B);
	
	sort(arr.begin(), arr.end());
	sort(arr2.begin(), arr2.end());

	vector <int> arr3;
	vector <int> arr4;
	
	arr3.push_back(arr[0]);
	arr4.push_back(arr2[0]);

	for(int i = 1; i < arr.size(); i++)
	{
		arr3.push_back(arr[i] - arr[i - 1]);
	}

	for(int i = 1; i < arr2.size(); i++)
	{
		arr4.push_back(arr2[i] - arr2[i - 1]);
	}

	sort(arr3.begin(), arr3.end());
	sort(arr4.begin(), arr4.end());

	cout << arr3[arr3.size() - 1] * arr4[arr4.size() - 1] << "\n";

	return 0;
}


