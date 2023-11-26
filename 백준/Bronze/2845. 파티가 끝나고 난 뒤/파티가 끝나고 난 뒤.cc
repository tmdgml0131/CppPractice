/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//5 20
//99 101 1000 0 97

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int num = a*b;
    
    vector<int> vi;
    
    for(int i = 0; i<5; i++)
    {
        int num2 = 0;
        cin >> num2;
        vi.push_back(num2 - num);
    }
    
    for(auto& v : vi)
    {
        cout << v << " ";
    }

    return 0;
}
