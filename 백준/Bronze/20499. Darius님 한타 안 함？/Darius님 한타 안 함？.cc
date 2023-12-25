// K+A < D or D = 0 -> gosu
// else, hasu

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string tmp = {};
    cin >> tmp;
    vector<int> vi;
    
    string tt;
    for(auto t: tmp)
    {
        if(isdigit(t))
        {
            tt += t;
        }
        else
        {
            vi.push_back(stoi(tt));
            tt.clear();
        }
    }
    vi.push_back(stoi(tt));
    
    if(vi[0] + vi[2] < vi[1] || vi[1] == 0)
    {
        cout << "hasu";
    }
    else
    {
        cout << "gosu";
    }
    return 0;
}
