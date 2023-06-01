#include <bits/stdc++.h>

using namespace std;

vector<int> solution(long long n) 
{
    vector<int> answer;
    string tmp = to_string(n);
    for(int i = tmp.size()-1; i>=0; i--)
    {
        int p = tmp[i] - '0';
        answer.push_back(p);
    }
    return answer;
}