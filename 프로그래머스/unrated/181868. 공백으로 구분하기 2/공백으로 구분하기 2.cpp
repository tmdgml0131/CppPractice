#include <bits/stdc++.h>

using namespace std;

vector<string> solution(string my_string) 
{
    vector<string> answer;
    string str;
    stringstream ss;
    ss.str(my_string);
    while(ss >> str)
    {
        answer.push_back(str);
    }
        

    return answer;
}