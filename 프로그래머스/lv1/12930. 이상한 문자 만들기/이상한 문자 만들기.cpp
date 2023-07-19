#include <bits/stdc++.h>

using namespace std;

string solution(string s) 
{
    string answer = "";
    bool isEven = true;
    
    for(auto& v : s)
    {
        if(isEven && v != ' ')
        {
            answer += (toupper(v));
            isEven = !isEven;
        }
        else if(!isEven && v!= ' ')
        {
            answer += (tolower(v));
            isEven = !isEven;
        }
        
        if(v == ' ')
        {
            answer += ' ';
            isEven = true;
        }
            
    }
    return answer;
}