#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    bool answer = false;
    int p = 0;
    int y = 0;
    for(auto&v : s)
    {
        if(v == 'p' || v == 'P')
            p++;
        else if(v == 'y' || v == 'Y')
            y++;
    }
    if(p == y)
        answer = true;
    return answer;
}