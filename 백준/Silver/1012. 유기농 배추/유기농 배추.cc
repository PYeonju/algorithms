#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board[51][51];
int dist[51][51];

int main()
{
    int testCase,m,n,k;
    cin>>testCase;
    
    while(testCase--)
    {
        cin>>m>>n>>k;
        
        // 테스트 케이스가 한번에 들어오므로 초기화 시켜줘야한다.
        for(int i=0; i<m; i++)
        {
            fill(board[i],board[i]+n,0);
            fill(dist[i],dist[i]+n,0);
        }
        
        while(k--)
        {
            int x,y;
            cin>>x>>y;
            board[x][y]=1;
        }
        
        queue<pair<int,int>> Q;
        int count = 0; 
    
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                // 배추이고 방문한적이 없을때 넣어준다.
                if(board[i][j] == 1 && dist[i][j] == 0)
                {
                    // 방문표시를 남긴다.
                    dist[i][j]=1;
                    Q.push({i,j});
                    count++;
                
                    while(!Q.empty())
                    {
                        auto cur = Q.front();
                        Q.pop();
                    
                        for(int dir=0; dir<4; dir++)
                        {
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                        
                            // 일단 넘는지 체크 먼저 한다.
                            if(nx < 0 || m <= nx || ny < 0 || n <= ny)
                                continue;;
                            // 방문했는지와 배추인지 체크
                            if(dist[nx][ny] !=0 || board[nx][ny] != 1)
                                continue;
                            dist[nx][ny]=1;
                            Q.push({nx,ny});
                         }
                      }
                    }
                }
            }
        cout<<count<<"\n";
    }
    
    return 0;
}