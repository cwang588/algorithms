#include<bits/stdc++.h>
using namespace std;
char String[300005],t[300005];
const int maxn=400010;
char str[maxn];//原字符串
char tmp[maxn<<1];//转换后的字符串
int Len[maxn<<1];
int INIT(char *st)
{
    int i,len=strlen(st);
    tmp[0]='@';//字符串开头增加一个特殊字符，防止越界
    for(i=1;i<=2*len;i+=2)
    {
        tmp[i]='#';
        tmp[i+1]=st[i/2];
    }
    tmp[2*len+1]='#';
    tmp[2*len+2]='$';//字符串结尾加一个字符，防止越界
    tmp[2*len+3]=0;
    return 2*len+1;//返回转换字符串的长度
}
void MANACHER(char *st,int len)
{
     int mx=0,ans=0,po=0;//mx即为当前计算回文串最右边字符的最大值
     for(int i=1;i<=len;i++)
     {
         if(mx>i)
         Len[i]=min(mx-i,Len[2*po-i]);//在Len[j]和mx-i中取个小
         else
         Len[i]=1;//如果i>=mx，要从头开始匹配
         while(st[i-Len[i]]==st[i+Len[i]])
         Len[i]++;
         if(Len[i]+i>mx)//若新计算的回文串右端点位置大于mx，要更新po和mx的值
         {
             mx=Len[i]+i;
             po=i;
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
	int n=strlen(t);
	build(1,n,1);
	INIT(t);
	MANACHER(tmp,n*2);
	long long ans=0;
	for(int i=1;i<=2*n;++i)
	{
		if(i%2==0)
		{
			int len=Len[i]/2;
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
			int len=(Len[i]-1)/2;
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


