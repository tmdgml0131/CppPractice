#include<bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    bool toLow = true;
    for(auto& v : strArr)
    {
        if(toLow)
            transform(v.begin(),v.end(), v.begin(), ::tolower);
        else
            transform(v.begin(),v.end(), v.begin(), ::toupper);
        
        toLow = !toLow;
        answer.push_back(v);
    }
      
    
    
    return answer;
}