#include <bits/stdc++.h>

using namespace std;

int dp[15];

int main()
{
    int n;
    cin>>n;
    
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    
    while(n--)
    {
        int m;
        cin>>m;
        
        for(int i=4; i<=m; i++)
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        
        cout<<dp[m]<<"\n";
    }
    
    
    
    return 0;
}