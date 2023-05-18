#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    for(auto& v : my_string)
    {
        if(v>=48 && v<=58)
            answer.push_back(v - '0');
    }
    sort(answer.begin(), answer.end());
    return answer;
}