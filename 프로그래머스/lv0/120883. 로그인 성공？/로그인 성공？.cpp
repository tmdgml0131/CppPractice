#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) 
{
    string answer = "";
    int count = 0;
    
    for(auto&v : db)
    {
        if(id_pw == v)
            return "login";
        
        if(id_pw[0] == v[0])
            count++;
    }
    
    if(count > 0)
        return "wrong pw";
    
    return "fail";
}