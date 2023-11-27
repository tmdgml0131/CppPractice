#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    string tmp{};
    cin >> a;
    
    while(a--)
    {
        cin >> tmp;
        
        for(auto& v : tmp)
            v = tolower(v);
        
        cout << tmp << "\n";
    }
    
    return 0;
}