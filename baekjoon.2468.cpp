#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int board[102][102];
int board_2[102][102];
bool vis[102][102];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int N;

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int max = 0;
    vector <int> arr;
    queue <pair<int,int>> Q;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] > max)
                max = board[i][j];
        }
    }
    for(int max_n = 0; max_n <= max; max_n++)
    {
        int count = 0;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                board_2[i][j] = 1;
                if (board[i][j] <= max_n)
                {
                    board_2[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if (vis[i][j] || !board_2[i][j]) continue;
                else
                {
                    count++;
                    Q.push({i,j});
                    vis[i][j] = 1;
                    while (!Q.empty())
                    {
                        pair <int,int> cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                            if (vis[nx][ny] || !board_2[nx][ny]) continue;
                            Q.push({nx,ny});
                            vis[nx][ny] = 1;
                        }
                    }
                }
            }
        }
        arr.push_back(count);
    }
    sort(arr.begin(), arr.end());
    cout << arr[arr.size() - 1] << "\n";
}
