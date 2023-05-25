#include <bits/stdc++.h>

using namespace std;
bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.first < b.first;    
}

int solution(vector<int> rank, vector<bool> attendance) 
{
    int answer = 0;
    vector<pair<int, int>> vs;
    for(int i = 0; i<rank.size(); i++)
    {
        if(attendance[i])
            vs.push_back(make_pair(rank[i], i));
    }
    sort(vs.begin(), vs.end(), compare);
    
    answer = 10000 * vs[0].second + 100 * vs[1].second + vs[2].second;
    
    return answer;
}