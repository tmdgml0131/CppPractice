#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string target = "";
    stringstream ss;
    ss.str(my_string);
    
    while(ss >> target)
    {
        answer.push_back(target);
    }
    
    return answer;
}