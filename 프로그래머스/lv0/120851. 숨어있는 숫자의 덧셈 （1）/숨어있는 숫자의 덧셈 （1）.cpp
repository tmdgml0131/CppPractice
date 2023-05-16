#include<bits/stdc++.h>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    for(auto& v : my_string)
    {
        if(isdigit(v))
        {
            answer += v - '0';
        }
            
    }
    return answer;
}