#include<bits/stdc++.h>
using namespace std;
int a[200005],cnt,ans;
vector<int>v;
int getid(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
char tmp[35];
struct Trie
{
	int num,tot;
	int next[2];
}trie[6000005];
void insert(int now)
{
	memset(tmp,0,sizeof(tmp));
	bitset<35>bit(now);
	for(int j=30;j>=0;--j)tmp[30-j]=bit[j]?'1':'0';
	int cur=0;
	for(int i=0;tmp[i];++i)
	{
		int pos=trie[cur].next[tmp[i]-'0'];
		if(!pos)
			pos=trie[cur].next[tmp[i]-'0']=++cnt;
		cur=pos;
		++trie[cur].tot;
	}
	++trie[cur].num;
}
void del(int now){
	memset(tmp,0,sizeof(tmp));
	bitset<35>bit(now);
	for(int j=30;j>=0;--j)tmp[30-j]=bit[j]?'1':'0';
	int cur=0;
	for(int i=0;tmp[i];++i)
	{
		int pos=trie[cur].next[tmp[i]-'0'];
		cur=pos;
		--trie[cur].tot;
	}
	++trie[cur].num;
}
int mi[35];
void dfs(int now,int pos,int nowans){
	if(trie[pos].num)ans=min(ans,nowans);
	if(tmp[now]=='0'){
		if(trie[pos].next[0]&&trie[trie[pos].next[0]].tot)dfs(now+1,trie[pos].next[0],nowans);
		else if(trie[pos].next[1]&&trie[trie[pos].next[1]].tot)dfs(now+1,trie[pos].next[1],nowans+mi[30-now]);
	}
	else{
		if(trie[pos].next[1]&&trie[trie[pos].next[1]].tot)dfs(now+1,trie[pos].next[1],nowans-mi[30-now]);
		else if(trie[pos].next[0]&&trie[trie[pos].next[0]].tot)dfs(now+1,trie[pos].next[0],nowans);	
	}
}
void init(){
	mi[0]=1;
	for(int i=1;i<=30;++i)mi[i]=mi[i-1]*2;
}
int dp[6000005];
void dfs(int pos){
	if((!trie[pos].next[0])&&(!trie[pos].next[1]))return;
	if(trie[pos].next[0])dfs(trie[pos].next[0]);
	if(trie[pos].next[1])dfs(trie[pos].next[1]);
	if(trie[pos].next[0]&&trie[pos].next[1])dp[pos]=min(dp[trie[pos].next[0]]+trie[trie[pos].next[1]].tot-1,dp[trie[pos].next[1]]+trie[trie[pos].next[0]].tot-1);
	else if(trie[pos].next[0])dp[pos]=dp[trie[pos].next[0]];
	else if(trie[pos].next[1])dp[pos]=dp[trie[pos].next[1]];
	else;
}
int main(){
	init();
	int n;	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),v.push_back(a[i]),insert(a[i]);
	dfs(0);
	printf("%d\n",dp[0]);
	return 0;
}
