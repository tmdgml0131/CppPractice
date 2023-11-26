/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

//같은 눈이 3개가 나오면 10,000원+(같은 눈)×1,000원의 상금을 받게 된다.
//같은 눈이 2개만 나오는 경우에는 1,000원+(같은 눈)×100원의 상금을 받게 된다.
//모두 다른 눈이 나오는 경우에는 (그 중 가장 큰 눈)×100원의 상금을 받게 된다.
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int answer{};
    vector<int> vi;
    
    vi.push_back(a);
    vi.push_back(b);
    vi.push_back(c);
    
    sort(vi.begin(), vi.end());
    
    if(a == b && a == c)
        answer = 10000 + (a*1000);
    else if(a == b || a == c)
        answer = 1000 + (a*100);
    else if(b == c)
        answer = 1000 + b*100;
    else
        answer = vi[2]*100;
    
    cout << answer;
    return 0;
}
