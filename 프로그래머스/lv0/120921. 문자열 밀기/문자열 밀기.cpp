#include <bits/stdc++.h>

using namespace std;

int solution(string A, string B) 
{
    if(A == B)
        return 0;
    
    for(int i = 0; i<A.size(); i++)
    {
        string temp = "";
        temp = A[A.size()-1] + A;
        temp.pop_back();
        
        if(temp == B)
            return i+1;
        
        A = temp;
    }
    
    return -1;
    
}