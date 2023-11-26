/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a = 0;
    cin >> a;
    
    //엔터
    for(int i = 0; i<a; i++)
    {
        //별 출력
        for(int k = a-i; k>0; k--)
        {
            cout<<"*";
        }
        
        cout << endl;
    }

    return 0;
}
