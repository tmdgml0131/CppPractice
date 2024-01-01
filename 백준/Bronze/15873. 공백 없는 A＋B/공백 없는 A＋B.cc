#include <bits/stdc++.h>
using namespace std;

int main()
{
    string tmp {};
    string one {};
    string two {};
    
    cin >> tmp;
    
    if(tmp.size() == 4)
    {
        cout << 20;
        return 0;
    }
    
    if(tmp.size() == 3 && tmp[2] == '0')
    {
        one += tmp[0];
        two += tmp[1];
        two += tmp[2];
    }
    else if(tmp.size() == 3)
    {
        one += tmp[0];
        one += tmp[1];
        two += tmp[2];
    }
    else
    {
        one += tmp[0];
        two += tmp[1];
    }
    
    cout << stoi(one) + stoi(two);
    
    
    return 0;
}