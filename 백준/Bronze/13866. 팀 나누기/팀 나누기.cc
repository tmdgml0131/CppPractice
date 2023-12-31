#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d;
    
    cin >> a >> b >> c >> d;
    
    vector<int> vi;
    
    vi.push_back(a);
    vi.push_back(b);
    vi.push_back(c);
    vi.push_back(d);
    
    sort(vi.begin(), vi.end());
    
    int tt, ttt;
    
    tt = vi[0] + vi[3];
    ttt = vi[1] + vi[2];
    
    cout << abs(tt - ttt);
    
    return 0;
}