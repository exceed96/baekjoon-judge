#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[32][32][32];
int vis[32][32][32];

int dx[] = {1,0,-1,0,0,0};
int dy[] = {0,1,0,-1,0,0};
int dz[] = {0,0,0,0,-1,1};

int bfs()
{
        int L, R, C, count = 0;
        cin >> L >> R >> C;
        if (!L && !R && !C)
            return (-1);
        queue <pair<pair<int,int>, int>> Q;
        for(int i = 0; i < L; i++)
        {
            for(int j = 0; j < R; j++)
            {
                for(int k = 0; k < C; k++)
                {
                    vis[i][j][k] = -1;
                    cin >> board[i][j][k];
                    if (board[i][j][k] == 'S')
                    {
                        Q.push({{i,j},k});
                        vis[i][j][k] = 0;
                    }
                }
            }
        }
        while (!Q.empty())
        {
            pair<pair<int,int>, int> cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 6; dir++)
            {
                int nx = cur.first.second + dx[dir];
                int ny = cur.second + dy[dir];
                int nz = cur.first.first + dz[dir];
                if(nx < 0 || nx >= R || ny < 0 || ny >= C || nz < 0 || nz >= L) continue;
                if(vis[nz][nx][ny] != -1 || board[nz][nx][ny] == '#') continue;
                if(board[nz][nx][ny] == 'E')
                {
                    count = vis[cur.first.first][cur.first.second][cur.second] + 1;
                    return (count);
                }
                Q.push({{nz,nx}, ny});
                vis[nz][nx][ny] = vis[cur.first.first][cur.first.second][cur.second] + 1;
            }
        }
        return (0);
}

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int count = 0;
    while (1)
    {
        count = bfs();
        if (count == -1)
            break;
        if (!count)
            cout << "Trapped!" << "\n";
        else
            cout << "Escaped in " << count << " minute(s)." << "\n";
    }
}
