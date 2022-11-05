#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

char board[102][102];
int vis_n[102][102], vis_s[102][102], vis_c[102][102];

int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};

queue <pair<int,int>> Q_n;
queue <pair<int,int>> Q_s;
queue <pair<int,int>> Q_c;

int R,C, count, result;
int max_count = 10002;

int main(void)
{
    cin >> R >> C;
    for(int i = 1; i <= R; i++)
        for(int j = 1; j <= C; j++)
            cin >> board[i][j];
    int x_n, y_n, x_s, y_s, x_c, y_c;
    cin >> x_n >> y_n >> x_s >> y_s >> x_c >> y_c;
    board[x_n][y_n] = 'N';
    board[x_s][y_s] = 'S';
    board[x_c][y_c] = 'C';
    memset(vis_n, -1, sizeof(vis_n)); memset(vis_s, -1, sizeof(vis_s)); memset(vis_c, -1, sizeof(vis_c));
    Q_n.push({x_n,y_n}); vis_n[x_n][y_n] = 0;
    Q_s.push({x_s,y_s}); vis_s[x_s][y_s] = 0;
    Q_c.push({x_c,y_c}); vis_c[x_c][y_c] = 0;
    while (!Q_n.empty())
    {
        pair <int,int> cur = Q_n.front(); Q_n.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
            if (board[nx][ny] == '1' || vis_n[nx][ny] >= 0) continue;
            vis_n[nx][ny] = vis_n[cur.first][cur.second] + 1;
            Q_n.push({nx,ny});
        }
    }
    while (!Q_s.empty())
    {
        pair <int,int> cur = Q_s.front(); Q_s.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
            if (board[nx][ny] == '1' || vis_s[nx][ny] >= 0) continue;
            vis_s[nx][ny] = vis_s[cur.first][cur.second] + 1;
            Q_s.push({nx,ny});
        }
    }
    while (!Q_c.empty())
    {
        pair <int,int> cur = Q_c.front(); Q_c.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
            if (board[nx][ny] == '1' || vis_c[nx][ny] >= 0) continue;
            vis_c[nx][ny] = vis_c[cur.first][cur.second] + 1;
            Q_c.push({nx,ny});
        }
    }
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            if (max(vis_s[i][j], max(vis_n[i][j], vis_c[i][j])) != -1)
            {
                result = max(vis_s[i][j], max(vis_n[i][j], vis_c[i][j]));
                if (result < max_count)
                {
                    count = 1;
                    max_count = result;
                }
                else if (result == max_count)
                    count++;
                else
                    continue;
            }
        }
    }
    if(max_count)
        cout << max_count << "\n" << count << "\n";
    else
        cout << "-1" << "\n";
}
