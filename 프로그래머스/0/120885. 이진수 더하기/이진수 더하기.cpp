#include <bits/stdc++.h>

using namespace std;

string solution(string bin1, string bin2) 
{
    int a = 0;
    int b = 0;
    for(auto& v: bin1)
        a = a << 1 | v - 48;
    for(auto& v: bin2)
        b = b << 1 | v - 48;
    
    string str = "";
    for(int n = a+b; n; n>>=1)
        str = char(n%2 + 48) + str;
    
    return str.empty() ? "0" : str;
}