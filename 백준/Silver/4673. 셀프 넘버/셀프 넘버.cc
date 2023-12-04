#include<bits/stdc++.h>
using namespace std;

int a[10000];

int d(int n) 
{
	int ret = n;
	while (n) 
    {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main()
{
    
    
    
    for (int i = 0; i < 10000; ++i) 
    {
		int ret = d(i);
		if (ret < 10000) a[ret] = 1;
	}

	for (int i = 0; i < 10000; ++i) 
    {
		if (!a[i]) printf("%d\n", i);
	}
    
    return 0;
}