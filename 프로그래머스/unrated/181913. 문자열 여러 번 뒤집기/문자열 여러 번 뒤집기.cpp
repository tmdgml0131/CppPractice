#include <bits/stdc++.h>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) 
{
    string answer = "";
    
    for(auto& v : queries)
    {
        reverse(my_string.begin() + v[0], my_string.begin() + v[1] +1);
    }
    
    return my_string;
}