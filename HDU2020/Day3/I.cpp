#include<bits/stdc++.h>
using namespace std;
char s[100005];
int pos1[100005],pos2[100005],sum[100005];
bool usd[100005];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false);
	int t; 
	cin>>t;
	while(t--)
	{
		memset(usd,0,sizeof(usd));
	//	memset(pos1,0,sizeof(pos1));
	//	memset(pos2,0,sizeof(pos2));
		sum[0]=0;
		cin>>(s+1);
		int n=strlen(s+1);
		int tot1=0,tot2=0,tot3=0;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='(')++tot1;
			else if(s[i]==')')++tot2;
			else ++tot3;
		} 
		if(tot3+tot1<tot2)
		{
			cout<<"No solution!\n";
			continue;
		} 
		int now=0,num1=0,num2=0;
		int tmp=tot3-tot1+tot2;
		if(tmp%2)tmp=tmp/2+1;
		else tmp/=2;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='*')
			{
				++now;
				if(now<=tmp)s[i]='(',pos1[++num1]=i;
				else s[i]=')',pos2[++num2]=i;
			}
		}
		bool ky=true;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='(')sum[i]=sum[i-1]+1;
			else sum[i]=sum[i-1]-1;
			if(sum[i]<0)ky=false;
		}
		if(!ky)
		{
			cout<<"No solution!\n";
			continue;
		}
		if(tot1+num1>tot2+num2&&tot3>0)
		{
			sum[pos1[num1]]=19260817;
			for(int i=pos1[num1]+1;i<=n;++i)
			{
				--sum[i];
				if(sum[i]<0)
				ky=false;
			}
			usd[pos1[num1]]=true;
			--num1;
		}	
		if(!ky||(sum[n]>0&&sum[n]<100000))
		{
			cout<<"No solution!\n";
			continue;
		}
		int nowl=pos1[num1],nowr=pos2[1],minnow=2147483647;
		for(int i=nowl+1;i<nowr;++i)minnow=min(minnow,sum[i]);
		for(int i=num1;i>=1;--i)
		{
			if(num1-i+1>num2)break;
			if(minnow>0)
			{
				usd[pos1[i]]=usd[pos2[num1-i+1]]=true;
				nowl=pos1[i]-1,nowr=pos2[num1-i+1]+1;
				minnow-=1;
			}
			else break;
			if(i==1)break;
			while(nowl>pos1[i-1])
			{
				minnow=min(minnow,sum[nowl]);
				--nowl;
			}
			while(nowr<pos2[num1-i+2])
			{
				minnow=min(minnow,sum[nowr]);
				++nowr;
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(!usd[i])
				cout<<s[i];
		}
		cout<<endl;
	} 
	return 0;
}
