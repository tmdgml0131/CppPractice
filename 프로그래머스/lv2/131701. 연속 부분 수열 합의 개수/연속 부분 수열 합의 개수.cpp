#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> elements) 
{
    int answer = 0;
    set<int> si;

    int len = 1;
    
    while(len<=elements.size())
    {
        for(int i=0;i<elements.size();i++)
        {
            int sum = 0;
            for(int j=i;j<i+len;j++)
            {
                if(j>=elements.size()) 
                    sum += elements[j-elements.size()];
                else 
                    sum += elements[j];
            }
            
            si.insert(sum);
        }
        len++;
    }
    
    answer = si.size();
    
    return answer;
}