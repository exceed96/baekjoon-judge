#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N,A,D,S,count = 0;
    cin >> N >> A >> D;
    vector <int> arr(N);
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if(arr[i] == A)
        {
            count++;
            A += D;
        }
    }
    cout << count << "\n";
    return 0;
}
