#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> babbling) 
{
    int answer = 0;
    vector<string> vs = {"aya", "ye", "woo", "ma"};
    
    for(int i=0; i<babbling.size(); i++)
    {
        bool check=false;
        bool aya = false;
        bool ye = false;
        bool woo = false;
        bool ma = false;
        
        for(int j=0; j<babbling[i].size(); j++)
        {
            if(babbling[i].substr(j, 3)=="aya" && !aya)
            {
                j+=2;
                aya = true;
                ye = woo = ma = false;
            }
            else if(babbling[i].substr(j, 2)=="ye" && !ye) 
            {
                j+=1;
                ye = true;
                aya = woo = ma = false;
            }
            else if(babbling[i].substr(j, 3)=="woo" && !woo) 
            {
                j+=2;
                woo = true;
                aya = ye = ma = false;
            }
            else if(babbling[i].substr(j, 2)=="ma" && !ma) 
            {
                j+=1;
                ma = true;
                aya = ye = woo = false;
            }
            else
            {
                check=true;
                break;
            }
        }
        
        if(!check) 
            answer++;
    }
    
    return answer;
}