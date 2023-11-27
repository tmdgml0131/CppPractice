/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d;
    int answer = 0;
    cin >> a >> b >> c >>d;
    answer += a;
    answer += b;
    answer += c;
    answer += d;
    
    int minute = answer/60;
    int second = answer%60;
    
    cout << minute << '\n' << second;
    
    return 0;
}
