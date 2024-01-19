#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    int answer = 0;
    if(a==b)
        answer++;
    if(a==c)
        answer++;
    if(a==d)
        answer++;
    if(a==e)
        answer++;
    if(a==f)
        answer++;
    
    cout << answer;
    
    return 0;
}