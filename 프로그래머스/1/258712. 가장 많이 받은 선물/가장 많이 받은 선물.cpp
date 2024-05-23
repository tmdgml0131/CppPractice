#include <bits/stdc++.h>

using namespace std;

map<string, int> msi;
vector<vector<int>> vvi;        
vector<int> vi;             // 선물점수

void SplitGift(string tmp)
{
    istringstream is;
    is.str(tmp);
    vector<string>ans;
    string st;
    while(getline(is,st,' '))
    {
        ans.push_back(st);
    }
    vvi[msi[ans[0]]][msi[ans[1]]]+=1;
    vvi[msi[ans[1]]][msi[ans[0]]]-=1;
    vi[msi[ans[0]]]+=1;
    vi[msi[ans[1]]]-=1;
}

int solution(vector<string> friends, vector<string> gifts) 
{
    int answer = 0;
    vi = vector<int>(friends.size(), 0);    // 초기화
    
    for(int i=0; i<friends.size(); i++)
    {
        msi.insert({friends[i],i});     // 멤버 당 인덱스 할당
    }
    
    vvi=vector<vector<int>>(friends.size(),vector<int>(friends.size(),0)); // 초기화
    
    for(int i=0; i<gifts.size(); i++)
    {
        SplitGift(gifts[i]);        // 표 구현
    }
    
    for (int i=0; i<friends.size(); i++)
    {
        int nowGift=0;
        for (int j=0; j<friends.size(); j++)
        {
            if (vvi[i][j]>0)
            {
                nowGift+=1;
            }
            else if (vvi[i][j]==0)
            {
                if (vi[i]>vi[j])            // 선물 지수 클 시 +1
                {
                    nowGift+=1;
                }
            }
        }
        
        if (nowGift>answer)
        {
            answer=nowGift;     // 갱신
        }
    }
    return answer;
    
}