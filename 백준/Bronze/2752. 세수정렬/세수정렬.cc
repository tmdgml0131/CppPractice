/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

// 첫째줄 시 분 초
// 둘째줄 초단위
// 출력 시 분 초 단위로 언제 끝나는지
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    
    vector<int> vi;
    
    vi.push_back(a);
    vi.push_back(b);
    vi.push_back(c);
    
    sort(vi.begin(), vi.end(), greater<int>());
    
    cout << vi[2] <<" " << vi[1] <<" "<< vi[0];
    return 0;
}
