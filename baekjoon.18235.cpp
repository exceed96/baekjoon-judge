#include <iostream>
#include <queue>

using namespace std;

int vis_A[500002][20];
int vis_B[500002][20]; //vis_B[위치][방문 일수]

int N,A,B;
const int INF = 987654321; // 결국 서로 만나지 못할 경우에 쓰기위한 변수
int ans = INF;

void sol_A()
{
    queue <pair<int,int>> Q;
    vis_A[A][0] = 0;
    Q.push({A,0});
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        int path = (1 << cur.second); //비트연산자를 통해서 1,2,4,8,16,32,64,128...으로 진행
        cout << path << "\n";
        int next[2] = {cur.first + path, cur.first - path}; 
        for(int i = 0; i < 2; i++)
        {
            if (1 <= next[i] && next[i] <= N) //다음위치의 범위가 1이상이고 N이하일때
            {
                if (vis_A[next[i]][cur.second + 1] == -1) //만약 방문하지 않은 위치라면 
                {
                    vis_A[next[i]][cur.second + 1] = cur.second + 1; //방문 날짜의 값은 현재 위치에서의 방문 일수에 +1을 해준다.
                    Q.push({next[i], cur.second + 1}); 
                }
            }
        }
        path *= 2;
    }
}

void sol_B()
{
    queue <pair<int,int>> Q;
    vis_B[B][0] = 0;
    Q.push({B, 0});
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        int path = (1 << cur.second);
        int next[2] = {cur.first + path, cur.first - path};
        if (vis_A[cur.first][cur.second] != -1 && vis_A[cur.first][cur.second] == vis_B[cur.first][cur.second])
        {
            ans = cur.second;
            return ;
        }
        for(int i = 0; i < 2; i++)
        {
            if (1 <= next[i] && next[i] <= N)
            {
                if (vis_B[next[i]][cur.second + 1] == -1)
                {
                    vis_B[next[i]][cur.second + 1] = cur.second + 1;
                    Q.push({next[i], cur.second + 1});
                }
            }
        }
    }
}

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> A >> B;
    
    for(int i = 0; i < 500002; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            vis_A[i][j] = -1;
            vis_B[i][j] = -1;
        }
    }
    sol_A();
    sol_B();
    if (ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";
}
