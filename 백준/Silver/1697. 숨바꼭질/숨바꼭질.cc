#include <bits/stdc++.h>

using namespace std;

int dist[100002];

int dx[3]={1,-1,2};

int main()
{
    queue<int> Q;
    
    // 수빈이 n, 동생 k
    int n,k;
    cin>>n>>k;
    
    fill(dist,dist+100001,-1);
    
    Q.push(n);
    dist[n] = 0;
    
    while(dist[k]==-1)
    {
        int cur = Q.front();
        Q.pop();
        
        for(int dir=0; dir<3; dir++)
        {
            int nx;
            if(dir != 2)
                nx = cur + dx[dir];
            else
                nx = cur * dx[dir];
            
            if(nx < 0 || 100000 < nx)
                continue;
            if(dist[nx] != -1)
                continue;
            dist[nx] = dist[cur]+1;
            Q.push(nx);
        }
    }
    
    cout<<dist[k];
    
    return 0;
}