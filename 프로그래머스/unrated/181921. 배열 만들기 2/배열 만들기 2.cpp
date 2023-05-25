#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int l, int r) 
{
    vector<int> answer;
    for(int i =l; i<=r; i++)
    {
        string temp = to_string(i);
        if(temp.find('1') == string::npos && temp.find('2') == string::npos && temp.find('3') == string::npos && temp.find('4') == string::npos && temp.find('6') == string::npos && temp.find('7') == string::npos && temp.find('8') == string::npos && temp.find('9') == string::npos)
            answer.push_back(i);
            
    }
    if(answer.empty())
        answer.push_back(-1);
    
    return answer;
}