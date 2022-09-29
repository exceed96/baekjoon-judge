#include <iostream>
#include <queue>

using namespace std;

string board[1002];
int dist1[1002][1002]; //불의 전파시간 방문 2차원배열
int dist2[1002][1002]; //지훈이의 이동시간 2차원배열
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N,M;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        fill(dist1[i], dist1[i] + M, -1); //dist1 2차원배열을 -1로 초기화
        fill(dist2[i], dist2[i] + M, -1); //dist2 2차원배열을 -1로 초기화
    }
    for(int i = 0; i < N; i++) //string으로 선언한 board 문자열 배열 입력
        cin >> board[i];
    queue <pair<int,int>> Q1; //불 queue
    queue <pair<int,int>> Q2; //지훈 queue
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if (board[i][j] == 'F') //불이 시작 지점을 Q1에 넣어준다.
            {
                Q1.push({i,j});
                dist1[i][j] = 0;
            }
            if (board[i][j] == 'J') //지훈이의 시작 지점을 Q2에 넣어준다.
            {
                Q2.push({i,j});
                dist2[i][j] = 0;
            }
        }
    }
    while (!Q1.empty()) //Q1이 빈 상태가 될 때까지 탐색을 진행
    {
        pair <int,int> cur = Q1.front(); Q1.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue; //벽을 만나면 continue
            dist1[nx][ny] = dist1[cur.first][cur.second] + 1; //불이 가지 못한 공간이라면 그 전의 값에다가 1을 더한 값을 초기화
            Q1.push({nx,ny});
        }
    }
    
    while (!Q2.empty())
    {
        pair <int,int> cur = Q2.front(); Q2.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) //범위를 벗어났다는 얘기는 곧 탈출 성공이란 것으로 +1을 해준 값을 출력과 함께 함수 종료
            {
                cout << dist2[cur.first][cur.second] + 1;
                return (0);
            }
            if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue; //이미 방문한 곳이거나 벽을 만나면 continue
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1) continue; //불이 지나간 시간보다 지훈이가 방문한 시간이 적다면 가지 못하는 곳이므로 continue
            dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
            Q2.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE"; 
}
