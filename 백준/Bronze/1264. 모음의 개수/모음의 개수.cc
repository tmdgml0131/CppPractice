/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    while(true)
    {
        string t {};
        int answer = 0;
        
        getline(cin, t);
        
        if(t == "#")
            return 0;
        for(auto&v : t)
        {
            if(v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u')
                answer++;
            if(v == 'A' || v == 'E' || v == 'I' || v == 'O' || v == 'U')
                answer++;
        }
        
        cout << answer << endl;
    }

    return 0;
}
