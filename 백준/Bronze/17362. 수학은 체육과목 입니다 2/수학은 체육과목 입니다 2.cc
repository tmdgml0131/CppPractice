#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    if (n <= 5) 
        cout << n;
    else
    {
        if ((n - 5) / 4 % 2 == 0)
            cout << 5 - (n-5) % 4;
        else
            cout << 1 + (n - 5) % 4;
    }
    return 0;
}