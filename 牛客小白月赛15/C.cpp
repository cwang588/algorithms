#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	int now=0;
	for(int i=1;i<=n;++i)
	{
		string t;
		cin>>t;
		if(m[t])
			++now;
		++m[t];
	}
	while(q--)
	{
		int tep;
		scanf("%d",&tep);
		if(tep==1)
		{
			string t;
			cin>>t;
			if(m[t])
				++now;
			++m[t];
		}
		else
		{
			cout<<now<<endl;
			now=0;
		}
	}
	return 0;
}
