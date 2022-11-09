#include <iostream>
#include <queue>

using namespace std;

int board[2002][2002];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

queue <pair<int,int>> Q_M;
queue <pair<int,int>> Q_S;

int N,M,K;
int sx,sy;

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            int& cur = board[i][j];
            cin >> cur;
            if (cur == 3) Q_M.push({i,j});
            else if (cur == 4)
            {
                cur = 1;
                sx = i;
                sy = j;
            }
        }
    }
    
    while (K--)
    {
        int Q_Msize = Q_M.size();
        while (Q_Msize--)
        {
            pair <int,int> cur = Q_M.front(); Q_M.pop();
            for(int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] == 3) continue;
                board[nx][ny] = 3;
                Q_M.push({nx,ny});
            }
        }
    }
    
    int res = 0;
    Q_S.push({sx, sy});
    while (1)
    {
        res++;
        int Q_Ssize = Q_S.size();
        if (!Q_Ssize)
        {
            cout << -1;
            return (0);
        }
        while (Q_Ssize--)
        {
            pair <int,int> cur = Q_S.front(); Q_S.pop();
            for(int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (board[nx][ny] == 1 || board[nx][ny] == 3) continue;
                else if (board[nx][ny] == 2)
                {
                    cout << res;
                    return (0);
                }
                board[nx][ny] = 3;
                Q_S.push({nx,ny});
            }
        }
    }
}
