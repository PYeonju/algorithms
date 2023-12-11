#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int input,height;
    cin>>input;
    stack<pair<int,int>> st;
    
    for(int i=0; i<input; i++)
    {
        cin>>height;
        
        while(!st.empty())
        {
            if(height <= st.top().second)
            {
                cout<<st.top().first<<" ";
                break;
            }
            st.pop();
        }
        if(st.empty())
            cout<<0<<" ";
        st.push({i+1,height});
    }
    return 0;
}