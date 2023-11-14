#include <bits/stdc++.h>

using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int board[1002][1002];
int dist[1002][1002][2];

int main()
{
    int n,m;
    cin>>n>>m;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            char temp;
            cin>>temp;
            board[i][j] = temp-'0';
        }
    }
    
    
    // Q에 상태까지 넣어야한다.
    // 0은 벽을 부수지 않은 상태
    // 1은 벽을 부순 상태
    queue<tuple<int,int,int>> Q;
    dist[0][0][0]=1;
    Q.push({0,0,0});
    
    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        
        // 만약 현재 위치가 n과 m이라면 출력해야한다.
        if(get<0>(cur)==n-1 && get<1>(cur) ==m-1)
        {
            cout<<dist[get<0>(cur)][get<1>(cur)][get<2>(cur)];
            return 0;
        }
        
        for(int dir = 0; dir<4; dir++)
        {
            int nx = get<0>(cur)+dx[dir];
            int ny = get<1>(cur)+dy[dir];
            int breakWall = get<2>(cur);
            
            if(nx<0 || n<=nx || ny<0|| m<=ny)
                continue;
            if(dist[nx][ny][breakWall] != 0)
                continue;
            
            // 위까지는 BFS와 동일하다.
            // 0(벽을 부수지 않은 세계), 1(벽을 부순 세계)
            // 0->1 // 1->0를 고려해야한다..?
            // 만약 다음이 0이면
            if(board[nx][ny]==0)
            {
                // 그 전 거리 +1을 하고 Q에 넣어준다. 이건 평소 BFS와 동일
                dist[nx][ny][breakWall]=dist[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
                Q.push({nx,ny,breakWall});
            }   
            // 만약 방문도 하지않았고, 벽이고, 벽을 부순적도 없으면
            if(board[nx][ny]==1 && breakWall==0)
            {
                dist[nx][ny][1]=dist[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
                Q.push({nx,ny,1});
            }
        }
    }
    
    cout<<-1;
    
    return 0;
}