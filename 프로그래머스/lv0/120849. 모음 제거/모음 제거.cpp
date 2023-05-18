#include <bits/stdc++.h>

using namespace std;

string solution(string my_string) 
{
    string answer = "";
    for(const auto v : my_string)
    {
        if( v != 'a' && v != 'e' && v != 'i' && v != 'o' && v != 'u')
            answer += v;
    }

    return answer;
}