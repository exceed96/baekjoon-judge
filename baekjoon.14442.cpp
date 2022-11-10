#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

char board[1002][1002];
int vis_count[1002][1002];
int vis[1002][1002][11];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int N,M,K;

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> board[i][j];
    if (N == 1 && M == 1)
    {
        cout << "1";
        return (0);
    }
    queue <tuple<int,int,int>> Q;
    vis_count[0][0] = 1; //시작지점의 이동횟수를 1로 초기화
    vis[0][0][0] = 0; 
    Q.push({0,0,0});
    while (!Q.empty())
    {
        int x = get<0>(Q.front());
        int y = get<1>(Q.front());
        int w = get<2>(Q.front());
        Q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (vis[nx][ny][w] > 0) continue;
            if (board[nx][ny] == '0' && !vis[nx][ny][w]) //가는곳이 땅이고 방문하지 않은 곳이면
            {
                vis[nx][ny][w] = 1; //방문 배열을 1로초기화
                Q.push({nx,ny,w}); //큐에 넣어준다.
                vis_count[nx][ny] = vis_count[x][y] + 1; // 이동횟수을 1 증가시킨다
            }
            if (board[nx][ny] == '1' && w < K && !vis[nx][ny][w + 1]) //가는곳이 벽이고 아직 벽을 부실수 있다면
            {
                vis[nx][ny][w + 1] = 1; //벽을 부신다.(즉 방문했다는 표시를 남긴다)
                Q.push({nx,ny,w + 1}); //큐에 넣어준다.
                vis_count[nx][ny] = vis_count[x][y] + 1; // 이동횟수를 1 증가시킨다.
            }
            if (nx == N - 1 && ny == M - 1) //맨 오른쪽 아래 좌표에 도착했다면 이동횟수 출력
            {
                cout << vis_count[x][y] + 1;
                return (0);
            }
        }
    }
    cout << "-1";
}
