#include <bits/stdc++.h>

using namespace std;

int dx[8]={-1,-1,-2,-2,1,1,2,2};
int dy[8]={-2,2,-1,1,-2,2,-1,1};

int main()
{
    int testCase,l;
    cin>>testCase;

    while(testCase--)
    {
        queue<pair<int,int>> Q;
        
        int dist[300][300];
        
        int x,y,tx,ty;
        cin>>l;
        
        for(int i=0; i<l; i++)
            fill(dist[i],dist[i]+l,-1);

        // 출발점
        cin>>x>>y;
        Q.push({x,y});
        dist[x][y]=0;
        // 도착점        
        cin>>tx>>ty;
        
        while(dist[tx][ty] == -1)
        {
            auto cur = Q.front();
            Q.pop();
            
            for(int dir=0; dir<8; dir++)
            {
                int nx = cur.first +dx[dir];
                int ny = cur.second +dy[dir];
                
                if(nx<0|| l<=nx ||ny<0||l<=ny)
                    continue;
                if(dist[nx][ny] !=-1)
                    continue;
                dist[nx][ny] = dist[cur.first][cur.second]+1;
                Q.push({nx,ny});
            }
        }
        cout<<dist[tx][ty]<<"\n";
    }
    
    return 0;
}