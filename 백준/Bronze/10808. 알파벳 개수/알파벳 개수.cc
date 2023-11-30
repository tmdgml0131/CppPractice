/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string t = {};
    cin >> t;
    
    map<int, int> mi;
    
    for(int i = 97; i<=122; i++)
        mi[i] = 0;
        
    for(auto v : t)
        mi[v]++;
        
    for(auto v : mi)
        cout << v.second << " ";

    return 0;
}
