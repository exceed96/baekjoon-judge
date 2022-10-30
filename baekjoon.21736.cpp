#include <iostream>
#include <queue>

using namespace std;

char board[602][602];
bool vis[602][602];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int N,M,count;

int main(void)
{
    queue <pair<int,int>> Q;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'I')
            {
                Q.push({i,j});
                vis[i][j] = 1;
            }
        }
    }
    
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (vis[nx][ny] || board[nx][ny] == 'X') continue;
            if (board[nx][ny] == 'P') count++;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
    if(count)
        cout << count << "\n";
    else
        cout << "TT" << "\n";
}
