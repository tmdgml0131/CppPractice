#include<bits/stdc++.h>
using namespace std;

int main()
{
    while(true)
    {
        string a;
        getline(cin, a);
        if(a == "END")
            break;
        reverse(a.begin(), a.end());
        cout << a << '\n';
    }
    
    
    return 0;
}