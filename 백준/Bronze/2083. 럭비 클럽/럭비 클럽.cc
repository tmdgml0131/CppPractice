#include <bits/stdc++.h>

using namespace std;

int main()
{
    string name = "";
    int age = 0;
    int weight = 0;
    
    while(1)
    {
        cin >> name >> age >> weight;
        
        if(name == "#")
            return 0;
        
        cout << name;
        
        if(age > 17 || weight >= 80)
            cout << " Senior" << endl;
        else
            cout << " Junior" << endl;
    }
    
    return 0;
}