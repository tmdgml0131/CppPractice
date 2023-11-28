#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);
    
    int count, a,b,c;
    cin >> count;
    
    while(count--)
    {
        cin >> a >> b;
        c = a+b;
        cout << c << '\n';
    }
    
    return 0;
}