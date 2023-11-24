/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 0;
    int answer = 0;
    cin >> t;
    
    for(int i = 1; i<= t; i++)
        answer += i;
    
    cout << answer;
    return 0;
}
