#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    
    vector<int> left(a.size());
    vector<int> right(a.size());
    
    int min = a[0];
    for(int i=0; i<a.size(); i++)
    {
        if(min>a[i])
            min = a[i];
        left[i]=min;
    }
    
    min = a[a.size()-1];
    for(int i=a.size()-1; i>=0; i--)
    {
        if(min>a[i])
            min=a[i];
        right[i]=min;
    }
    
    for(int i=0; i<a.size(); i++)
    {
        // 작은게 하나라도 있으면 된다.
        if(a[i] <= left[i] || a[i] <= right[i])
            answer++;
    }
    
    return answer;
}