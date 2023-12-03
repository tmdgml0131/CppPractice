#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d,e,f,g,h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    int to, too;
    to = 0;
    too = 0;
    
    to += a;
    to += b;
    to += c;
    to += d;
    
    too += e;
    too += f;
    too += g;
    too += h;
    
    to >= too ? cout << to : cout << too;
    
    return 0;
}