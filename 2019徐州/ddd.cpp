#include<bits/stdc++.h>
using namespace std;
string Strin,t;
int cnt[600005];
string s;
void Manacher(int len) {
    int l = 0;
    Strin[l++] = '$';
    Strin[l++] = '#';
    for (int i = 0; i < len; i++) {
        Strin[l++] = s[i];
        Strin[l++] = '#';
    }
    Strin[l] = '\0'; 
    int MaxR = 0;
    int flag = 0;
    for (int i = 0; i < l; i++) {
        cnt[i] = MaxR > i ? min(cnt[2 * flag - i], MaxR - i) : 1;
        while (Strin[i + cnt[i]] == Strin[i - cnt[i]])
            cnt[i]++;
        if (i + cnt[i] > MaxR) {
            MaxR = i + cnt[i];
            flag = i;
        }
    }
}
int sum[1200005][30];
void build(int l,int r,int rt)
{
	if(l==r)
	{
		int now=(int)((char)t[l-1]-'a')+1  ;
		sum[rt][now]=l;
		return;
	}
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	for(int i=0;i<26;++i)
		sum[rt][i]=min(sum[rt<<1][i],sum[rt<<1|1][i]);
}
int query(int l,int r,int rt,int nowl,int nowr,int k)
{
	if(l>=nowl&&r<=nowr)return sum[rt][k];
	int m=(l+r)>>1;
	int re=999999999;
	if(m>=nowl)re=min(re,query(l,m,rt<<1,nowl,nowr,k));
	if(m<nowr)re=min(re,query(m+1,r,rt<<1|1,nowl,nowr,k));
	return re;
}
int main()
{
	memset(sum,0x3f,sizeof(sum));
	cin>>t;
	s=t;
	int n=t.size();
	build(1,n,1);
	Manacher(n);
	long long ans=0;
	for(int i=1;i<=2*n;++i)
	{
		if(i%2==0)
		{
			int len=cnt[i]/2;
			if(len>0)
			{
				for(int j=1;j<=26;++j)
				{
					int pos=query(1,n,1,i/2,i/2+len-1,j);
					if(pos<=n)
					ans+=(long long)(i/2+len-pos);
					else;
				}
			}
			else;
		}
		else
		{
			int len=(cnt[i]-1)/2;
			if(len>0)
			{
				for(int j=1;j<=26;++j)
				{
					int pos=query(1,n,1,(i+1)/2,(i+1)/2+len-1,j);
					if(pos<=n)
					ans+=(long long)((i+1)/2+len-pos);
					else;
				}
			}
			else;
		}
	}
	cout<<ans<<endl;
	return 0;
}

