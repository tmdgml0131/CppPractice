#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d;
    int t, tt;
    cin >> a >> b >> c >> d;
    t = b+c;
    tt = a+d;
    
    t >= tt ? cout << tt : cout << t; 
    return 0;
}