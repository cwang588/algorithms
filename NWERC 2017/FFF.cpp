#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
const int N=1e6+5,MX=1e7+1;
int pr[MX],cnt,is_p[MX];
void su()
{
	for(int i=2;i<MX;i++)
	{
		if(!is_p[i])pr[++cnt]=i;
		for(int j=1;j<=cnt&&i*pr[j]<MX;j++)
		{
			is_p[i*pr[j]]=pr[j];
			if(i%pr[j]==0)break;
		}
	}
}
int n,a[N],L[N],R[N],fa[N];
vector<int> S[MX];
int solve(int l,int r)
{
	if(l>r)return 0;
	int t1=l,t2=r,mid=-1;
	while(t1<=t2)
	{
		if(L[t1]<=l&&R[t1]>=r){mid=t1;break;}
		if(L[t2]<=l&&R[t2]>=r){mid=t2;break;}
		++t1,--t2;
	}
	if(mid==-1){printf("impossible\n");exit(0);}
	fa[solve(l,mid-1)]=mid,fa[solve(mid+1,r)]=mid;
	return mid;
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n),su();
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]),L[i]=1,R[i]=n;
		while(is_p[a[i]])
		{
			int p=is_p[a[i]];
			S[p].push_back(i);
			while(a[i]%p==0)a[i]/=p;
		}
		S[a[i]].push_back(i);
	}
	for(int I=2;I<MX;I++)
	{
		if(S[I].empty())continue;
		sort(S[I].begin(),S[I].end());
		for(int i=0;i<S[I].size();i++)
		{
			if(i>0)L[S[I][i]]=max(L[S[I][i]],S[I][i-1]+1);
			if(i+1<S[I].size())R[S[I][i]]=min(R[S[I][i]],S[I][i+1]-1);
		}
	}
	fa[solve(1,n)]=0;
	for(int i=1;i<=n;i++)
		printf("%d ",fa[i]);
	return 0;
}
/*
6
2 7 15 8 9 6
*/
