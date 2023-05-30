#include <bits/stdc++.h>

using namespace std;

int solution(int a, int b, int c, int d) 
{
    int answer = 0;
    map<int, int> mp;
    
    mp[a]++;
    mp[b]++;
    mp[c]++;
    mp[d]++;
    
    if(mp[a] == 4)
        return 1111*a;
    
    if(mp[a] == 3 || mp[b] == 3)
    {
        int q = 0;
        int p = 7;
        for(auto& v : mp)
        {
            if(v.second == 1)
                q = v.first;
            else
                p = v.first;
        }
        return (10 * p + q) * (10* p + q);
    }
    
    if(mp[a] == 2 && mp[b] == 2 && mp[c] == 2)
    {
        int p = -1;
        int q = -1;
        
        if(p == -1)
            p = a; 
        
        if(p != b)
            q = b;
        else if(p != c)
            q = c;
        else if(p != d)
            q = d;
        
        return (p+q) * (abs(p-q));
    }
    
    if(mp[a] == 2 || mp[b] == 2 || mp[c] == 2 || mp[d] == 2)
    {
        int q = 0;
        int r = 0;
        
        if(mp[a] == 1 && q == 0)
            q = a;
        else if(mp[b] == 1 && q == 0)
            q = b;
        else if(mp[c] == 1 && q == 0)
            q = c;
        else if(mp[d] == 1 && q == 0)
            q = d;
        
        if(mp[a] == 1 && q != 0 && q!=a)
            r = a;
        else if(mp[b] == 1 && q != 0 && q!=b)
            r = b;
        else if(mp[c] == 1 && q != 0 && q!=c)
            r = c;
        else if(mp[d] == 1 && q != 0 && q!=d)
            r = d;
        
        return q*r;
    }
    
    int p = a;
    if(b < p)
        p = b;
    if(c < p)
        p = c;
    if(d < p)
        p = d;
    
    return p;
}