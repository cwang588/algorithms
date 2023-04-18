#include<bits/stdc++.h>
using namespace std;
int pos[1000005],cha[1000005];
int gcd(int a,int b)
{
	while(b)
	{
		int t1=a,t2=b;
		a=t2;
		b=t1%t2;
	}
	return a;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(pos,0,sizeof(pos));
		memset(cha,0,sizeof(cha));
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=m;++i)
			cin>>pos[i];
		sort(pos+1,pos+1+m);
		for(int i=1;i<=m;++i)
			cha[i]=pos[i]-pos[i-1];
		cha[1]=pos[1]-pos[m]+n;
		sort(cha+1,cha+1+m);
		int now=1;
		for(int i=1;i<=n;++i)
		{
			if(now<=m)
				printf("%d/%d\n",(m-now+1)/gcd(n,(m-now+1)),n/gcd(n,(m-now+1)));
			else
			{
				printf("0\n");
				continue;
			}
			while(i>=cha[now]&&now<=m+1)
				++now;
		}
	}
	return 0;
}
