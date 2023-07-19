#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) 
{
    vector<int> answer;
    vector<int> one = {1,2,3,4,5}; // 5
    vector<int> two = {2,1,2,3,2,4,2,5}; // 8
    vector<int> three = {3,3,1,1,2,2,4,4,5,5}; // 10
    
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    
    for(int i = 0; i<answers.size(); i++)
    {
        if(answers[i] == one[i%5])
            count1++;
        if(answers[i] == two[i%8])
            count2++;
        if(answers[i] == three[i%10])
            count3++;
    }
    while(1)
    {
        if(count1 > count2 && count1 > count3)
        {
            answer.push_back(1);
            break;
        }
            
        if(count2 > count1 && count2 > count3)
        {
            answer.push_back(2);
            break;
        }
            
        if(count3 > count1 && count3 > count2)
        {
            answer.push_back(3);
            break;
        }
        
        if(count1 == count2 && count2 == count3)
        {
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
            break;
        }
        
        if(count1 == count2 && count1 > count3)
        {
            answer.push_back(1);
            answer.push_back(2);
            break;
        }
        
        if(count1 == count3 && count1 > count2)
        {
            answer.push_back(1);
            answer.push_back(3);
            break;
        }
        
        if(count2 == count3 && count2 > count1)
        {
            answer.push_back(2);
            answer.push_back(3);
            break;
        }
    }
    
    
    return answer;
}