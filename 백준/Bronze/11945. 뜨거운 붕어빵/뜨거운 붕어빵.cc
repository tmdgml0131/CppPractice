#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cin.ignore();
    while(a--)
    {
        string tmp;
        getline(cin, tmp);
        reverse(tmp.begin(), tmp.end());
        if(a)
            cout << tmp << '\n';
        else
            cout << tmp;
    }
    
    return 0;
}