#include <bits/stdc++.h>

using namespace std;

bool solution(int x) 
{
    bool answer = true;
    string tmp = to_string(x);
    int t = 0;
    for(auto& v : tmp)
        t += v - '0';
    
    return x%t == 0;
}