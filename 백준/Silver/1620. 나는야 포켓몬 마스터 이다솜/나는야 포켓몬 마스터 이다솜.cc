#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    map<string, int> ms;
    map<int, string> mi;
    cin >> n >> m;
    string tmp;
    for(int i =0; i< n; i++)
    {
        cin >> tmp;
        ms[tmp] = i+1;
        mi[i+1] = tmp;
    }
    
    for(int i =0; i<m; i++)
    {
        cin >> tmp;
        if(!isdigit(tmp[0]))
        {
            cout << ms[tmp] << "\n";
        }
        else
        {
            cout<< mi[stoi(tmp)] << "\n";
        }
    }
    
    
    return 0;
}
