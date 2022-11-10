#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int board[202][202]; //맵
int vis_count[202][202]; //맵의 각 좌표마다 움직이는 회수 저장할 배열
bool vis[202][202][32]; //원숭이가 방문했는지 방문안했는지 판단하는 배열

int dx[] = {1,0,-1,0}; //원숭이였을때 움직이는 경로
int dy[] = {0,1,0,-1};

int dx_h[] = {-2,-2,-1,-1,1,1,2,2,}; //말이 였을때 움직이는 경로
int dy_h[] = {-1,1,-2,2,-2,2,-1,1};

int K,W,H;

queue <tuple<int,int,int>> Q; //좌표값과 말처럼 이동했는지 안했는지와 방문 판단 값

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> K >> W >> H;
    for(int i = 1; i <= H; i++)
        for(int j = 1; j <= W; j++)
            cin >> board[i][j];
    vis[1][1][K] = 1; //제한된 k횟수만큼으로 시작한다. 즉 처음 시작 부분은 1로 초기화
    vis_count[1][1] = 0; //시작지점의 이동횟수는 0
    Q.push({1,1,K}); //처음 부분부터 큐에다가 넣는다.
    while (!Q.empty())
    {
        int x = get<0>(Q.front()); //x좌표
        int y = get<1>(Q.front()); //y좌표
        int h = get<2>(Q.front()); //말처럼 이동한 횟수
        Q.pop();
        if (x == H && y == W) //맨오른쪽 좌표에 도달했다면 vis_count에저장된 값을 출력하고 끝
        {
            cout << vis_count[x][y];
            return (0);
        }
        if (h > 0) //말처럼 이동할 수 있는 횟수가 0보다 클때만 말처럼 이동하는 bfs에 접근
        {
            for(int dir = 0; dir < 8; dir++)
            {
                int nx = x + dx_h[dir];
                int ny = y + dy_h[dir];
                if (nx > 0 && nx <= H && ny > 0 && ny <= W && !board[nx][ny]) //만약 말처럼 이동할수 있다면
                {
                    if (!vis[nx][ny][h - 1]) //또, 방문하지 않은 좌표라면
                    {
                        Q.push({nx,ny,h - 1}); //큐에다가 그 좌표값을 넣어주고
                        vis[nx][ny][h - 1] = 1; //그 좌표는 이미 방문했다는 표시를 해주고
                        vis_count[nx][ny] = vis_count[x][y] + 1; //이동횟수를 1 증가시켜준다.
                    }
                }
            }
        }
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx > 0 && nx <= H && ny > 0 && ny <= W && !board[nx][ny])
            {
                if (!vis[nx][ny][h])
                {
                    Q.push({nx,ny,h});
                    vis[nx][ny][h] = 1;
                    vis_count[nx][ny] = vis_count[x][y] + 1;
                }
            }
        }
    }
    cout << "-1";
}
