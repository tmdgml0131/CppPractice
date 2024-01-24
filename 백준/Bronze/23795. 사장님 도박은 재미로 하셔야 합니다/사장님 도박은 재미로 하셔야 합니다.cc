#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 0;
    int answer = 0;
    while(true)
    {
        cin >> a;
        if(a == -1 ) break;
        
        answer += a;
    }
    cout << answer;
    
    return 0;
}