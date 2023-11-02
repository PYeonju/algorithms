#include <bits/stdc++.h>

using namespace std;

struct A
{
    int data;
    int pos;
};

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    vector<int> temp;
    deque<A> answer;
    
    int N,L,input;
    
    cin>>N>>L;
    
    // input data
    for(int i=0; i<N; i++)
    {
        cin>>input;
        temp.push_back(input);
    }
    
    for(int i=0; i<N; i++)
    {
        if(!answer.empty() && i==answer.front().pos+L)
            answer.pop_front();
        while(!answer.empty() &&answer.back().data> temp[i])
            answer.pop_back();
        answer.push_back({temp[i],i});
        cout<<answer.front().data<<" ";
    }

    
    return 0;
}