#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

using tp = tuple<int,int,int>; //튜플을 사용하여서 큐에 3개의 원소를 받을 수 있게 하였다.
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int N, M, Hx, Hy, Ex, Ey, board[1002][1002], vis[1002][1002][2]; //vis방문 배열을 3차원으로 하여서 마지막 위치가 0일때는 벽을 부수지 않은 상태, 1일때는 벽을 부순 상태

int bfs()
{
    memset(vis, -1, sizeof(vis));
    queue <tp> Q;
    Q.push({Hx, Hy, 0});
    vis[Hx][Hy][0] = 0;
    while (!Q.empty())
    {
        int x = get<0>(Q.front());
        int y = get<1>(Q.front());
        int key = get<2>(Q.front());
        Q.pop();
        if (x == Ex && y == Ey)
            return vis[x][y][key];
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if (vis[nx][ny][key] != -1) continue;
            if (!board[nx][ny]) //'0'인 지역일때는 부순 상태인지 벽을 부수지 않은상태인지에 따라서 그 전 값에 +1 한 값으로 초기화
            {
                vis[nx][ny][key] = vis[x][y][key] + 1;
                Q.push({nx,ny,key});
            }
            if (board[nx][ny] && !key) //이미 벽을 부순 상태라면 그전에 벽을 부수지 않은 상태에서 +1을 해준다.
            {
                vis[nx][ny][1] = vis[x][y][0] + 1;
                Q.push({nx,ny, 1});
            }
        }
    }
    return (-1);
}

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> M >> Hx >> Hy >> Ex >> Ey;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            cin >> board[i][j];
    cout << bfs();
}
