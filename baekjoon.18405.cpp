#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int board[202][202];
bool vis[202][202];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

vector <pair<int,int>> v[1002];

int N,K,S,X,Y;

void bfs(int S, int X_bfs, int Y_bfs)
{
    queue <tuple<int,int,int>> Q;
    for(int i = 1; i <= K; i++)
    {
        if (!v[i].empty())
        {
            for(auto p: v[i])
            {
                Q.push({i, p.first, p.second});
                vis[p.first][p.second] = 1;
            }
        }
    }
    while (!Q.empty() && S--)
    {
        int Q_size = Q.size();
        while (Q_size--)
        {
            int num, x, y;
            tie(num, x, y) = Q.front();
            Q.pop();
            for(int dir = 0; dir < 4; dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N || vis[nx][ny]) continue;
                board[nx][ny] = num;
                vis[nx][ny] = 1;
                Q.push({num, nx, ny});
            }
        }
    }
    cout << board[X_bfs][Y_bfs];
}

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j])
                v[board[i][j]].push_back({i,j});
        }
    }
    cin >> S >> X >> Y;
    bfs(S, X - 1, Y - 1);
}
