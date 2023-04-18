#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,tl[N],mm,ans,ans_cn;
struct st
{
	int x,y;
}a[N];
int h[N],l[N],cnh,cnl;
bool is_h[N],is_l[N],hk[N],lk[N];
int main()
{
	scanf("%d",&T);
	for(int cn=1;cn<=T;cn++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		for(int i=1;i<=n;i++)h[i]=0,l[i]=0;
		printf("Case %d: ",cn);
		for(int i=1;i<=n;i++)tl[i]=a[i].x;
		sort(tl+1,tl+1+n);
		mm=unique(tl+1,tl+1+n)-tl-1;
		for(int i=1;i<=n;i++)
			a[i].x=lower_bound(tl+1,tl+1+mm,a[i].x)-tl;
		for(int i=1;i<=n;i++)tl[i]=a[i].y;
		sort(tl+1,tl+1+n);
		mm=unique(tl+1,tl+1+n)-tl-1;
		for(int i=1;i<=n;i++)
			a[i].y=lower_bound(tl+1,tl+1+mm,a[i].y)-tl;
		for(int i=1;i<=n;i++)
			++h[a[i].x],++l[a[i].y];
		for(int i=1;i<=n;i++)hk[i]=lk[i]=0;
		int tpp=0;
		for(int i=1;i<=n;i++)
			if(!hk[a[i].x])hk[a[i].x]=1,++tpp;
		if(tpp==1){printf("%d 1\n",n);continue;}
		tpp=0;
		for(int i=1;i<=n;i++)
			if(!lk[a[i].y])lk[a[i].y]=1,++tpp;
		if(tpp==1){printf("%d 1\n",n);continue;}
		cnh=cnl=0;
		int mx=0;
		for(int i=1;i<=n;i++)
			mx=max(mx,h[i]);
		for(int i=1;i<=n;i++)
			if(h[i]==mx)is_h[i]=1,++cnh;
			else is_h[i]=0;
		ans=mx,mx=0;
		for(int i=1;i<=n;i++)
			mx=max(mx,l[i]);
		for(int i=1;i<=n;i++)
			if(l[i]==mx)is_l[i]=1,++cnl;
			else is_l[i]=0;
		ans+=mx; int tmp=0;
		for(int i=1;i<=n;i++)
			if(is_h[a[i].x]&&is_l[a[i].y])++tmp;
		if(tmp<cnl*cnh)
		{
			if(ans!=2)printf("%d %d\n",ans,cnl*cnh-tmp);
			else printf("%d %d\n",ans,(cnl*cnh-tmp)/2);
			continue;
		}
		ans_cn=cnl*cnh,mx=cnh=tmp=0;
		for(int i=1;i<=n;i++)
			mx=max(mx,h[i]);
		for(int i=1;i<=n;i++)
			if(h[i]==mx-1)is_h[i]=1,++cnh;
			else is_h[i]=0;
		for(int i=1;i<=n;i++)
			if(is_h[a[i].x]&&is_l[a[i].y])++tmp;
		if(tmp<cnl*cnh)ans_cn+=cnl*cnh-tmp;
		
		cnh=0;
		for(int i=1;i<=n;i++)
			if(h[i]==mx)is_h[i]=1,++cnh;
			else is_h[i]=0;
		mx=tmp=cnl=0;
		for(int i=1;i<=n;i++)
			mx=max(mx,l[i]);
		for(int i=1;i<=n;i++)
			if(l[i]==mx-1)is_l[i]=1,++cnl;
			else is_l[i]=0;
		for(int i=1;i<=n;i++)
			if(is_h[a[i].x]&&is_l[a[i].y])++tmp;
		if(tmp<cnl*cnh)ans_cn+=cnl*cnh-tmp;
		printf("%d %d\n",ans-1,ans_cn);
	}
	return 0;
}
/*
1
5
1 2
1 3
2 3
4 5
6 7
*/
