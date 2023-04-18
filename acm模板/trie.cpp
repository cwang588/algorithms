#include<bits/stdc++.h>
using namespace std;
int a[1000005],s[1000005];
struct Trie
{
	int num;
	int next[2];
}trie[20000005];
int cnt;
char tmp[50];
void insert()
{
	int cur=0;
	for(int i=0;tmp[i]!=' ';++i)
	{
		int pos=trie[cur].next[tmp[i]-'0'];
		if(!pos)
			pos=trie[cur].next[tmp[i]-'0']=++cnt;
		cur=pos;
	}
	++trie[cur].num;
}
int mi(int x)
{
	int re=1;
	for(int i=1;i<=x;++i)
		re*=2;
	return re;
}
int ans;
void dfs(int now,int pos,int nowans)
{
	if(trie[pos].num)
		ans=max(ans,nowans);
	if(tmp[now]=='0')
	{
		if(trie[pos].next[1])
			dfs(now+1,trie[pos].next[1],nowans+mi(30-now));
		else if(trie[pos].next[0])
			dfs(now+1,trie[pos].next[0],nowans);
	}
	else
	{
		if(trie[pos].next[0])
			dfs(now+1,trie[pos].next[0],nowans);
		else if(trie[pos].next[1])
			dfs(now+1,trie[pos].next[1],nowans-mi(30-now));		
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		memset(tmp,' ',sizeof(tmp));
		s[i]=s[i-1]^a[i];
		bitset<35>bit(s[i]);
		for(int j=30;j>=0;--j)
			tmp[30-j]=bit[j]?'1':'0';
		insert();
	}
	for(int i=1;i<=n;++i)
	{
		memset(tmp,' ',sizeof(tmp));
		bitset<35>bit(s[i]);
		for(int j=30;j>=0;--j)
			tmp[30-j]=bit[j]?'1':'0';
		dfs(0,0,s[i]);		
	}
	printf("%d",ans);
	return 0;
}
