#include<bits/stdc++.h>
using namespace std;
string s;
int pos[100005],cnt;
int calc(int l,int r)
{
	int re=0;
	for(int i=l;i<=r;++i)re=re*2+s[i]-'0';
	return re;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(pos,0,sizeof(pos));
		cnt=0;
		s.clear();
		cin>>s;
		int n=s.size();
		for(int i=0;i<n;++i)if(s[i]=='1')pos[++cnt]=i+1;
		int ans=0;
		for(int i=1;i<=cnt;++i)
			for(int j=1;j<=20&&(pos[i]-1+j-1<n);++j)
			{
				int now=calc(pos[i]-1,pos[i]+j-2);
				if(now-j<=pos[i]-pos[i-1]-1)++ans;
			}
		printf("%d\n",ans);
	}
	return 0;
}
