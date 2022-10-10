#include <iostream>
#include <queue>

using namespace std;

bool vis[100002];

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N,K, count = 0; //N = 수빈이의 위치, K = 동생의 위치, count = 최종 이동한 횟수
    cin >> N >> K;
    queue <pair<int,int>> Q; // first = 수빈이의 위치, second = 이동한 횟수
    Q.push(make_pair(N, 0)); // 수빈이의 위치와 이동한 횟수의 시작값을 넣어준다.
    
    while (!Q.empty()) //큐가 빌때까지
    {
        int l = Q.front().first; // l = 수빈이의 현재 위치
        int c = Q.front().second; // c = 이동한 횟수
        Q.pop(); 
        if (l == K) //수빈이의 현재위치가 동생의 위치와 같아진다면
        {
            count = c; // count변수에는 c로 초기화 해주고 반복문을 벗어난다.
            break;
        }
        
        int x = l - 1; //현재위치에서 -1만큼 이동
        int y = l + 1; //현재위치에서 +1만큼 이동
        int z = l * 2; //현재위치에서 두배만큼 이동
        
        if (0 <= x && !vis[x]) //x는 현재위치에서 -1만큼 이동하는 것이므로 0보다 크고 방문하지 않은 위치라면 
        {
            vis[x] = true; //방문했다고 표시
            Q.push(make_pair(x, c + 1)); //그 위치를 다시 큐에다가 넣어주고 이동한 횟수를 + 1 해준다.
        }
        if (y <= K && !vis[y]) //위와 같다.
        {
            vis[y] = true;
            Q.push(make_pair(y, c + 1));
        }
        if (z <= K + 1 && !vis[z]) //2배일 경우는 -1을 한번 해줄수 있으므로 동생의 위치에서 + 1 만큼 해준거 까지가 범위이다.
        {
            vis[z] = true;
            Q.push(make_pair(z, c + 1));
        }
    }
    cout << count;
}

