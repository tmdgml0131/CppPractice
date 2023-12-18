#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    int answer = 2;
    cin >> a;
    
    if(a == 1)
    {
        cout << 2;
        return 0;
    }
    else
    {
        a--;
    }
    while(a--)
    {
        answer *= 2;
    }
    
    cout << answer;
    return 0;
}