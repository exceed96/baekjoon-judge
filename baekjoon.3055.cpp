#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[52][52];
int vis_S[52][52];
int vis_W[52][52];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int R, C;

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> R >> C;
    
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            vis_S[i][j] = -1;
            vis_W[i][j] = -1;
        }
    }
    
    queue <pair<int,int>> Q_S;
    queue <pair<int,int>> Q_W;
    
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'S')
            {
                Q_S.push({i,j});
                vis_S[i][j] = 0;
            }
            if (board[i][j] == '*')
            {
                Q_W.push({i,j});
                vis_W[i][j] = 0;
            }
        }
    }
    while (!Q_W.empty())
    {
        pair <int,int> cur = Q_W.front(); Q_W.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (vis_W[nx][ny] >= 0 || board[nx][ny] == 'X' || board[nx][ny] == 'D') continue;
            vis_W[nx][ny] = vis_W[cur.first][cur.second] + 1;
            Q_W.push({nx,ny});
        }
    }
    
    while (!Q_S.empty())
    {
        pair <int,int> cur = Q_S.front(); Q_S.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (board[nx][ny] == 'D')
            {
                cout << vis_S[cur.first][cur.second] + 1;
                return (0);
            }
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (vis_S[nx][ny] >= 0 || board[nx][ny] == 'X') continue;
            if (vis_W[nx][ny] != -1 && vis_W[nx][ny] <= vis_S[cur.first][cur.second] + 1) continue;
            vis_S[nx][ny] = vis_S[cur.first][cur.second] + 1;
            Q_S.push({nx,ny});
        }
    }
    
    /*cout << "-------------------------" << "\n";
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
            cout << vis_W[i][j];
        cout << "\n";
    }
    cout << "-------------------------" << "\n";
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
            cout << vis_S[i][j];
        cout << "\n";
    }*/
    cout << "KAKTUS";
}
