#include <bits/stdc++.h>

using namespace std;

int dist[1000002];

int main()
{
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;
    
    // 1층부터라고 생각하지만 인덱스는 0부터다
    fill(dist,dist+f+1,-1);
    
    queue<int> Q;
    Q.push(s);
    dist[s]=0;
    
    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        
        int upX = cur + u;
        int downX = cur - d;
        
        if(1<=upX && upX<f+1 )
        {
            if(dist[upX]==-1)
            {
                dist[upX] = dist[cur]+1;
                Q.push(upX);
            }
        }
        
        if(1<=downX && downX<f+1)
        {
            if(dist[downX]==-1)
            {
                dist[downX] = dist[cur]+1;
                Q.push(downX);
            }
        }
        
        if(dist[g] != -1)
            break;
    }
    
    if(dist[g] != -1)
        cout<<dist[g];
    else
        cout<<"use the stairs";
    
    return 0;
}