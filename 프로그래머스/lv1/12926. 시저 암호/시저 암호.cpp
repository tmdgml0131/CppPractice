#include <bits/stdc++.h>

using namespace std;

string solution(string s, int n) 
{
    //65 = A, 97=a
    string answer = "";
    for(auto& v : s)
    {
        if(v == ' ')
        {
            answer += ' ';
            continue;
        }
        if(v+n > 122)
        {
            v += n-26;
        }
        else if(v+n > 90 && v < 97)
        {
            v += n-26;
        }
        else
            v += n;
        
        answer += v;
    }
    return answer;
}