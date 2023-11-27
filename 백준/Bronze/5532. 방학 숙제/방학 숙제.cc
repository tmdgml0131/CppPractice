#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    
    int t1, t2;
    
    t1 = c / e;
    if(c%e != 0)
        t1++;
    
    t2 = b / d;
    if(b%d != 0)
        t2++;
    
    t1 >= t2 ? cout<< a-t1 : cout << a-t2;
    
    return 0;
}