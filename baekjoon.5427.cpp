#include <iostream>
#include <queue>

using namespace std;

string board[1002];
int dist1[1002][1002];
int dist2[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool f;

int main(void)
{
    int T;
    cin >> T;
    while (T--)
    {
        f = 0;
        cin.tie(0); ios_base::sync_with_stdio(0);
        int N,M;
        cin >> N >> M;
        for(int i = 0; i < M; i++)
        {
            fill(dist1[i], dist1[i] + N, -1);
            fill(dist2[i], dist2[i] + N, -1);
        }
        for(int i = 0; i < M; i++)
            cin >> board[i];
        queue <pair<int,int>> Q1;
        queue <pair<int,int>> Q2;
        for(int i = 0; i < M; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if (board[i][j] == '*')
                {
                    Q1.push({i,j});
                    dist1[i][j] = 0;
                }
                if (board[i][j] == '@')
                {
                    Q2.push({i,j});
                    dist2[i][j] = 0;
                }
            }
        }
        while (!Q1.empty())
        {
            pair <int,int> cur = Q1.front(); Q1.pop();
            for(int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
                Q1.push({nx,ny});
            }
        }
        
        while (!Q2.empty() && (!f))
        {
            pair <int,int> cur = Q2.front(); Q2.pop();
            for(int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                {
                    cout << dist2[cur.first][cur.second] + 1 << "\n";
                    f = 1;
                    break;
                }
                if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1) continue;
                dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
                Q2.push({nx,ny});
            }
        }
        if (f != 1)
            cout << "IMPOSSIBLE" << "\n";
        while (!Q1.empty())
            Q1.pop();
        while (!Q2.empty())
            Q2.pop();
    }
}
