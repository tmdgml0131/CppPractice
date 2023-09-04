#include <bits/stdc++.h>

using namespace std;

//map으로 카운팅
//map.second로 내림차순 정렬
//map.first로 갯수 카운트
bool cmp(const pair<int,int>& a, const pair<int,int>& b) 
{
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int solution(int k, vector<int> tangerine) 
{
    int answer = 0;
    map<int, int> mi;
    
    for(auto& v : tangerine)
        mi[v]++;
    
    vector<pair<int,int>> vec( mi.begin(), mi.end() );
    
    sort(vec.begin(), vec.end(), cmp);
    reverse(vec.begin(), vec.end());
    
    for(auto& v : vec)
    {
        if(k - v.second <= 0)
        {
            answer++;
            break;
        }
        else if(k - v.second >= 0)
        {
            answer++;
            k -= v.second;
        }
    }
    return answer;
}