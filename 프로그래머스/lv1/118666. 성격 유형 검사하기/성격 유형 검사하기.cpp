#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> survey, vector<int> choices) 
{
    string answer = "";
    map<char, int> mp;
    
    for(int i = 0; i<survey.size(); i++)
    {
        if(choices[i] < 4)
        {
            if(choices[i] == 1)
                mp[survey[i][0]] += 3;
            else if(choices[i] == 2)
                mp[survey[i][0]] += 2;
            else if(choices[i] == 3)
                mp[survey[i][0]] += 1;
        }
        else if(choices[i] > 4)
        {
            if(choices[i] == 5)
                mp[survey[i][1]] += 1;
            else if(choices[i] == 6)
                mp[survey[i][1]] += 2;
            else if(choices[i] == 7)
                mp[survey[i][1]] += 3;
        }
    }
    
    if(mp['R'] >= mp['T'])
        answer += 'R';
    else
        answer += 'T';
    
    if(mp['C'] >= mp['F'])
        answer += 'C';
    else
        answer += 'F';
    
    if(mp['J'] >= mp['M'])
        answer += 'J';
    else
        answer += 'M';
    
    if(mp['A'] >= mp['N'])
        answer += 'A';
    else
        answer += 'N';
    
    return answer;
}