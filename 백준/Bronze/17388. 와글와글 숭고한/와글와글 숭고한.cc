// 100 이상이면 OK
// 이하면 Soongsil, Korea, Hanyang

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    
    if(a+b+c >= 100)
    {
        cout << "OK";
        return 0;
    }
    else
    {
        if(a < b && a < c)
        {
            cout << "Soongsil";
            return 0;
        }
        else if(b < c)
        {
            cout << "Korea";
            return 0;
        }
        else
        {
            cout << "Hanyang";
            return 0;
        }
    }
    
    return 0;
}