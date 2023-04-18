#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d,e,f;
	scanf("%d:%d:%d",&d,&e,&f);
	scanf("%d:%d:%d",&a,&b,&c);
	int ans=0;
	while(a!=d||b!=e||c!=f)
	{
		++ans;
		++c;
		if(c==60)
		{
			c=0;
			++b;
			if(b==60)
			{
				++a;
				b=0;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
