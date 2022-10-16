#include <iostream>
#include <vector>

using namespace std;

int f[3];

int main(void)
{
    vector <int> arr(4);
    for(int i = 0; i < 4; i++)
    {
        cin >> arr[i];
        if (i >= 1)
        {
            if (arr[i] > arr[i - 1]) f[0]++;
            else if (arr[i] < arr[i - 1]) f[1]++;
            else if (arr[i] == arr[i - 1]) f[2]++;
        }
    }
    if (f[0] == 3) cout << "Fish Rising" << "\n";
    else if (f[1] == 3) cout << "Fish Diving" << "\n";
    else if (f[2] == 3) cout << "Fish At Constant Depth" << "\n";
    else cout << "No Fish" << "\n";
}
