#include<bits/stdc++.h>
using namespace std;
char s[1000005];
const unsigned long long Mod=19260817;
unsigned long long Hash[2000005];
unsigned long long mod[2000005];
unsigned long long mi[2000005];
inline unsigned long long calc(int l,int r)
{
	return Hash[r]-Hash[l-1]*mi[r-l+1];
}
void init(int n)
{
	mi[0]=1;
	for(int i=1;i<=n;++i)
		mi[i]=mi[i-1]*Mod;
}
struct ss
{
	int l,r;
}tmp[500005],ans[500005];
bool cmp1(ss a,ss b)
{
	if(s[a.l]!=s[b.l])return s[a.l]>s[b.l];
	int L=1,R=a.r-a.l+1;
	while(L<R-1)
	{
		int m=(L+R)>>1;
		if(calc(a.l,a.l+m-1)==calc(b.l,b.l+m-1))L=m;
		else R=m;
	}
	if(calc(a.l,a.l+R-1)==calc(b.l,b.l+R-1))return s[a.l+R]>s[b.l+R];
	else return s[a.l+L]>s[b.l+L];
}
bool cmp2(ss a,ss b)
{
	if(s[a.l]!=s[b.l])return s[a.l]<s[b.l];
	int L=0,R=a.r-a.l+1;
	while(L<R-1)
	{
		int m=(L+R)>>1;
		if(calc(a.l,a.l+m-1)==calc(b.l,b.l+m-1))L=m;
		else R=m;
	}
	if(calc(a.l,a.l+R-1)==calc(b.l,b.l+R-1))return s[a.l+R]<s[b.l+R];
	else return s[a.l+L]<s[b.l+L];
}
int main()
{
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	init(n);
	for(int i=1;i<=n;++i)
	{
		cin>>s[i];
		s[i+n]=s[i];
	}
	for(int i=1;i<=2*n;++i)Hash[i]=Hash[i-1]*Mod+s[i];
	for(int i=1;i<=k;++i)
	{
		for(int j=1;j<=n/k;++j)
		{
			tmp[j].l=i+k*(j-1);
			tmp[j].r=i+k*j-1;
		}
		sort(tmp+1,tmp+1+n/k,cmp1);
		ans[i]=tmp[1];
	}
	sort(ans+1,ans+1+k,cmp2);
	for(int i=ans[1].l;i<=ans[1].r;++i)cout<<s[i];
	cout<<endl;
	return 0;
} 
