/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    string str1 = "";
    
    cin >> n;
    
    while(n--)
    {
        cin >> str1;
        cout << str1[0] << str1[str1.size()-1] << '\n';
    }
    
    
    return 0;
}
