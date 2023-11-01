#include <bits/stdc++.h>

using namespace std;

int solution(int cacheSize, vector<string> cities) 
{
    int answer = 0;
    deque<string> ds;
    for(auto v : cities)
    {
        for (int i = 0; i < v.length(); i++) 
            v[i] = tolower(v[i]);
        
        bool hit = false;
        int index = 0;
        for (index = 0; index < ds.size(); index++) 
        {
            if (ds[index] == v) 
            {
                hit = true;
                break;
            }
        }
        
        ds.push_back(v);
        
        if (hit) 
        {
            ds.erase(ds.begin() + index);
            answer += 1;
        }
        else 
        {
            if (ds.size() > cacheSize) {
                ds.pop_front();
            }
            answer += 5;
        }
    }
    return answer;
}