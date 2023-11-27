/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c, d,e;
    cin >> a >> b >> c >> d >> e;
    int answer = 0;
    vector<int> vi;
    
    vi.push_back(a);
    vi.push_back(b);
    vi.push_back(c);
    sort(vi.begin(), vi.end());
    
    if(d>=e)
        answer = vi[0] + e - 50;
    else
        answer = vi[0] + d - 50;
        
    cout << answer;
    return 0;
}
