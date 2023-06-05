#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
    string answer = "Yes";
    for(int i = 0; i<goal.size(); i++)
    {
        string tmp = goal[i];
        if(cards1[0] == tmp)
        {
            cards1.erase(cards1.begin());
            continue;
        }
            
        if(cards2[0] == tmp)
        {
            cards2.erase(cards2.begin());
            continue;
        }
        
        return "No";
    }
    return answer;
}