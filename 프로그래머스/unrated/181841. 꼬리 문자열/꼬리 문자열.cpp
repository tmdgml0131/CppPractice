#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> str_list, string ex) {
    string answer = "";
    for(auto& v : str_list)
    {
        if(v.find(ex) == string::npos)
            answer+=v;
    }
    return answer;
}