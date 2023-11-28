/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d,e,f;
    int byetime = 0;
    int hitime = 0;
    int worktime = 0;
    int hour, minute, second;
    
    for(int i =0; i<3; i++)
    {
        cin >> a >> b >> c >> d >> e >> f;
        byetime = d*3600 + e*60 + f;
        hitime = a*3600 + b*60 + c;
        worktime = byetime - hitime;
        hour = worktime/3600;
        worktime %=3600;
        minute = worktime/60;
        worktime %= 60;
        second = worktime;
        
        cout << hour << " " << minute << " " << second << '\n';
    }

    return 0;
}
