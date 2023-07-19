#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> picture, int k) 
{
    vector<string> answer;
    string temp = "";
    for(auto&v : picture)
    {
        for(auto& v2 : v)
        {
            for(int i = 0; i<k; i++)
                temp += v2;
        }
        
        for(int i = 0; i<k; i++)
            answer.push_back(temp);
        temp.clear();
    }
    return answer;
}