#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> quiz) 
{
    vector<string> answer;
    // v-> 30 - 14 = -3
    for(auto& v : quiz)
    {
        vector<string> temp;
        stringstream ss(v);
        string str = "";
        while(ss >> str)
            temp.push_back(str);
        //temp[0~4] - 숫자, 연산, 숫자, 등호, 결과
        
        int first = stoi(temp[0]);
        string cal = temp[1];
        int last = stoi(temp[2]);
        int result = stoi(temp[4]);
        int compare = 0;
        
        if(cal == "+")
        {
            compare = first + last;
            if(compare == result)
                answer.push_back("O");
            else
                answer.push_back("X");
        }
        else if(cal == "-")
        {
            compare = first - last;
            if(compare == result)
                answer.push_back("O");
            else
                answer.push_back("X");
        }
    }
    
    
    return answer;
}