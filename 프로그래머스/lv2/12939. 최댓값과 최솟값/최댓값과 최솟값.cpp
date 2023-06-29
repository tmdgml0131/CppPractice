#include <bits/stdc++.h>

using namespace std;

string solution(string s) 
{
    string answer = "";
    string temp = "";
    vector<int> vi;
    for(auto& v : s)
    {
        if(v != ' ')
            temp += v;
        else
        {
            vi.push_back(stoi(temp));
            temp.clear();
        }
    }
    vi.push_back(stoi(temp));
    sort(vi.begin(), vi.end());
    string min = to_string(vi[0]);
    string max = to_string(vi[vi.size()-1]);
    answer += min;
    answer += ' ';
    answer += max;
    return answer;
}