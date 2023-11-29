#include<bits/stdc++.h>
using namespace std;
/*
260000
4
20000 5
30000 2
10000 6
5000 8
*/
int main()
{
    int total, count;
    cin >> total >> count;
    
    while(count--)
    {
        int a, b;
        cin >> a >> b;
        total -= a*b;
    }
    
    total == 0 ? cout << "Yes" : cout << "No";
    
    return 0;
}