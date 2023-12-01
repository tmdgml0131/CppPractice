#include <bits/stdc++.h>
using namespace std;

int main()
{
    int answer = 0;
    int count;
    int a;
    int t = 5;
    cin >> count;
    
    while(t--)
    {
        cin >> a;
        if(count == a)
            answer++;
    }
    cout << answer;
    
    return 0;
}