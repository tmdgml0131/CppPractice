#include <bits/stdc++.h>

using namespace std;

int solution(string s) 
{
    int answer = 0;
    string tmp;
    for(int i = 0; i<s.size();i++)
    {
        if(isdigit(s[i]))
        {
            tmp += s[i];
            continue;
        }
            
        
        if(s[i] == 'z')
        {
            tmp += '0';
            i +=3;
        }
        else if(s[i] == 'o')
        {
            tmp += '1';
            i += 2;
        }
        else if(s[i] == 't')
        {
            if(s[i+2] == 'o')
            {
                tmp += '2';
                i += 2;
            }
            else
            {
                tmp += '3';
                i += 4;
            }
        }
        else if(s[i] == 'f')
        {
            if(s[i+2] == 'u')
            {
                tmp += '4';
                i += 3;
            }
            else
            {
                tmp += '5';
                i += 3;
            }
        }
        else if(s[i] == 's')
        {
            if(s[i+2] == 'x')
            {
                tmp += '6';
                i += 2;
            }
            else
            {
                tmp += '7';
                i += 4;
            }
        }
        else if(s[i] == 'e')
        {
            tmp += '8';
            i += 4;
        }
        else if(s[i] == 'n')
        {
            tmp += '9';
            i += 3;
        }
    }
    
    return stoll(tmp);
}