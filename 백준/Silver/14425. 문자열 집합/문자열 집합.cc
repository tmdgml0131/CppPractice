#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    int c = 0;
    cin >> n >> m;
    map<string, bool> ms;
    string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		ms.insert(pair<string, bool>(str, true));
	}

	for (int i = 0; i < m; i++)
	{
		cin >> str;
		if (ms[str]==true)
			c++;
	}
	cout << c;
    
    
    return 0;
}

