#include <bits/stdc++.h>

using namespace std;

int arr[100002];
int dist[100002];

void Run(int i)
{
    int cur = i;
    
    while(true)
    {
        dist[cur]=i;
        cur = arr[cur];
        // 이번 방문에서 지나간 학생에 도달했을 경우
        if(dist[cur]==i)
        {
            while(dist[cur] != -1)
            {
                dist[cur] = -1;
                cur = arr[cur];
            }
            return;
        }
        else if(dist[cur]!=0)
            return;
    }
    
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        
        int input;
        cin >> input;

        fill(dist, dist + input+1, 0);

        for (int i = 1; i < input+1; i++)
            cin >> arr[i];

        for (int i = 1; i < input+1; i++)
        { 
            // 만약 자기자신을 부르면 함수를 부르지도마
            if(i==arr[i])
            {
                dist[i] = -1;
                continue;
            }
            // 방문을 하지 않았을때만 방문을 한다.
            if(dist[i] == 0)
                Run(i);   
        }
        int count = 0;
        for(int i=1; i<input+1; i++)
        {
            if(dist[i]!=-1)
                count++;
        }
        
        cout << count<<"\n";

    }


    return 0;
}