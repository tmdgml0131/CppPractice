#include <bits/stdc++.h>

using namespace std;

string solution(int a, int b) 
{
    string answer = "";
    vector<string> vs = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    vector<int> vi = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int max = 0;
    
    for(int i = 0; i<a-1; i++)
    {
        max += vi[i]; 
    }
    max += b;
    answer = vs[max%7];
    return answer;
}