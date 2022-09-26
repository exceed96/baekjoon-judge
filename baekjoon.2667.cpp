#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

char board[27][27];
bool vis[27][27];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N,M, count = 0;
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> board[i][j];
    vector <int> arr;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if (vis[i][j] || board[i][j] == '0') continue;
            else
            {
                count = 0;
                queue <pair<int,int>> Q;
                vis[i][j] = 1;
                Q.push({i,j});
                while (!Q.empty())
                {
                    count++;
                    pair <int, int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (vis[nx][ny] || board[nx][ny] == '0') continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
                arr.push_back(count);
            }
        }
    }
    sort(arr.begin(), arr.end());
    cout << arr.size() << "\n";
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << "\n";
}
