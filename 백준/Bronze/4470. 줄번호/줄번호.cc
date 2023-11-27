#include <bits/stdc++.h>
using namespace std;

//1. Lionel Cosgrove
//2. Alice
//3. Columbus and Tallahassee
//4. Shaun and Ed
//5. Fido

int main()
{
    int count = 0;
    cin >> count;
    cin.ignore();
    
    for(int i =1; i<=count; i++)
    {
        string tmp{};
        getline(cin, tmp);
        cout << i << ". " << tmp << "\n";
    }
    
    
    return 0;
}