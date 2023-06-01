#include <bits/stdc++.h>
using namespace std;
int solution(int n)
{
    int answer = 0;
    string tmp = to_string(n);
    
    for(auto& v : tmp)
        answer += v -'0';
    
    return answer;
}