#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long input,height;
    cin>>input;
    
    stack<long long> st;
    long long count = 0;
    
    for(int i=0; i<input; i++)
    {
        cin>>height;
        while(!st.empty())
        {
            if(st.top() <= height)
               st.pop();
            else
            {
                count += st.size();
                break;
            }
        }
        st.push(height);
    }
    
    cout<<count;
    
    return 0;
}