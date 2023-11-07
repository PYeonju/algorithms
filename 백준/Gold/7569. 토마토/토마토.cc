#include <bits/stdc++.h>

using namespace std;

// 상하좌우 + 위아래
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int dz[2]={-1,1};

int board[102][102][102];
int dist[102][102][102];

int main()
{
    int n,m,h;
    cin>>n>>m>>h;
    queue<tuple<int,int,int>> Q;
    
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<m; j++)
            fill(dist[i][j],dist[i][j]+n,-1);
    }
    
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<m; j++)
        {
            for(int k=0; k<n; k++)
            {
                cin>>board[i][j][k];
                if(board[i][j][k]==1)
                {
                    Q.push(make_tuple(i,j,k));
                    dist[i][j][k]=0;
                }
            }
        }
    }
                    
    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
    
        for(int dir =0; dir<4; dir++)
        {
            int nz = get<0>(cur);
            int nx = get<1>(cur) + dx[dir];
            int ny = get<2>(cur) + dy[dir];
                         
            if(nx<0 || m<=nx || ny<0 || n<=ny || nz<0 || h<=nz)
                continue;
            if(dist[nz][nx][ny] >= 0 || board[nz][nx][ny] == -1)
                continue;
            dist[nz][nx][ny]= dist[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            Q.push(make_tuple(nz,nx,ny));
        }
        for(int dir =0; dir<2; dir++)
        {
            int nz = get<0>(cur) + dz[dir];
            int nx = get<1>(cur);
            int ny = get<2>(cur);
                         
            if(nx<0 || m<=nx || ny<0 || n<=ny || nz<0 || h<=nz)
                continue;
            if(dist[nz][nx][ny] >= 0 || board[nz][nx][ny] == -1)
                continue;
            dist[nz][nx][ny]= dist[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            Q.push(make_tuple(nz,nx,ny));
        }
    }
    
    int day=0;
    
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<m; j++)
        {
            for(int k=0; k<n; k++)
            {
                if(dist[i][j][k] == -1 && board[i][j][k] == 0)
                {
                    cout<<-1;
                    return 0;
                }
                day = max(day,dist[i][j][k]);
            }
        }
    }
    
    cout<<day;
    
    return 0;
}