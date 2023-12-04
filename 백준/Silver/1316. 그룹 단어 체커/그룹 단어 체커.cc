#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> mi;
    
    int a;
    cin >> a;
    int answer = 0;
    
    while(a--)
    {
        string t = {};
        cin >> t;
        bool isSkip = false;
        stack<int> si;
        
        for(auto v : t)
        {
            if(si.empty())
            {
                si.push(v);
                continue;
            }
            
            if(mi[v] > 0)
            {
                isSkip = true;
                break;
            }
            
            if(si.top() != v)
            {
                mi[si.top()]++;
                si.pop();
                si.push(v);
            }
            else
            {
                si.push(v);
            }
        }
        
        mi.clear();
        
        if(isSkip)
            continue;
        
        answer++;
    }
    
    cout << answer;
    return 0;
}